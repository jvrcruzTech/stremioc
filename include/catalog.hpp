#pragma once

#include <curl/curl.h>
#include <string>
#include <list>
#include "logger.hpp"
#include "json.hpp"
#include "meta.hpp"


using json = nlohmann::json;
using namespace std;

class Catalog {
    public:
        Catalog(nlohmann::json catalogJson);

        list<Meta> getContent() const;
    private:
        list<Meta> content; // List of Meta objects representing the catalog content
};