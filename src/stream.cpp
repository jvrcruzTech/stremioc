#include "stream.hpp"

Stream::Stream(std::string name, std::string description) {
    this->name = name;
    this->description = description;
}

void Stream::setUrl(const std::string& url) {
    this->url = url;
}

void Stream::setTorrent(const std::string& infoHash, int fileIndex) {
    this->infoHash = infoHash;
    this->fileIndex = fileIndex;
}

void Stream::setBehaviorHints(const json& behaviorHints) {
    this->behaviorHints = behaviorHints;
}

std::string Stream::getUrl() const {
    return url;
}

std::string Stream::getName() const {
    return name;
}

std::string Stream::getDescription() const {
    return description;
}

json Stream::getBehaviorHints() const {
    return behaviorHints;
}

std::string Stream::getInfoHash() const {
    return infoHash;
}

int Stream::getFileIdx() const {
    if (fileIndex < 0) {
        return; // Return void if fileIndex is not set
    }
    return fileIndex;
}
