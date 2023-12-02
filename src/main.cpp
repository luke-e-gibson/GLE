#include "window/window.hpp"
#include "GLFW/glfw3.h"
#include "spdlog/spdlog.h"

bool pressed = false;

void update(GLFWwindow *window)
{
    //** Update Locic Here **//
    int state = glfwGetKey(window, GLFW_KEY_A);
    if (state == GLFW_PRESS && !pressed)
    {
        spdlog::info("Key A pressed");
        pressed = true;
    }
    else
    {
        pressed = false;
    }
}
void error_callback(int error, const char *description)
{
    spdlog::error("Error: {}", description);
}

int main()
{
    Window window;

    window.WindowInit();
    glfwSetErrorCallback(error_callback);
    window.Start(update);

    return 0;
}
