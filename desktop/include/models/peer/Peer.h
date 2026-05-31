#pragma once

#include <string>

#include "models/key/PublicKey.h"
#include "models/Status.h"

class Peer {
private:
    std::string displayName;
    Crypto::PublicKey publicKey;
    Status::PresenceStatus status;

public:
    Peer(
        const std::string& displayName,
        const Crypto::PublicKey& publicKey,
        Status::PresenceStatus status
    )
        : displayName(displayName),
          publicKey(publicKey),
          status(status)
    {}

    const std::string& getDisplayName() const {
        return displayName;
    }

    const Crypto::PublicKey& getPublicKey() const {
        return publicKey;
    }

    Status::PresenceStatus getStatus() const {
        return status;
    }

    void setDisplayName(const std::string& displayName) {
        this->displayName = displayName;
    }

    void setStatus(Status::PresenceStatus status) {
        this->status = status;
    }
};