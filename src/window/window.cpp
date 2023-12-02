#include "window.hpp"

void Window::WindowInit()
{
    spdlog::info("Window Opening");
    glfwSetErrorCallback(Window::GlfwErrorCallback);
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
    gladLoadGL();
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        spdlog::error("Failed to initialize GLAD");
    }
}
void Window::Start(std::function<void(GLFWwindow *ptr)> start, std::function<void(GLFWwindow *ptr)> update)
{
    spdlog::info("Starting Application");
    glClearColor(1.0f, 0.5f, 0.5f, 1.0f);
    start(window);
    _Update(update);
}
void Window::_FpsCounter(double fps)
{
    spdlog::info("FPS: {}", fps);
}
void Window::_Update(std::function<void(GLFWwindow *ptr)> update)
{
    spdlog::info("Enterd Mainloop");
    double previousTime = glfwGetTime();
    int frameCount = 0;
    while (!glfwWindowShouldClose(window))
    {
        double currentTime = glfwGetTime();
        frameCount++;
        // If a second has passed.
        if (currentTime - previousTime >= 1.0)
        {
            // Display the frame count here any way you want.
            _FpsCounter(frameCount);

            frameCount = 0;
            previousTime = currentTime;
        }
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
        update(window);
    }

    spdlog::info("Closing GLFW");
    glfwTerminate();
}
