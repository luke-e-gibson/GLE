#include "../glad/glad.h"
#include "spdlog/spdlog.h"
#include "GLFW/glfw3.h"
#include "functional"

class Window
{
public:
    GLFWwindow *window;
    // void SetGLFWErrorCallBack(std::function<GLFWerrorfun(int error, const char *description)> callback);
    void WindowInit();
    static void GlfwErrorCallback(int errorCode, const char *message)
    {
        spdlog::error("ERROR CODE: {}, ERROR MESSAGE: {}", errorCode, message);
    }

    void Start(std::function<void(GLFWwindow *ptr)> start, std::function<void(GLFWwindow *ptr)> update);

private:
    void _Update(std::function<void(GLFWwindow *ptr)> update);
    void _FpsCounter(double fps);
};
