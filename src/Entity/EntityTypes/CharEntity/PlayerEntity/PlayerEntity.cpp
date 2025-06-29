#include <glm/glm.hpp>

#include "PlayerEntity.h"
#include "Renderable/Renderable.h"

PlayerEntity::PlayerEntity(EntityRig entRig, int health, int width,int height,glm::vec3 pos, glm::vec3 orient) 
: CoreCharEntity(entRig, health, pos, orient), playerCamera(width, height, pos + glm::vec3(0.0f, followHeight, followDist))
{
    glm::vec3 viewDir = entityRig.position - playerCamera.position;
    playerCamera.orientation = glm::normalize(glm::vec3(viewDir.x, viewDir.y, 0.0f));
    // moveCamera();
}

void PlayerEntity::Input(float deltaTime, GLFWwindow* window)
{

}

