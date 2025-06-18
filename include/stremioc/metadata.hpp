#pragma once

#include <string>
#include <vector>

class Metadata{
public:
    virtual std::string getId() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string getName() const = 0;
    virtual std::string getPosterUrl() const = 0;
    virtual std::string getDescription() const = 0;
    virtual std::string getYear() const = 0;
    virtual std::string getBackgroundUrl() const = 0;
    virtual std::string getLogoUrl() const = 0;
    virtual std::vector<std::string> getGenres() const = 0;
};

