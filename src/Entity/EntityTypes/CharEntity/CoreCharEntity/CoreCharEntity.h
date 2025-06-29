#ifndef CORE_CHAR_ENTITY_H
#define CORE_CHAR_ENTITY_H

#include "CoreEntity.h"
#include "Renderable/Renderable.h"
#include "EntityRig.h"

class CoreCharEntity : public CoreEntity
{
    public:
        CoreCharEntity(EntityRig entRig, glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 orient = glm::vec3{0.0f, 0.0f, 1.0f});

        // void Draw(Shader& shader) override;
};

#endif