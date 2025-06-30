#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/string_cast.hpp>
#include "PlayerEntity.h"
#include "Renderable/Renderable.h"

PlayerEntity::PlayerEntity(EntityRig entRig, int health, float speed,  int width,int height,glm::vec3 pos, glm::vec3 orient) 
: CoreCharEntity(entRig, health,speed, pos, orient), playerCamera(width, height, pos + glm::vec3(0.0f, followHeight, followDist)), width(width), height(height)
{
    entityRig = entRig;
    glm::vec3 viewDir = entityRig.position - playerCamera.position;
    playerCamera.orientation = glm::normalize(glm::vec3(viewDir.x, viewDir.y, 0.0f));
    moveCamera();
}

void PlayerEntity::Input(float deltaTime, GLFWwindow* window)
{
    if (mouseLocked) {
        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        float deltaX = float(mouseX - width / 2);
        float sensitivity = 0.15f;
        yaw -= deltaX * sensitivity;

        if (yaw > 360.f) yaw -= 360.f;
        if (yaw < 0.f) yaw += 360.f;

        orientation = glm::normalize(glm::vec3(sin(glm::radians(yaw)),0.0f,cos(glm::radians(yaw))));

        glfwSetCursorPos(window, width / 2, height / 2);

        
    }

    glm::vec3 dir(0.0f);
    glm::vec3 forward = orientation;
    glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0, 1, 0)));

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) dir += forward;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) dir -= forward;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) dir -= right;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) dir += right;
    moveChar(dir, deltaTime);

    // Mouse lock/unlock
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && !mouseLocked) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        mouseLocked = true;
        glfwSetCursorPos(window, width / 2, height / 2);
    }

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        mouseLocked = false;
    }

    updatePosition();  
    moveCamera();
}

void PlayerEntity::moveCamera() {


    // 1) get the player’s flat forward direction
    glm::vec3 forward = orientation;
    forward.y = 0.0f;
    forward = glm::normalize(forward);

    // 2) compute the desired camera position behind and above
    glm::vec3 camPos = position
                     - forward * followDist      // behind
                     + glm::vec3(0.0f, followHeight, 0.0f); // up

    // 3) point camera at the player’s position
    glm::vec3 lookDir = position - camPos;
    lookDir = glm::normalize(lookDir);

    // 4) write into your Camera
    playerCamera.position    = camPos;
    playerCamera.orientation = lookDir;
}

