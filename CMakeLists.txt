cmake_minimum_required(VERSION 3.29)
project(OpenGL_Class)

set(CMAKE_CXX_STANDARD 20)

set(WINDOW_NAME "Hello, OpenGL!")
set(WINDOW_WIDTH 960)
set(WINDOW_HEIGHT 540)

# dependency 관련 변수 설정
set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)

add_executable(${PROJECT_NAME} src/main.cpp)

include(cmake/default/Dependency.cmake)

# unicode 지원을 위한 /utf-8 옵션 추가
target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8")

# include/lib 관련 옵션 추가
target_include_directories(${PROJECT_NAME} PRIVATE ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${DEP_LIBS})

target_compile_definitions(${PROJECT_NAME} PRIVATE
        WINDOW_NAME="${WINDOW_NAME}"
        WINDOW_WIDTH=${WINDOW_WIDTH}
        WINDOW_HEIGHT=${WINDOW_HEIGHT}
)

# dependency 빌드 순서 설정 -> dependency들이 먼저 빌드되도록
add_dependencies(${PROJECT_NAME} ${DEP_LIST})

