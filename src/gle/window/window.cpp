#include "window.hpp"

void Window::WindowInit()
{
    spdlog::info("Window Opening");
    glfwSetErrorCallback(Window::GlfwErrorCallback);

    // Check if GLFW Inits
    if (!glfwInit())
    {
        spdlog::error("GLFW could not init");
    }
    // GLFW opegl hintss Sets version to 3.3 and sets core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Creates window and checks if window has int
    window = glfwCreateWindow(800, 800, "Window", NULL, NULL);
    if (!window)
    {
        spdlog::error("Could not make window");
        glfwTerminate();
    }

    // Sets window context and load GL
    glfwMakeContextCurrent(window);
    gladLoadGL();
    // glEnable(GL_DEPTH_TEST);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        spdlog::error("Failed to initialize GLAD");
    }
}
void Window::Start(std::function<void(GLFWwindow *ptr)> start, std::function<void(GLFWwindow *ptr)> update, Graphics grahicsPipeLine)
{
    spdlog::info("Starting Application");
    glViewport(0, 0, 800, 800);
    glClearColor(1.0f, 0.5f, 0.5f, 1.0f);
    start(window);
    grahicsPipeLine.Init();
    _Update(update, grahicsPipeLine);
}
void Window::_FpsCounterLog(double fps)
{
    spdlog::info("FPS: {}", fps);
}
void Window::_Update(std::function<void(GLFWwindow *ptr)> update, Graphics grahicsPipeLine)
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
            _FpsCounterLog(frameCount);

            frameCount = 0;
            previousTime = currentTime;
        }
        // Render here

        // Poll for and process events
        glfwPollEvents();
        update(window);
        grahicsPipeLine.GraphicsPipeLineUpdate(window);
    }
}
void Window::Cleanup()
{
    spdlog::info("Closing GLFW");
    glfwDestroyWindow(window);
    glfwTerminate();
}