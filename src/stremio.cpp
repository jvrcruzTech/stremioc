#include "stremio.hpp"

void StremioUtils::login(const std::string& email, const std::string& password) {
    endpoint = "https://api.strem.io";
    std::string dbUrl = endpoint + "/api/login";
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        json data; 

        data["email"] = email;
        data["password"] = password;
        std::string postFields = data.dump();
        

        curl_easy_setopt(curl, CURLOPT_URL, dbUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nullptr);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK) {
            Logger::error("curl_easy_perform() failed");
            return;
        }
        json response = json::parse(readBuffer);

        response = response["result"];
        if (response.contains("authToken")) {
            authToken = response["authKey"];
            userJson = response["user"].dump();
            Logger::info("Login successful, authToken");
        } else {
            Logger::error("Login failed");
        }
    }
}

void StremioUtils::logout() {
    if (authToken.empty()) {
        Logger::warning("Not logged in, cannot logout.");
        return;
    }

    authToken.clear();
    userJson.clear();
    Logger::info("Logged out successfully.");
}

nlohmann::json StremioUtils::getAddonsFromDB() {
    endpoint = "https://api.strem.io";
    std::string dbUrl = endpoint + "/api/addonCollectionGet";
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    json addons;
    json data;
    data["authToken"] = authToken;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, dbUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nullptr);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK) {
            Logger::error("curl_easy_perform() failed");
            return addons;
        }
        json response = json::parse(readBuffer);
        addons = response["result"]["addons"];
        return addons;
    }
    return json::object({{"error", "Failed to initialize CURL"}});
}
