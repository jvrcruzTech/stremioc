#include "logger.hpp"
#include <cstdarg>

void Logger::overrideLogger(void (*logFunction)(const std::string& message)) {
    Logger::logFunction = logFunction;
}

void Logger::error(const std::string& message) {
    if (logFunction) {
        logFunction("ERROR: " + message);
    } else {
        fprintf(stderr, "ERROR: %s\n", message.c_str());
    }
}

void Logger::warning(const std::string& message) {
    if (logFunction) {
        logFunction("WARNING: " + message);
    } else {
        fprintf(stderr, "WARNING: %s\n", message.c_str());
    }
}

void Logger::info(const std::string& message) {
    if (logFunction) {
        logFunction(message);
    } else {
        fprintf(stdout, "%s\n", message.c_str());
    }
}
void (*Logger::logFunction)(const std::string& message) = nullptr; // Initialize static member