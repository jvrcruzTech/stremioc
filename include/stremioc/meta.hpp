#pragma once

#include "metadata.hpp"
#include <string>
#include <vector>


class Meta : public Metadata {
public:
    Meta();

    std::string getId() const override;
    std::string getType() const override;
    std::string getName() const override;
    std::string getPosterUrl() const override;
    std::string getDescription() const override;
    std::string getYear() const override;
    std::string getBackgroundUrl() const override;
    std::string getLogoUrl() const override;
    std::vector<std::string> getGenres() const override;
    std::vector<std::string> getEpisodes() const;

    void setId(const std::string& id);
    void setType(const std::string& type);
    void setName(const std::string& name);
    void setPosterUrl(const std::string& posterUrl);
    void setDescription(const std::string& description);
    void setYear(const std::string& year);
    void setBackgroundUrl(const std::string& backgroundUrl);
    void setLogoUrl(const std::string& logoUrl);
    void setGenres(const std::vector<std::string>& genres);
    void setEpisodes(const std::vector<std::string>& episodes);
private:
    std::string id;
    std::string type;
    std::string name;
    std::string posterUrl;
    std::string description;
    std::string year;
    std::string backgroundUrl;
    std::string logoUrl;
    std::vector<std::string> genres;
    std::vector<> episodes; // List of episode IDs
};