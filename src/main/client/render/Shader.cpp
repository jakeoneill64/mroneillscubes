//
// Created by Jake M O'Neill on 09/09/2022.
//

#include "Shader.h"
#include "render.h"
#include <fstream>
#include <vector>

Shader::Shader(const char *fileName, const uint32_t& shaderType) {

    std::ifstream ifs(fileName);
    std::string code( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );

    const char * codeCString = code.c_str();

    glWrap(m_shaderId = glCreateShader(shaderType));

    glWrap(glShaderSource(m_shaderId, 1, &codeCString, nullptr));
    glWrap(glCompileShader(m_shaderId));

}



