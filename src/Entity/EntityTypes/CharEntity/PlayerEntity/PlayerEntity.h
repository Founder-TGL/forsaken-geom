#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "CoreCharEntity/CoreCharEntity.h"
#include "Renderable/Renderable.h"
#include "Camera.h"
#include "EntityRig.h"

class PlayerEntity : public CoreCharEntity
{
    public:
        int width;
        int height;
        float followDist   = 5.0f;
        float followHeight = 2.0f; 
        Camera playerCamera;
        float yaw = 0.0f;
        bool mouseLocked = false;

        PlayerEntity(EntityRig entRig, int health, int speed, int width, int height, glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 orient = glm::vec3{0.0f, 0.0f, 1.0f});

        void Input(float deltaTime, GLFWwindow* window);
        void moveCamera();


};

#endif