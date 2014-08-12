#pragma once

#include "ns.hpp"
#include "Logger.hpp"

#include <string>
#include <sstream>
#include <ostream>
#include <functional>
#include <ctime>

NOXIS_NS_BEGIN;

typedef std::function<std::string(const LogMessage&)> LogFormatter; 

class LogHandler {
    public:
        virtual void onMessage(const LogMessage &message) = 0;
        
        LogFormatter getFormatter() const;
        void setFormatter(LogFormatter formatter);

        virtual ~LogHandler();
    protected:
        LogFormatter formatter = [] (const LogMessage &message) {
            char time[10];
            std::strftime(time, sizeof(time), "%T", std::localtime(&message.time));

            std::stringstream ss;
            ss << "[" << time << "] [" << message.logger << "/" << logLevelToString(message.level) << "]: " << message.text;
            return ss.str();
        };
};

class StreamHandler : public LogHandler {
    public:
        StreamHandler(std::ostream &os);
        virtual void onMessage(const LogMessage &message) override;
        virtual ~StreamHandler();
    private:
        std::ostream &os;
};

NOXIS_NS_END;
