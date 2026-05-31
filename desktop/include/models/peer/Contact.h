#pragma once

#include "models/peer/Peer.h"

class Contact : public Peer {
public:
    Contact(
        const std::string& displayName,
        const Crypto::PublicKey& publicKey,
        Status::PresenceStatus status
    )
        : Peer(displayName, publicKey, status)
    {}
    bool hasSameIdentityAs(const Contact& other) const{
       return getPublicKey() == other.getPublicKey();
    }
};