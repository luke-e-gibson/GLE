#include "window.hpp"
#include "spdlog/spdlog.h"

void Window::glfwErrorCallback(int error, const char *description)
{
    spdlog::error("ERROR CODE: {}; {}", error, description);
}

void Window::WindowInit()
{
    if (!glfwInit())
    {
        spdlog::error("GLFW could not init");
    }

    window = glfwCreateWindow(640, 480, "Window", NULL, NULL);
    if (!window)
    {
        spdlog::error("Could not make window");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        spdlog::error("Failed to initialize GLAD");
    }
}
void Window::Start(std::function<void(GLFWwindow *ptr)> update)
{
    _Update(update);
}
void Window::_Update(std::function<void(GLFWwindow *ptr)> update)
{
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
        update(window);
    }

    glfwTerminate();
}
