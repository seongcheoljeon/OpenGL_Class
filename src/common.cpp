/*
Created by d2306010001 at November 11/2/2024 (18:06:42)

author        : Seongcheol Jeon
project       : OpenGL_Class
file path     : src/common.cpp
created date  : 2024.11.02
modified date : 2024.11.02
description   : 
*/

//
// Created by d2306010001 on 11/2/2024.
//

#include "common.h"

#include <fstream>
#include <sstream>


std::optional<std::string> LoadTextFile(const std::string& filename)
{
    const std::ifstream fin(filename);
    if(!fin.is_open())
    {
        SPDLOG_ERROR("failed to open file: {}", filename);
        // std::optinoal은 값이 없을 때, {}를 반환하면 아무것도 없는 값을 반환한다.
        return {};
    }
    std::stringstream text;
    text << fin.rdbuf();
    return text.str();
}

