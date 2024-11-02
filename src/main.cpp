/*
 * project: OpenGL_Class
 * author: Seongcheol Jeon
 * created date: 2024.11.02
 * modified date: 2024.11.02
 * description: OpenGL
*/

#include "common.h"
#include "shader.h"

#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


// 윈도우의 프레임버퍼 크기가 변경되었을 때, 호출하기 위한 콜백 정의
// glViewport() : OpenGL이 그림을 그릴 영역을 정의
void OnFramebufferSizeChange(GLFWwindow* window, const int32_t width, const int32_t height)
{
    SPDLOG_INFO("framebuffer size changed: ({} x {})", width, height);
    glViewport(0, 0, width, height);
}

void OnKeyEvent(GLFWwindow* window, const int32_t key, const int32_t scancode, const int32_t action, const int32_t mods)
{
    SPDLOG_INFO("key: {}, scancode: {}, action: {}, mods: {}{}{}",
                key, scancode,
                action == GLFW_PRESS ? "Pressed" :
                action == GLFW_RELEASE ? "Released" :
                action == GLFW_REPEAT ? "Repeat" : "Unknown",
                mods & GLFW_MOD_CONTROL ? "C" : "-",
                mods & GLFW_MOD_SHIFT ? "S" : "-",
                mods & GLFW_MOD_ALT ? "A" : "-");
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}


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

    // OpenGL 4.6을 사용하겠다고 명시
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // window 생성
    SPDLOG_INFO("Create glfw window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
    if (!window)
    {
        SPDLOG_ERROR("failed to create glfw window!");
        glfwTerminate();
        return -1;
    }
    // 만들어진 OpenGL Context를 앞으로 사용하겠다고 명시. (window를 생성하면, 자동으로 context가 생성됨)
    glfwMakeContextCurrent(window);

    // glad를 사용하여 OpenGL 함수들을 로드
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        SPDLOG_ERROR("failed to initialize grad");
        glfwTerminate();
        return -1;
    }
    auto glVersion = glGetString(GL_VERSION);
    SPDLOG_INFO("OpenGL context version: {}", reinterpret_cast<const char*>(glVersion));

    //
    auto vertexShader = Shader::CreateFromFile("./shader/simple.vert", GL_VERTEX_SHADER);
    auto fragmentShader = Shader::CreateFromFile("./shader/simple.frag", GL_FRAGMENT_SHADER);
    SPDLOG_INFO("vertex shader id: {}", vertexShader->Get());
    SPDLOG_INFO("fragment shader id: {}", fragmentShader->Get());
    //

    OnFramebufferSizeChange(window, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(window, OnFramebufferSizeChange);
    glfwSetKeyCallback(window, OnKeyEvent);

    // glfw loop 실행, window가 닫힐 때까지
    SPDLOG_INFO("Start main loop!");
    while (!glfwWindowShouldClose(window))
    {
        // keyboard/mouse 등 여러가지 이벤트들을 수집하는 함수. 1/60초마다 이벤트 수집
        // 해당 함수가 없으면, 너무 빠르게 실행되어 멈춘것처럼 보일 수 있음.
        glfwPollEvents();
        // 컬러 프레임버퍼 화면을 클리어 (화면을 지울때 무슨색으로 지울까?)
        glClearColor(0.0f, 0.1f, 0.2f, 0.0f);
        // 프레임버퍼 클리어 (실제로 화면을 지워주는 함수)
        glClear(GL_COLOR_BUFFER_BIT);
        // 화면에 그림을 그리는 과정
        // - 프레임버퍼 2개를 준비 (front/back)
        // - back buffer에 그림 그리기
        // - front와 back을 바꿔치기
        // - 위의 과정 반복
        // 그림이 그려지는 과정이 노출되지 않도록 해줌
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
