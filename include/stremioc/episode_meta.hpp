#pragma once
#include <string>
#include <vector>

#include "metadata.hpp"

class EpisodeMeta : public Metadata {
public:
    EpisodeMeta();
    
    std::string getId() const override;
    std::string getName() const override;
    std::string getDescription() const override;
    std::string getOverview() const;
    std::string getThumbnailUrl() const;
    int getSeason() const;
    int getEpisode() const;


    void setId(const std::string& id);
    void setType(const std::string& type);
    void setName(const std::string& name);
    void setPosterUrl(const std::string& posterUrl);
    void setDescription(const std::string& description);
    void setYear(const std::string& year);
    void setBackgroundUrl(const std::string& backgroundUrl);
    void setLogoUrl(const std::string& logoUrl);
    void setGenres(const std::vector<std::string>& genres);