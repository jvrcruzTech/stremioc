#pragma once

#include <curl/curl.h>
#include <string>
#include "logger.hpp"
#include "json.hpp"
#include "catalog.hpp"
#include "meta.hpp"
#include "stream.hpp"

using json = nlohmann::json;

class Addon {
    public:
        Addon(nlohmann::json manifest, std::string endpoint, std::string transport = "http");

        nlohmann::json getManifest() const;
        std::string getId() const;
        std::string getName() const;
        std::string getDescription() const;
        nlohmann::json getTypes() const;
        std::string getVersion() const;
        nlohmann::json getResources() const;
        nlohmann::json getIdPrefixes() const;
        std::string getEndpoint() const;

        Catalog getCatalog(const std::string type, const std::string id) const;
        list<Stream> getStream(const std::string type, const std::string id) const;
        Meta getMeta(const std::string type, const std::string id) const;
        nlohmann::json getSubtitles(const std::string type, const std::string id) const;

    private:
        nlohmann::json manifest;
        std::string addonEndpoint = "";
        std::string transport; // Default transport is HTTP
};