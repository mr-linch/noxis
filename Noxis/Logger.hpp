#pragma once

#include "ns.hpp"

#include <list>
#include <string>
#include <ctime>

NOXIS_NS_BEGIN;

class Logger;
class LogHandler;

enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    DEFAULT = INFO
};

/**
 * @brief Convert LogLevel to string
 * @param level log level
 * @return string
 */
std::string logLevelToString(LogLevel level);

/**
 * @brief Convert string to LogLevel
 */
LogLevel stringToLogLevel(const std::string &level);

struct LogMessage {
    std::string logger;
    LogLevel level;
    std::string text;
    std::time_t time;
};

class Logger {
    public:
        /**
         * @brief Create logger with specific name
         */
        Logger(const std::string &name, LogLevel level = LogLevel::DEFAULT);
        
        /**
         * @brief Get logger name
         */
        const std::string& getName() const;

        /**
         * @brief Set logger name
         */
        void setName(const std::string &name);

        /**
         * @brief Get current minimum level
         */
        LogLevel getLevel() const;

        /**
         * @brief Set minimum level
         */
        void setLevel(LogLevel level);
        
        /**
         * @brief Add handler
         */
        void addHandler(LogHandler *handler);

        /**
         * @brief Remove handler
         */
        void removeHandler(LogHandler *handler);

        /**
         * @brief Remove all handler
         */
        void removeAllHandlers();
        
        void log(LogLevel level, const std::string &message);
        
        /**
         * @brief Write message with debug level
         */
        Logger& debug(const std::string &message);
        
        /**
         * @brief Write message with info level
         */
        Logger& info(const std::string &message);
        
        /**
         * @brief Write message with warning level
         */
        Logger& warning(const std::string &message);

        /**
         * @brief Write message with error level
         */
        Logger& error(const std::string &message);
        
        virtual ~Logger();

    private:
        void sendToHandlers(const LogMessage &message);

        std::string name;
        LogLevel level;
        std::list<LogHandler*> handlers;
};

NOXIS_NS_END;
