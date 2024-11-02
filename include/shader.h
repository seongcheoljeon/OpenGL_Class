/*
Created by d2306010001 at November 11/2/2024 (18:48:33)

author        : Seongcheol Jeon
project       : OpenGL_Class
file path     : include/shader.h
created date  : 2024.11.02
modified date : 2024.11.02
description   : 
*/

//
// Created by d2306010001 on 11/2/2024.
//

#ifndef SHADER_H
#define SHADER_H

#include "common.h"


/*
 * Shader class 설계 이유
 * 생성자가 private인 이유, CreateFromFile() 함수 외에 다른 방식의 Shader 인스턴스 생성을 막기 위함
 * getter는 있지만 setter는 없는 이유, shader 오브젝트의 생성 관리는 Shader 내부에서만 관리하기 위함
 * LoadFile()이 bool을 리턴하는 이유, 생성에 실패할 경우 false를 리턴하기 위함
*/
CLASS_PTR(Shader);

class Shader
{
public:
    static ShaderUPtr CreateFromFile(const std::string& filename, GLenum shaderType);

    ~Shader();

    uint32_t Get() const { return m_shader; }

private:
    Shader() = default;

    bool LoadFile(const std::string& filename, GLenum shaderType);

    uint32_t m_shader{0};
};

#endif //SHADER_H
