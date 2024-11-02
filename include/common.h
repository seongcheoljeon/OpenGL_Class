/*
Created by d2306010001 at November 11/2/2024 (17:58:17)

author        : Seongcheol Jeon
project       : OpenGL_Class
file path     : src/common.h
created date  : 2024.11.02
modified date : 2024.11.02
description   : 
*/

//
// Created by d2306010001 on 11/2/2024.
//

#ifndef COMMON_H
#define COMMON_H

#include <memory>
#include <string>
#include <optional>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <spdlog/spdlog.h>


std::optional<std::string> LoadTextureFile(const std::string& filename);

#endif //COMMON_H
