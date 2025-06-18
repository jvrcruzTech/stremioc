#pragma once

#include "meta.hpp"
#include "stream.hpp"

class Playable {
public:
    virtual ~Playable() = default;

    virtual vector<Stream> getStreams() const = 0;
    virtual Meta getMeta() const = 0;
    virtual string getId() const = 0;
    virtual string getType() const = 0;


};
