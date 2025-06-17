#include "meta.hpp"

Meta::Meta(std::string id, std::string type, std::string name, std::string posterUrl, std::string description, nlohmann::json videos, std::string year, nlohmann::json genres, std::string backgroundUrl, std::string logoUrl) {
    this->id = id;
    this->type = type;
    this->name = name;
    this->posterUrl = posterUrl;
    this->description = description;
    this->videos = videos;
    this->year = year;
    this->genres = genres;
    this->backgroundUrl = backgroundUrl;
    this->logoUrl = logoUrl;
}

std::string Meta::getId() const {
    return id;
}

std::string Meta::getType() const {
    return type;
}

std::string Meta::getName() const {
    return name;
}

std::string Meta::getPosterUrl() const {
    return posterUrl;
}

std::string Meta::getDescription() const {
    return description;
}

std::string Meta::getYear() const {
    return year;
}

nlohmann::json Meta::getGenres() const {
    return genres;
}

std::string Meta::getBackgroundUrl() const {
    return backgroundUrl;
}

std::string Meta::getLogoUrl() const {
    return logoUrl;
}

nlohmann::json Meta::getVideos() const {
    return videos;
}