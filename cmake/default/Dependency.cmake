# Created by d2306010001 at November 11/2/2024 (02:00:08)

# author        : Seongcheol Jeon
# project       : OpenGL_Class
# file path     : cmake/default/Dependency.cmake
# created date  : 2024.11.02
# modified date : 2024.11.02
# description   :


# external project 관련 명령어 셋 추가
include(ExternalProject)

ExternalProject_Add(
        dep-spdlog
        GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
        GIT_TAG "v1.x"
        # 가장 최신의 커밋만 가져오기
        GIT_SHALLOW 1
        UPDATE_COMMAND "" PATCH_COMMAND "" TEST_COMMAND ""
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
)

ExternalProject_Add(
        dep-glfw
        GIT_REPOSITORY "https://github.com/glfw/glfw.git"
        GIT_TAG "3.4"
        GIT_SHALLOW 1
        UPDATE_COMMAND "" PATCH_COMMAND "" TEST_COMMAND ""
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
            -DGLFW_BUILD_EXAMPLES=OFF
            -DGLFW_BUILD_TESTS=OFF
            -DGLFW_BUILD_DOCS=OFF
)

# dependency 리스트 및 라이브러리 파일 리스트 추가
set(DEP_LIST ${DEP_LIST} dep-spdlog)
set(DEP_LIBS ${DEP_LIBS} spdlog$<$<CONFIG:Debug>:d>)

set(DEP_LIST ${DEP_LIST} dep-glfw)
set(DEP_LIBS ${DEP_LIBS} glfw3)

message(STATUS "DEP_LIST: ${DEP_LIST}")
message(STATUS "DEP_LIBS: ${DEP_LIBS}")
