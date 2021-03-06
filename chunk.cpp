#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string.h>
#include "chunk.h"
#include "main.h"
#include "blocks.h"

Chunk::Chunk(int x, int y, int z) {
    pos = glm::ivec3(x, y, z);
    blocks = (Block ****)(new Block***[XBlocks][YBlocks][ZBlocks]);

    for (int x = 0; x < XBlocks; x++) {
        blocks[x] = (Block ***)new Block**[YBlocks][ZBlocks];
        for (int y = 0; y < YBlocks; y++) {
            blocks[x][y] = new Block*[ZBlocks];
            memset(blocks[x][y], 0, ZBlocks * sizeof(Block*));
        }
    }
}


void Chunk::render() {
    for (int x = 0; x < XBlocks; x++) {
        for (int y = 0; y < YBlocks; y++) {
            for (int z = 0; z < ZBlocks; z++) {
                if (blocks[x][y][z] != NULL) {
                    glm::mat4 translateMatrix =
                        glm::translate(glm::mat4(1.0f),
                                       glm::vec3(x * 1 + pos.x * XBlocks,
                                                 y * 1 + pos.y * YBlocks,
                                                 z * 1 + pos.z * ZBlocks));
                    glUniformMatrix4fv(worldMatUniform, 1, GL_FALSE, glm::value_ptr(translateMatrix));
                    blocks[x][y][z]->render();
                }
            }
        }
    }
}
