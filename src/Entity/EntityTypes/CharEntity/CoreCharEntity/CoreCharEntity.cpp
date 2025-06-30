#include <glm/glm.hpp>

#include "CoreCharEntity.h"
#include "Renderable/Renderable.h"

CoreCharEntity::CoreCharEntity(EntityRig entRig, int health, float speed, glm::vec3 pos, glm::vec3 orient) : CoreEntity(entRig, pos, orient), speed(speed), health(health){}

void CoreCharEntity::moveChar(glm::vec3 direction, float deltaTime)
{
    glm::vec3 projectedPosition = position + speed * direction * deltaTime;

    if(isMoveValid(projectedPosition))position = projectedPosition;
    updatePosition();

}
bool CoreCharEntity::isMoveValid(glm::vec3 projectedPosition)
{
    Hitbox::OBB projectedOBB = this->getOBB();
    projectedOBB.center = projectedPosition;

    for(CoreEntity* ent: getCollidables())
    {
        if (Hitbox::doOBBsIntersect(projectedOBB, ent->getOBB()))
        {
            return false;
        }
    }
    return true;
}
