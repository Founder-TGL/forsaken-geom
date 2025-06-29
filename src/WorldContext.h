#ifndef WORLD_CONTEXT_H
#define WORLD_CONTEXT_H

#include<vector>

class CoreEntity;


struct WorldContext {
    inline static WorldContext* s_instance = nullptr; 

    std::vector<CoreEntity*>* collidables = nullptr;

    static void SetInstance(WorldContext* ctx) { s_instance = ctx; }
};

#endif