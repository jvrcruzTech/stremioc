#pragma once

#include <curl/curl.h>
#include <string>
#include <list>
#include "logger.hpp"

#include "json.hpp"
#include "addon.hpp"
#include "stremio.hpp"

using namespace std;
using json = nlohmann::json;

class AddonCollection {
    public:
        static Addon getAddonFromId(const std::string& addonId);
        static std::list<Addon> getAddonsFromResource(const std::string& type);
        static std::list<Addon> getAddons();
        static bool updateAddonCollection();
        
    private:
        static std::list<Addon> addons;

};