#include "meta.hpp"

Meta::Meta(std::string id, std::string type, std::string name, std::string posterUrl, std::string description) {
    this->id = id;
    this->type = type;
    this->name = name;
    this->posterUrl = posterUrl;
    this->description = description;
}

std::string Meta::getId() {
    return id;
}

std::string Meta::getType() {
    return type;
}

std::string Meta::getName() {
    return name;
}

std::string Meta::getPosterUrl() {
    return posterUrl;
}

std::string Meta::getDescription() {
    return description;
}
