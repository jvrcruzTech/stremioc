#pragma once

#include <curl/curl.h>
#include <string>
#include <variant>
#include "logger.hpp"
#include "json.hpp"
using json = nlohmann::json;


class StremioUtils {
  public:
    static nlohmann::json getAddonsFromDB();
    static void login(const std::string& email, const std::string& password);
    static void logout();

  private:
    static std::string endpoint;
    static std::string authToken;
    static std::string userJson;
};