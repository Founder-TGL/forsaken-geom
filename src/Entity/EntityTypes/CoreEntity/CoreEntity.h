#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H

#include "Renderable/Renderable.h"
#include "EntityRig.h"

class CoreEntity
{
    protected:
    static std::vector<CoreEntity*>* s_collidables;

    public:
        EntityRig entityRig;
        glm::vec3 position;
        glm::vec3 orientation;    

        CoreEntity(EntityRig entRig, glm::vec3 pos, glm::vec3 orient);

        virtual void Draw(Shader& shader);

        // static void SetCollidableList(std::vector<CoreEntity*>* list) {
        //     s_collidables = list;
        // }

};

#endif