
#include "addon.hpp"

Addon::Addon(nlohmann::json manifest, std::string endpoint, std::string transport) {
    this->manifest = manifest;
    this->addonEndpoint = endpoint;
    this->transport = transport;
}

nlohmann::json Addon::getManifest() const {
    return manifest;
}

std::string Addon::getId() const {
    return manifest["id"].get<std::string>();
}

std::string Addon::getName() const {
    return manifest["name"].get<std::string>();
}

std::string Addon::getDescription() const {
    return manifest["description"].get<std::string>();
}

nlohmann::json Addon::getTypes() const {
    return manifest["types"];
}

std::string Addon::getVersion() const {
    return manifest["version"].get<std::string>();
}

nlohmann::json Addon::getResources() const {
    return manifest["resources"];
}

nlohmann::json Addon::getIdPrefixes() const {
    return manifest["idPrefixes"];
}

std::string Addon::getEndpoint() const {
    return addonEndpoint;
}

Catalog Addon::getCatalog(const std::string type, const std::string id) const {
    if (transport != "http") {
        Logger::error("Unsupported transport: %s", transport.c_str());
        return; // Return an empty Catalog object
    }
    std::string url = addonEndpoint + "/catalog/" + type + "/" + id + ".json";

    CURL* curl = curl_easy_init();

}

list<Stream> Addon::getStream(const std::string type, const std::string id) const {

    if (transport != "http") {
        Logger::error("Unsupported transport: %s", transport.c_str());
        return list<Stream>(); // Return an empty list of Stream objects
    }

    std::string url = addonEndpoint + "/stream/" + type + "/" + id + ".json";

    CURL* curl = curl_easy_init();
    if (!curl) {
        Logger::error("Failed to initialize CURL for fetching stream data.");
        return list<Stream>(); // Return an empty Stream object
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    std::string readBuffer;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nullptr);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if (res != CURLE_OK) {
        Logger::error("curl_easy_perform() failed: %s", curl_easy_strerror(res));
        return list<Stream>(); // Return an empty Stream object
    }

    nlohmann::json response = nlohmann::json::parse(readBuffer);
    nlohmann::json streamsData = response["streams"];

    list<Stream> streams;
    for (const auto& stream : streamsData) {
        Stream streamObj = Stream(
            stream["name"].get<std::string>(),
            stream["description"].get<std::string>()
        );

        if (stream.contains("url")) {
            streamObj.setUrl(stream["url"].get<std::string>());
        }

        if (stream.contains("infoHash")) {
            streamObj.setTorrent(stream["infoHash"].get<std::string>(), stream["fileIdx"].get<int>());
        }
        streams.push_back(streamObj);
    }
    return streams;

}

Meta Addon::getMeta(const std::string type, const std::string id) const {
    if (transport != "http") {
        Logger::error("Unsupported transport: %s", transport.c_str());
        return; // Return an empty Meta object
    }

    std::string url = addonEndpoint + "/meta/" + type + "/" + id + ".json";

    CURL* curl = curl_easy_init();
    if (!curl) {
        Logger::error("Failed to initialize CURL for fetching meta data.");
        return Meta("", "", "", "", ""); // Return an empty Meta object
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    std::string readBuffer;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nullptr);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if (res != CURLE_OK) {
        Logger::error("curl_easy_perform() failed: %s", curl_easy_strerror(res));
        return Meta("", "", "", "", ""); // Return an empty Meta object
    }

    nlohmann::json response = nlohmann::json::parse(readBuffer);
    nlohmann::json metaData = response["meta"];
    if (metaData.is_null()) {
        Logger::error("No meta data found for type: %s, id: %s", type.c_str(), id.c_str());
        return Meta("", "", "", "", ""); // Return an empty Meta object
    }

    return Meta(
        metaData["id"].get<std::string>(),
        metaData["type"].get<std::string>(),
        metaData["name"].get<std::string>(),
        metaData["poster"].get<std::string>(),
        metaData["description"].get<std::string>()
    );
}

nlohmann::json Addon::getSubtitles(const std::string type, const std::string id) const {
    std::string url = addonEndpoint + "/subtitle/" + type + "/" + id + ".json";
    // Implement the HTTP GET request to fetch the subtitles
    // This is a placeholder; actual implementation will depend on your HTTP client library
    return nlohmann::json(); // Return the fetched subtitles as a JSON object
}