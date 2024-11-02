/*
Created by d2306010001 at November 11/3/2024 (02:15:04)

author        : Seongcheol Jeon
project       : OpenGL_Class
file path     : include/context.h
created date  : 2024.11.03
modified date : 2024.11.03
description   : Refactoring -> OpenGL object들을 관리하고 렌더링하는 코드 분리

- 프로그램 life-cycle을 고려하여 코드 리펙토링
- GLFW / OpenGL Context / GLAD 초기화
- 그림을 그리기 위한 OpenGL objects 생성 (shader / program)
- 렌더링
- OpenGL objects 제거
- GLFW 종료 / 프로그램 종료
*/

//
// Created by d2306010001 on 11/3/2024.
//

#ifndef CONTEXT_H
#define CONTEXT_H

#include "common.h"
#include "program.h"


CLASS_PTR(Context);

class Context
{
public:
    static ContextUPtr Create();
    void Render();

private:
    Context() = default;
    bool Init();
    ProgramUPtr m_program;
};

#endif //CONTEXT_H
