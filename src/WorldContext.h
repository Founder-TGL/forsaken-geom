#ifndef WORLD_CONTEXT_H
#define WORLD_CONTEXT_H

#include <vector>

class CoreEntity;
class BulletEntity;


struct WorldContext {
    inline static WorldContext* s_instance = nullptr;

    std::vector<CoreEntity*>* collidables = nullptr;
    std::vector<BulletEntity*>* bullets = nullptr;


    static void SetInstance(WorldContext* ctx) {
        s_instance = ctx;
    }

    static WorldContext* Instance() {
        return s_instance;
    }

};

#endif