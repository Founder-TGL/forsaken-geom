#define GLM_ENABLE_EXPERIMENTAL
// #include <glm/gtx/string_cast.hpp>
#include<iostream>
#include<glad/glad.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<GLFW/glfw3.h>
#include<filesystem>
// #include"shaderClass.h"
#include "WorldContext.h"

#include "PreFabs/shapeData.h"
#include "Camera.h"
#include "Renderable/Renderable.h"
#include "EntityRig.h"
#include "CoreCharEntity/CoreCharEntity.h"
#include "PlayerEntity/PlayerEntity.h"
#include "Scene.h"
#include "EnemyEntity/EnemyEntity.h"

#include <math.h>

const static int width = 1600;
const static int height = 1000;

int main() {
    // --- Init GLFW + window ---
    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);

    //stores all the collidables in a world class sop they can be cccess from entities without needing it passed in
    std::vector<CoreEntity*> collidables;
    WorldContext world;
    world.collidables = &collidables;
    WorldContext::SetInstance(&world); 

    Shader shaderProgram("src/Shaders/default.vert", "src/Shaders/default.frag");
    Renderable pyramid(pyramidVertices, pyramidVerticesSize, pyramidIndices, pyramidIndicesSize);
    EntityRig pyramidTestRig(pyramid);
    EnemyEntity testPyramid(pyramidTestRig, 10, 0.1f, 10,  glm::vec3{0.0f, 0.0f, 10.0f});

    PlayerEntity player(pyramidTestRig, 10, 5.0f, width, height);

    Scene mainScene(window);

    mainScene.setPlayer(&player);
    mainScene.addEntity(&testPyramid);
    
    

    while (!glfwWindowShouldClose(window)) 
    {
        mainScene.updateAndRender(shaderProgram);
        glfwPollEvents();
    }   


}

