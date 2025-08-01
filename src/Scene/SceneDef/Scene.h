#ifndef SCENE_H
#define SCENE_H

#include "PlayerEntity/PlayerEntity.h"
#include "CoreEntity.h"
#include "EnemyEntity/EnemyEntity.h"
#include <vector>

class Scene {

public:
    public:
        Scene(GLFWwindow* window);
        void updateAndRender(Shader& shader);
        void setPlayer(PlayerEntity* p) { player = p; addEntity(p);}
        PlayerEntity* getPlayer(){return player;}
        void addEntity(CoreEntity* entity) { collidables->push_back(entity); }

    private:
        GLFWwindow* window;
        float lastTime;
        PlayerEntity* player = nullptr;
        std::vector<CoreEntity*>* collidables;
        std::vector<CoreEntity*>  spawnBuffer;

        void update(float deltaTime);
        void render(Shader& shader);
        void enemyInteraction(EnemyEntity* enemy);
};


#endif