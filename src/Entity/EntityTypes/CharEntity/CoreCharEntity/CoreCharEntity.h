#ifndef CORE_CHAR_ENTITY_H
#define CORE_CHAR_ENTITY_H

#include <vector>

#include "CoreEntity.h"
#include "Renderable/Renderable.h"
#include "EntityRig.h"
// #include "BulletEntity.h"


class CoreCharEntity : public CoreEntity
{
    public:
        int health;
        float speed = 0.1f;
        CoreCharEntity(EntityRig entRig, int health, float speed, glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 orient = glm::vec3{0.0f, 0.0f, 1.0f});
        bool isDead() const {  std::cout << "player health " << health << std::endl; return health <= 0;}
        // void Draw(Shader& shader) override;

        void moveChar(glm::vec3 direction, float deltaTime);
        bool isMoveValid(glm::vec3 direction);
        bool isAlive() const override {return health > 0;}

        BulletEntity* shoot();
        
};

#endif