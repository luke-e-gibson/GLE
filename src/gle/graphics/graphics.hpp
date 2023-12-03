#include <string>
#include "../glad/glad.h"
#include "GLFW/glfw3.h"

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

class Graphics
{
public:
    GLuint ShaderProgram;
    GLuint VBO, VAO, EBO;
    void Init();
    void GraphicsPipeLineUpdate(GLFWwindow *window);
    void Cleanup();

private:
    void _ShaderInit();
};

#endif // GRAPHICS_HPP
