#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace sap::gfx
{
    class Shader
    {
        private:
            unsigned int m_programID;

        private:
            unsigned int compileShader(const std::string& sourceFile, int shaderType) const;
            void linkShaders(unsigned int vsh, unsigned int fsh) const;

        public:
            Shader(const std::string& vshFile, const std::string& fshFile);
            ~Shader();
            void bind() const;
            void unbind() const;
    };
}


#endif  // SHADER_H