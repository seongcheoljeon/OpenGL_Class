/*
Created by d2306010001 at November 11/3/2024 (00:17:47)

author        : Seongcheol Jeon
project       : OpenGL_Class
file path     : include/program.h
created date  : 2024.11.03
modified date : 2024.11.03
description   : 
*/

//
// Created by d2306010001 on 11/3/2024.
//

#ifndef PROGRAM_H
#define PROGRAM_H

#include "common.h"
#include "shader.h"


CLASS_PTR(Program);

class Program
{
public:
    static ProgramUPtr Create(const std::vector<ShaderSPtr>& shaders);
    ~Program();
    uint32_t Get() const { return m_program; }

private:
    Program() = default;
    bool Link(const std::vector<ShaderSPtr>& shaders);
    uint32_t m_program{0};
};


#endif //PROGRAM_H
