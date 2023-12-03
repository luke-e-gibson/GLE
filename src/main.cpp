#include "gle/GLE.hpp"

bool pressed = false;

void update(GLFWwindow *window)
{
    //** Update Locic Here **//
    int state = glfwGetKey(window, GLFW_KEY_A);
    if (state == GLFW_PRESS && !pressed)
    {
        spdlog::info("Key A PRESS");
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        pressed = true;
    }
    if (state == GLFW_RELEASE && pressed)
    {
        spdlog::info("Key A RELEASE");
        glClearColor(1.0f, 0.5f, 0.5f, 1.0f);
        pressed = false;
    }
}
void start(GLFWwindow *window)
{
    spdlog::info("Start Application");
}

int main()
{
    Window window;
    Graphics graphics;

    window.WindowInit();
    window.Start(start, update, graphics);
    window.Cleanup();

    return 0;
}
