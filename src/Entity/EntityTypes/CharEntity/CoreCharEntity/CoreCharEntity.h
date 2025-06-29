#ifndef CORE_CHAR_ENTITY_H
#define CORE_CHAR_ENTITY_H

#include "CoreEntity.h"
#include "Renderable.h"
#include "EntityRig.h"

class CoreCharEntity : public CoreEntity
{
    public:
        EntityRig entityRig;
        glm::vec3 position;
        glm::vec3 orientation;    

        CoreCharEntity(EntityRig entRig, glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 orient = glm::vec3{0.0f, 0.0f, 1.0f});

        void Draw(Shader& shader) override;
};

#endif