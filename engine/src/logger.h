#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace sap::dbg
{
    enum class LogLevel
    {
        INFO,
        WARNING,
        FATAL
    };

    class Logger
    {
        private:
            std::string m_loggerName;
            std::string m_logFileName;

        public:
            Logger(const std::string& loggerName, const std::string& logFileName):
            m_loggerName(loggerName), m_logFileName(logFileName)
            {

            }
            ~Logger() = default;

            template<typename ... Args>
            void log(const char* fmt, const Args &... args)
            {
                
            }
    };
}


#include "logger.cpp"

#endif  // LOGGER_H