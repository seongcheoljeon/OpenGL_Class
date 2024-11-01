#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv)
{
    SPDLOG_INFO("hello, opengl");

    SPDLOG_INFO("Initialize glfw");
    // glfw 초기화
    if (!glfwInit())
    {
        const char* description = nullptr;
        glfwGetError(&description);
        SPDLOG_ERROR("failed to initialize glfw: {}", description);
        return -1;
    }

    SPDLOG_INFO("Create glfw window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
    if (!window)
    {
        SPDLOG_ERROR("failed to create glfw window!");
        glfwTerminate();
        return -1;
    }

    // glfw loop 실행, window가 닫힐 때까지
    SPDLOG_INFO("Start main loop!");
    while (!glfwWindowShouldClose(window))
    {
        // keyboard/mouse 등 여러가지 이벤트들을 수집하는 함수. 1/60초마다 이벤트 수집
        // 해당 함수가 없으면, 너무 빠르게 실행되어 멈춘것처럼 보일 수 있음.
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
