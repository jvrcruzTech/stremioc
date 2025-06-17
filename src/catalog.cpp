#include "catalog.hpp"

Catalog::Catalog(nlohmann::json catalogJson) {
    for (const auto& item : catalogJson["metas"]) {
        if (item["type"].get<std::string>() != "movie" && item["type"].get<std::string>() != "series") {
            continue; // Skip items that are not movies or series
        }

        Meta meta(item.value("id", std::string()),
                  item.value("type", std::string()),
                  item.value("name", std::string()),
                  item.value("poster", std::string()),
                  item.value("description", std::string()),
                  item.value("videos", nlohmann::json()),
                  item.value("year", std::string()),
                  item.value("genres", nlohmann::json()));
                  
        content.push_back(meta);
    }
}

std::list<Meta> Catalog::getContent() const {
    return content;
}