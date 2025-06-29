#ifndef CORE_CHAR_ENTITY_H
#define CORE_CHAR_ENTITY_H

#include <vector>

#include "CoreEntity.h"
#include "Renderable/Renderable.h"
#include "EntityRig.h"


class CoreCharEntity : public CoreEntity
{
    public:
        int health;
        float speed;
        CoreCharEntity(EntityRig entRig, int health ,glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 orient = glm::vec3{0.0f, 0.0f, 1.0f});
        bool isDead() const { return health <= 0; std::cout << "player health " << health << std::endl;}
        // void Draw(Shader& shader) override;

        void moveChar(std::vector<CoreEntity> collidables, glm::vec3 direction);
        bool isMoveValid(std::vector<CoreEntity> collidables, glm::vec3 direction);
};

#endif