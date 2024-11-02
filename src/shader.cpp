/*
Created by d2306010001 at November 11/2/2024 (19:03:00)

author        : Seongcheol Jeon
project       : OpenGL_Class
file path     : src/shader.cpp
created date  : 2024.11.02
modified date : 2024.11.02
description   : 
*/

//
// Created by d2306010001 on 11/2/2024.
//

#include "shader.h"


Shader::~Shader()
{
    // m_shader가 0이 아닌 경우에만 glDeleteShader() 호출. 0이 아니라는 말인즉슨, 셰이더가 존재한다는 뜻
    if (m_shader)
    {
        glDeleteShader(m_shader);
    }
}

ShaderUPtr Shader::CreateFromFile(const std::string& filename, GLenum shaderType)
{
    auto shader = ShaderUPtr(new Shader());
    if (!shader->LoadFile(filename, shaderType))
    {
        return nullptr;
    }
    return std::move(shader);
}

bool Shader::LoadFile(const std::string& filename, GLenum shaderType)
{
    auto result = LoadTextFile(filename);
    if (!result.has_value())
    {
        return false;
    }
    auto& code = result.value();
    const char* codePtr = code.c_str();
    int32_t codeLength = static_cast<int32_t>(code.length());

    // create and compile shader
    this->m_shader = glCreateShader(shaderType);
    glShaderSource(this->m_shader, 1, (const GLchar* const*)&codePtr, &codeLength);
    glCompileShader(m_shader);

    // check compile error
    int success = 0;
    // iv -> integer vector -> iv가 붙은 것은 맨 오른쪽이 pointer라는 것을 의미. 그래서 &success로 포인터 만듦
    glGetShaderiv(this->m_shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[1024];
        glGetShaderInfoLog(m_shader, 1024, nullptr, infoLog);
        SPDLOG_ERROR("failed to compile shader: \"{}\"", filename);
        SPDLOG_ERROR("reason: {}", infoLog);
        return false;
    }
    return true;
}
