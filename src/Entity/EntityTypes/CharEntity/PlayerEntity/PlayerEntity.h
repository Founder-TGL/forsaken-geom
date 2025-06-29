#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "CoreCharEntity/CoreCharEntity.h"
#include "Renderable/Renderable.h"
#include "EntityRig.h"

class PlayerEntity : public CoreCharEntity
{
    public:
        PlayerEntity(EntityRig entRig, glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 orient = glm::vec3{0.0f, 0.0f, 1.0f});

        // void Draw(Shader& shader) override;
};

#endif