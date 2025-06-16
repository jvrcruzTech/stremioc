#include "addons.hpp"

std::list<Addon> AddonCollection::addons;

Addon AddonCollection::getAddonFromId(const std::string& addonId) {
    if (addons.empty()) {
        bool success = updateAddonCollection();
        if (!success) {
            Logger::error("Failed to retrieve addons from the database.");
            return;
        }
    }
    
    for (const auto& addon : addons) {
        return addon;
    }
    
    return; // Return an empty object if not found
}

std::list<Addon> AddonCollection::getAddonsFromResource(const std::string& type) {
    if (addons.empty()) {
        bool success = updateAddonCollection();
        if (!success) {
            Logger::error("Failed to retrieve addons from the database.");
            return list<Addon>(); // Return an empty array if retrieval fails
        }
    }
    
    list<Addon> result = list<Addon>();
    for (const auto& addon : addons) {
        if (addon.getResources().contains(type)) {
            result.push_back(addon);
        }
    }
    
    return result;
}

std::list<Addon> AddonCollection::getAddons() {
    if (addons.empty()) {
        bool success = updateAddonCollection();
        if (!success) {
            Logger::error("Failed to retrieve addons from the database.");
            return list<Addon>(); // Return an empty array if retrieval fails
        }
    }
    
    return addons;
}

bool AddonCollection::updateAddonCollection() {
    json addonsJson = StremioUtils::getAddonsFromDB();

    if (addonsJson["error"].is_string()) {
        Logger::error("Error retrieving addons: %s", addonsJson["error"].get<std::string>().c_str());
        return false;
    }

    for (const auto& addonJson : addonsJson) {
        try {
            std::string transportUrl = addonJson["transportUrl"].get<std::string>();
            size_t pos = transportUrl.find("/manifest.json");

            std::string endpoint;
            if (pos == std::string::npos) {
                Logger::error("Invalid transport URL format: %s", transportUrl.c_str());
                continue; // Skip this addon if the URL is invalid
            } else {
                Logger::info("Found transport URL: %s", transportUrl.c_str());
                endpoint = transportUrl.erase(pos, std::string("/manifest.json").length());
            }

            Addon addon = Addon(addonJson["manifest"], endpoint, addonJson["transportName"].get<std::string>());
            addons.push_back(addon);
        } catch (const std::exception& e) {
            Logger::error("Failed to parse addon: %s", e.what());
            continue;
        }
    }
    return true;
}