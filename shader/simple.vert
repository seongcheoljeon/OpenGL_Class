#version 460 core       // OpenGL version: 4.6 이상에서 실행시킬 수 있는 shader 코드이다. 라고 명시함

layout(location = 0) in vec3 aPos;

void main(){
    gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
}
