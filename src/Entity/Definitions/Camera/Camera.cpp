#include "Camera.h"
#include <iostream>
#include <glm/gtx/string_cast.hpp>


        Camera::Camera(int width, int height, glm::vec3 position){
            this->width = width;
            this->height = height;
            this->position = position;
        }

        void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader&shader, const char* uniform){
            // Initializes matrices since otherwise they will be the null matrix
            glm::mat4 view = glm::mat4(1.0f);
            glm::mat4 projection = glm::mat4(1.0f);

            // Makes camera look in the right direction from the right position
            view = glm::lookAt(position, position + orientation, Up);
            // Adds perspective to the scene
            projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

            // Exports the camera matrix to the Vertex Shader
            glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
        }

        
        