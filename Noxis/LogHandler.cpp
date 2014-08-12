#include "LogHandler.hpp"

NOXIS_NS_BEGIN;

LogHandler::~LogHandler() {
    
}

LogFormatter LogHandler::getFormatter() const {
    return formatter;
}

void LogHandler::setFormatter(LogFormatter formatter) {
    this->formatter = formatter;
}

StreamHandler::StreamHandler(std::ostream &os) : LogHandler(), os(os) {

}

void StreamHandler::onMessage(const LogMessage &message) {
    os << formatter(message) << std::endl;    
}

StreamHandler::~StreamHandler() {

}

NOXIS_NS_END;
