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
    mesh(int size) {
        vertices.reserve(size);
    }
    void addVert(float a) {
        vertices.push_back(a);
    }
    float& operator [](int index) {
        return vertices[index];
    }
};

class chunk {
public:
    uint16_t grid[16*128*16];
    mesh render() {
        mesh chunkMesh = mesh(21);
        for (int i = 0; i < 16*128*16; i++) {
            // uhhhhhhh
            // im too eepy to think about voxel rendering
            
        }
        chunkMesh.vertices.shrink_to_fit();
        return chunkMesh;
    }
};