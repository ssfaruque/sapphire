#ifndef LOGGER_H
#define LOGGER_H


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
        public:
            void log();
    };
}



#endif  // LOGGER_H