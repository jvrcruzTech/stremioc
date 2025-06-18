#pragma once

#include <stdio.h>
#include <string>
using namespace std;

class Logger {
    public:
        static void overrideLogger(void (*logFunction)(const std::string& message));

        static void error(const std::string& message);

        static void warning(const std::string& message);

        static void info(const std::string& message);

    private:
        static void (*logFunction)(const std::string& message);
        
};