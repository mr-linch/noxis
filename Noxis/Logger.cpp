#include "Logger.hpp"
#include "LogHandler.hpp"

#include <iostream>
#include <cassert>

NOXIS_NS_BEGIN;

std::string logLevelToString(LogLevel level) {
    switch(level) {
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    };
}

LogLevel stringToLogLevel(const std::string &level) {
    if(level == "DEBUG") {
        return LogLevel::DEBUG;
    } else if(level == "INFO") {
        return LogLevel::INFO;
    } else if(level == "WARNING") {
        return LogLevel::WARNING;
    } else if(level == "ERROR") {
        return LogLevel::ERROR;
    } else {
        return LogLevel::DEFAULT;
    }
}

Logger::Logger(const std::string &name, LogLevel level) : name(name), level(level) {
    addHandler(new StreamHandler(std::clog));
}

const std::string& Logger::getName() const {
    return name;
}

void Logger::setName(const std::string &name) {
    this->name = name;
} 

LogLevel Logger::getLevel() const {
    return level;
}

void Logger::setLevel(LogLevel level) {
    this->level = level;
}

void Logger::addHandler(LogHandler *handler) {
    assert(handler != nullptr);
    handlers.push_back(handler); 
}

void Logger::removeHandler(LogHandler *handler) {
    assert(handler != nullptr);
    handlers.remove(handler); 
    delete handler;
}

void Logger::removeAllHandlers() {
    for(auto &handler : handlers) {
        delete handler;
        handler = nullptr;
    }    
    handlers.clear();
}

void Logger::sendToHandlers(const LogMessage &message) {
    for(auto handler : handlers) {
        handler->onMessage(message);
    }
}

void Logger::log(LogLevel level, const std::string &text) {
    if(level >= this->level) {
        LogMessage message;
        message.logger = name;
        message.text = text;
        message.level = level;
        message.time = time(nullptr);

        sendToHandlers(message);
    }
}

Logger& Logger::debug(const std::string &message) {
    log(LogLevel::DEFAULT, message);
    return *this;
}

Logger& Logger::info(const std::string &message) {
    log(LogLevel::INFO, message);
    return *this;
}

Logger& Logger::warning(const std::string &message) {
    log(LogLevel::WARNING, message);
    return *this;
}

Logger& Logger::error(const std::string &message) {
    log(LogLevel::ERROR, message);
    return *this;
}

Logger::~Logger() {
    removeAllHandlers();
}

NOXIS_NS_END;
