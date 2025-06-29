#ifndef CORE_CHAR_ENTITY_H
#define CORE_CHAR_ENTITY_H

#include "CoreEntity.h"
#include "Renderable.h"
#include "EntityRig.h"

class CoreCharEntity : CoreEntity
{
    EntityRig entityRig;
    glm::vec3 position;
    glm::vec3 orientation;    

    CoreCharEntity(EntityRig entRig, glm::vec3 pos, glm::vec3 orient);

    void Draw(Shader& shader) override;
};

#endif