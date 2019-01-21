
#include <iostream>
#include <fstream>

#include "shader.h"
#include "glad/glad.h"

namespace sap::gfx
{
    Shader::Shader(const std::string& vshFile, const std::string& fshFile):
    m_programID(0)
    {
        m_programID = glCreateProgram();
        unsigned int vsh = compileShader(vshFile, GL_VERTEX_SHADER);
        unsigned int fsh = compileShader(fshFile, GL_FRAGMENT_SHADER);
        linkShaders(vsh, fsh);
    }


    Shader::~Shader()
    {
        if(m_programID)
            glDeleteProgram(m_programID);
    }


    unsigned int Shader::compileShader(const std::string& sourceFile, int shaderType) const
    {
        std::ifstream inf{sourceFile.c_str()};

        if(!inf.is_open())
            std::cerr << "Failed to open file: " << sourceFile << std::endl;
        
        std::string strSrc{std::istreambuf_iterator<char>(inf),
                           std::istreambuf_iterator<char>()};
        
        inf.close();
                        
        const char* src = strSrc.c_str();

        unsigned int shaderID = glCreateShader(shaderType);
        glShaderSource(shaderID, 1, &src, nullptr);
        glCompileShader(shaderID);

        int success;
        char infoLog[512];
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

        if(!success)
        {
            glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
            std::cerr << "Failed to compile shader file: " << sourceFile << std::endl;
            std::cerr << "Info Log: " << infoLog << std::endl;
        }

        return shaderID;
    }


    void Shader::linkShaders(unsigned int vsh, unsigned int fsh) const
    {
        glAttachShader(m_programID, vsh);
        glAttachShader(m_programID, fsh);
        glLinkProgram(m_programID);

        int success;
        char infoLog[512];

        glGetProgramiv(m_programID, GL_LINK_STATUS, &success);

        if(!success)
        {
            glGetProgramInfoLog(m_programID, 512, nullptr, infoLog);
            std::cerr << "Failed to link shader program" << std::endl;
            std::cerr << "Info log: " << infoLog << std::endl;
        }

        glDetachShader(m_programID, vsh);
        glDetachShader(m_programID, fsh);
        glDeleteShader(vsh);
        glDeleteShader(fsh);
    }


    void Shader::bind() const
    {
        glUseProgram(m_programID);
    }


    void Shader::unbind() const
    {
        glUseProgram(0);
    }
}