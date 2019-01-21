#ifndef SHADER_H
#define SHADER_H

#include <string>

#include "glad/glad.h"

namespace sap::gfx
{
    class Shader
    {
        private:
            unsigned int m_programID;

        private:
            void compileShader(const std::string& vshFile, int shaderType) const;
            void linkShaders() const;

        public:
            Shader(const std::string& vshFile, const std::string& fshFile);
            ~Shader();
    };
}





#endif  // SHADER_H