#ifndef VOXELS_HPP
#define VOXELS_HPP
#include <cstdint>
#include <vector>
#include "shaders.hpp"

typedef struct {
    float x;
    float y;
    float z;
} coord;

typedef struct {
    bool top; // y+1
    bool bottom; // y-1
    bool left; // x+1
    bool right; // x-1
    bool forward; // z+1
    bool backward; // z-1
} neighboursAir;

class mesh {
public:
    std::vector<float> vertices;
    mesh(int size);
    void addVert(float a);
    float& operator [](int index);
};

extern const float cubeVertices[][3];

extern const float cubeIndices[];

class cube {
    GLuint VAO, VBO, EBO;
public:
    float offset;
    cube(float newOffset);
    void setupBuffers();
    void render();
};

class chunk {
public:
    uint16_t grid[16*128*16];
    mesh render();
};
#endif