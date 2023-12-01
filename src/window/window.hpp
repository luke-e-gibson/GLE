#include "../glad/glad.h"
#include "GLFW/glfw3.h"
#include "functional"

class Window
{
public:
    GLFWwindow *window;

    void glfwErrorCallback(int error, const char *description);
    void WindowInit();
    void Start(std::function<void(GLFWwindow *ptr)> update);

private:
    void _Update(std::function<void(GLFWwindow *ptr)> update);
};
