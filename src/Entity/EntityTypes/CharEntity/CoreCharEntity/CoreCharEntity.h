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
        bool isDead() const {  std::cout << "player health " << health << std::endl; return health <= 0;}
        // void Draw(Shader& shader) override;

        void moveChar(glm::vec3 direction);
        bool isMoveValid(glm::vec3 direction);
};

#endif