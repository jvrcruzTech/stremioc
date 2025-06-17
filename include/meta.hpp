#pragma once

#include <curl/curl.h>
#include <string>
#include "logger.hpp"
#include "json.hpp"

using json = nlohmann::json;

class Meta {
    public:
        Meta(std::string id, std::string type, std::string name, std::string posterUrl, std::string description, nlohmann::json videos = json(), std::string year, nlohmann::json genres, std::string backgroundUrl);

        std::string getId();
        std::string getType();
        std::string getName();
        std::string getPosterUrl();
        std::string getDescription();
        json getVideos() const;
        std::string getYear() const;
        json getGenres() const;
        std::string getBackgroundUrl() const;


    private:
        std::string id;          // Unique identifier for the meta
        std::string type;        // Type of the meta (e.g., movie, series)
        std::string name;        // Name of the meta
        std::string posterUrl;   // URL to the poster image
        std::string description; // Description of the meta
        json videos;            // JSON object containing video information
        std::string year;          // Year of release 
        json genres;           // Genres associated with the meta 
        std::string backgroundUrl; // URL to the background image 

};