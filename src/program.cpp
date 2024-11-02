/*
Created by d2306010001 at November 11/3/2024 (00:22:57)

author        : Seongcheol Jeon
project       : OpenGL_Class
file path     : src/Program.cpp
created date  : 2024.11.03
modified date : 2024.11.03
description   : 
*/

//
// Created by d2306010001 on 11/3/2024.
//

#include "program.h"


ProgramUPtr Program::Create(const std::vector<ShaderSPtr>& shaders)
{
    auto program = ProgramUPtr(new Program());
    if (!program->Link(shaders))
    {
        return nullptr;
    }
    return std::move(program);
}

bool Program::Link(const std::vector<ShaderSPtr>& shaders)
{
    // id 얻음
    m_program = glCreateProgram();
    for (auto& shader : shaders)
    {
        // shader id를 program에 attach
        glAttachShader(m_program, shader->Get());
    }
    glLinkProgram(m_program);

    int success = 0;
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[1024];
        glGetProgramInfoLog(m_program, 1024, nullptr, infoLog);
        SPDLOG_ERROR("failed to link program: {}", infoLog);
        return false;
    }
    return true;
}

Program::~Program()
{
    if (m_program)
    {
        glDeleteProgram(m_program);
    }
}