/*
Created by d2306010001 at November 11/3/2024 (02:19:19)

author        : Seongcheol Jeon
project       : OpenGL_Class
file path     : src/context.cpp
created date  : 2024.11.03
modified date : 2024.11.03
description   : 
*/

//
// Created by d2306010001 on 11/3/2024.
//

#include "context.h"


ContextUPtr Context::Create()
{
    auto context = ContextUPtr(new Context());
    if (!context->Init())
    {
        return nullptr;
    }
    return std::move(context);
}

bool Context::Init()
{
    ShaderSPtr vertShader = Shader::CreateFromFile("./shader/simple.vert", GL_VERTEX_SHADER);
    ShaderSPtr fragShader = Shader::CreateFromFile("./shader/simple.frag", GL_FRAGMENT_SHADER);
    if (!vertShader || !fragShader)
    {
        return false;
    }
    SPDLOG_INFO("vertex shader id: {}", vertShader->Get());
    SPDLOG_INFO("fragment shader id: {}", fragShader->Get());

    this->m_program = Program::Create({fragShader, vertShader});
    if (!m_program)
    {
        return false;
    }
    SPDLOG_INFO("program id: {}", this->m_program->Get());

    // 컬러 프레임버퍼 화면을 클리어 (화면을 지울때 무슨색으로 지울까?)
    glClearColor(0.0f, 0.1f, 0.2f, 0.0f);

    uint32_t vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    return true;
}

void Context::Render()
{
    // 프레임버퍼 클리어 (실제로 화면을 지워주는 함수)
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(this->m_program->Get());
    glDrawArrays(GL_POINTS, 0, 1);
}
