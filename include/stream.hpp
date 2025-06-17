#pragma once

#include <curl/curl.h>
#include <string>
#include "logger.hpp"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Stream {
    public:
        Stream(std::string contentId, string name, string description);


        std::string getContentId() const;
        std::string getUrl() const;
        std::string getName() const;
        std::string getInfoHash() const;
        int getFileIdx() const;
        std::string getDescription() const;
        json getBehaviorHints() const;
        string getType() const;

        void setUrl(const std::string& url);
        void setTorrent(const std::string& infoHash, int fileIndex = -1);
        void setBehaviorHints(const json& behaviorHints);

    private:
        std::string contentId; // Unique identifier for the content
        std::string url; // URL of the stream
        std::string infoHash; // Info hash for torrent streams
        int fileIndex; // Index of the file in a torrent (optional)
        std::string name;      // Name of the stream
        std::string description; // Description of the stream
        json behaviorHints; // Additional hints for the stream behavior
        
};