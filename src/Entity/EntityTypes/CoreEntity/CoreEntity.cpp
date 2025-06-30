#include <glm/glm.hpp>

#include "CoreEntity.h"
#include "Renderable/Renderable.h"
#include <glm/glm.hpp>


CoreEntity::CoreEntity(EntityRig entRig, glm::vec3 pos, glm::vec3 orient) 
: entityRig(std::move(entRig)), position(pos), orientation(orient)
{
    this->position = pos;
    this->orientation = orient;
    updatePosition();
    entityRig.update();
}

void CoreEntity::updatePosition()
{
    entityRig.position = position;
    entityRig.orientation = orientation;
    entityRig.update();
}

void CoreEntity::aimAt(CoreEntity* target)
{
    glm::vec3 forward = target->orientation;
    forward.y = 0.0f;
    forward = glm::normalize(forward);

    glm::vec3 lookDir = target->position - position;
    lookDir = glm::normalize(lookDir);

    orientation = lookDir;

    updatePosition();
}

void CoreEntity::Draw(Shader& shader){entityRig.Draw(shader);}