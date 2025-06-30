#include "Scene.h"
#include "hitBox.h"
#include "WorldContext.h"
#include "EnemyEntity/EnemyEntity.h"
#include "BulletEntity.h"
#include <iostream>

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



void Scene::update(float dt) 
{  // 1) clear last frame’s spawns
  spawnBuffer.clear();

  // 2) update everyone
  player->Input(dt, window);
  for (CoreEntity* ent : *collidables) {
    if (auto enemy = dynamic_cast<EnemyEntity*>(ent)) {
      if (enemy->targetDetection(player)) {
        enemy->aimAt(player);
        // collect a brand new bullet
        spawnBuffer.push_back(enemy->shoot());
      }
    }
    else if (auto bullet = dynamic_cast<BulletEntity*>(ent)) {
      bullet->travel(dt);
    }
  }

  // 3) now that the iteration is done, safely append spawns
  for (CoreEntity* e : spawnBuffer) {
    collidables->push_back(e);
  }

}

void Scene::render(Shader& shader) {
  glClearColor(0, 0, 0.01f, 1);
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