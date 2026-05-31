#pragma once

#include "models/key/PublicKey.h"
#include "models/key/PrivateKey.h"
namespace Crypto{
class KeyPair {
private:
    PublicKey publicKey;
    PrivateKey privateKey;

public:
    KeyPair(const PublicKey& publicKey, const PrivateKey& privateKey)
        : publicKey(publicKey),
          privateKey(privateKey)
    {}

    const PublicKey& getPublicKey() const {
        return publicKey;
    }

    const PrivateKey& getPrivateKey() const {
        return privateKey;
    }

    bool isComplete() const {
        return !publicKey.isEmpty() && !privateKey.isEmpty();
    }
};
}