#include <glm/glm.hpp>

#include "CoreEntity.h"
#include "Renderable/Renderable.h"


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

void CoreEntity::Draw(Shader& shader){entityRig.Draw(shader);}