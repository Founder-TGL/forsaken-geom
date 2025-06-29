#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H

#include "Renderable.h"
#include "EntityRig.h"

class CoreEntity
{
    EntityRig entityRig;
    glm::vec3 position;
    glm::vec3 orientation;    

    CoreEntity(EntityRig entRig, glm::vec3 pos, glm::vec3 orient);

    virtual void Draw(Shader& shader);
};

#endif