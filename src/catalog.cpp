#include "catalog.hpp"

Catalog::Catalog(nlohmann::json catalogJson) {
    for (const auto& item : catalogJson["metas"]) {
        Meta meta(item["id"].get<std::string>(),
                  item["type"].get<std::string>(),
                  item["name"].get<std::string>(),
                  item["poster"].get<std::string>(),
                  item["description"].get<std::string>());
        content.push_back(meta);
    }
}

std::list<Meta> Catalog::getContent() const {
    return content;
}