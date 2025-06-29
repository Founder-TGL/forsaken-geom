#include<vector>

#include"CoreEntity.h"

struct WorldContext {
    static WorldContext* s_instance = nullptr; 

    std::vector<CoreEntity*>* collidables = nullptr;

    static void SetInstance(WorldContext* ctx) { s_instance = ctx; }
};