#include <cstdint>
#include <vector>
#include "shaders.hpp"
#include "voxels.hpp"

mesh::mesh(int size) {
    vertices.reserve(size);
}
void mesh::addVert(float a) {
    vertices.push_back(a);
}
float& mesh::operator [](int index) {
    return vertices[index];
}

const float cubeVertices[][3] = {
        // Position
    {-1.0f, -1.0f, -1.0f},
    { 1.0f, -1.0f, -1.0f},
    { 1.0f,  1.0f, -1.0f},
    {-1.0f,  1.0f, -1.0f},

    {-1.0f, -1.0f,  1.0f},
    { 1.0f, -1.0f,  1.0f},
    { 1.0f,  1.0f,  1.0f},
    {-1.0f,  1.0f,  1.0f}
};

const float cubeIndices[] = {
        // Bottom face
    0, 1, 2,  0, 2, 3,
    // Top face  
    4, 5, 6,  4, 6, 7,
    // Front face
    3, 2, 6,  3, 6, 7,
    // Back face
    0, 1, 5,  0, 5, 4,
    // Left face
    0, 3, 7,  0, 7, 4,
    // Right face
    1, 2, 6,  1, 6, 5
};

    cube::cube(float newOffset) {
        offset = newOffset;
    }
    void cube::setupBuffers() {
        // Generate buffers
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        // Bind VAO first
        glBindVertexArray(VAO);

        // Vertex Buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, 
                    8 * 3,
                    cubeVertices, 
                    GL_STATIC_DRAW);

        // Element Buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                    36 * sizeof(GLuint),
                    cubeIndices,
                    GL_STATIC_DRAW);

        // Position attribute (location = 0)
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 
                            3, (void*)0);
        glEnableVertexAttribArray(0);

        // Color attribute (location = 1)
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
                            3, (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // Unbind
        glBindVertexArray(0);
    }
void cube::render() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

    uint16_t grid[16*128*16];
    mesh chunk::render() {
        mesh chunkMesh = mesh(21);
        for (int i = 0; i < 16*128*16; i++) {
            // uhhhhhhh
            // im too eepy to think about voxel rendering

        }
        chunkMesh.vertices.shrink_to_fit();
        return chunkMesh;
    }