#include "shaders.hpp"

const char* vertexShaderSource = R"glsl(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos, 1.0);
    }
)glsl";

const char* fragmentShaderSource = R"glsl(
    #version 330 core
    out vec4 FragColor;
    uniform float time;
    void main() {
        FragColor = vec4(
            (sin(time) + 1.0) / 2.0,
            (cos(time * 0.7) + 1.0) / 2.0,
            (sin(time * 0.3) + 1.0) / 2.0,
            1.0
        );
    }
)glsl";
