#include "Scene.h"
#include "hitBox.h"
#include "WorldContext.h"
#include "EnemyEntity/EnemyEntity.h"
#include "BulletEntity.h"
#include <iostream>
#include <algorithm>

Scene::Scene(GLFWwindow* win)
  : window(win),
    lastTime(glfwGetTime())
{
  collidables = WorldContext::Instance()->collidables;
}

void Scene::updateAndRender(Shader& shader) {

  float now = glfwGetTime();
  float dt  = now - lastTime;
  lastTime  = now;
  update(dt);


  render(shader);
}



void Scene::update(float dt) {
    spawnBuffer.clear();

    if (player && player->isAlive()) {
        player->Input(dt, window);
    }

    for (CoreEntity* ent : *collidables) {
        if (auto enemy = dynamic_cast<EnemyEntity*>(ent)) {
            enemy->timeSinceShot += dt;

            if (enemy->targetDetection(player)) {
                enemy->aimAt(player);
                if (enemy->timeSinceShot >= enemy->shootCooldown) {
                    BulletEntity* newBullet = enemy->shoot();
                    newBullet->owner = enemy;
                    spawnBuffer.push_back(newBullet);
                    enemy->timeSinceShot = 0.0f;
                }
            }
        }
        else if (auto bullet = dynamic_cast<BulletEntity*>(ent)) {
            bullet->travel(dt);
        }
    }

    for (CoreEntity* e : spawnBuffer) {
        collidables->push_back(e);
    }

    auto& list = *collidables;
    list.erase(
        std::remove_if(list.begin(), list.end(),
            [&](CoreEntity* ent) {
                if (!ent->isAlive()) {
                    if (ent == player) return false;   // don't delete player
                    delete ent;
                    return true;
                }
                return false;
            }),
        list.end()
    );

    if (player && !player->isAlive()) {
        std::cout << "💀 Player has died. Game Over!\n";
    }
}


void Scene::render(Shader& shader) {
  if (player && !player->isAlive()) {
      glClearColor(1, 0, 0.01f, 1);
  }else {  glClearColor(0, 0, 0.01f, 1);
}
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  shader.Activate();
  player->playerCamera.Matrix(45.0f, 0.1f, 100.0f, shader, "camMatrix");

  for (auto* e : *collidables)
    e->Draw(shader);

  glfwSwapBuffers(window);
}

void Scene::enemyInteraction(EnemyEntity* enemy)
{
  if (enemy->targetDetection(player))
  {
    enemy->aimAt(this->player);
    enemy->shoot();
  }
}