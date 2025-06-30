#include "Scene.h"
#include "hitBox.h"
#include "WorldContext.h"
#include "EnemyEntity/EnemyEntity.h"
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



void Scene::update(float dt) {
  player->Input(dt, window);
  for (auto* e : *collidables)
  {
    CoreEntity* ent;
    if (auto e = dynamic_cast<EnemyEntity*>(ent)) {
      enemyInteraction(e);
    }
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
  enemy->aimAt(this->player);
}