#include "Scene.h"
#include "Hitbox.h"
#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

Scene::Scene() : enemyMesh(Renderable(cubeVertices, cubeVerticesSize, cubeIndices, cubeIndicesSize)){}

void Scene::update(float deltaTime, GLFWwindow* window) {
    if (!player) return;

    if (player->isDead()) {
    }

    const auto& playerOBB = player->playerObj.getOBB();

    // Proposed move + attempt with collision
    glm::vec3 moveVec = player->Input(deltaTime, window);
    if (glm::length(moveVec) > 0.001f)
        attemptMovePlayer(moveVec);

}



void Scene::attemptMovePlayer(glm::vec3 proposedMove) {
    glm::vec3 proposedPos = player->playerObj.position + proposedMove;

    // Simulate updated hitbox
    Hitbox::OBB trial;
    trial.setFromTransform(proposedPos,
                           player->playerObj.orientation,
                           player->playerObj.scale,
                           player->playerObj.localHalfExtents);

    // Check against all other objects
    for (GameObject* obj : gameObjects) {
        if (Hitbox::doOBBsIntersect(trial, obj->getOBB())) {
            std::cout << "🟥 Movement blocked by object at: " << glm::to_string(obj->position) << "\n";
            return;
        }
    }

    // No collisions commit
    player->playerObj.position = proposedPos;
    player->playerObj.update();
    player->moveCamera();
}


void Scene::draw(Shader& shader) {
    if (player)
        player->playerObj.Draw(shader);

    for (auto* obj : gameObjects)
        obj->Draw(shader);
}

void Scene::handlePlayerDeath(){
 
}