#pragma once

#include <string>
#include <vector>
#include <list>

#include <curl/curl.h>

#include "logger.hpp"
#include "json.hpp"
#include "addon.hpp"
#include "catalog.hpp"
#include "stream.hpp"
#include "meta.hpp"
#include "playable.hpp"
#include "episode.hpp"
#include "episode_meta.hpp"
#include "manifest.hpp"
#include "addons.hpp"
#include "metadata.hpp"


using json = nlohmann::json;
using namespace std;

namespace stremioc
{
    StremioUtils;
    AddonCollection;

} // namespace stremioc
