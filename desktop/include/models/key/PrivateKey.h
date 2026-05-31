#pragma once

#include <string>
#include "models/key/Key.h"
namespace Crypto{
class PrivateKey : public Key {
private:
    std::string encoded;

public:
    explicit PrivateKey(const std::string& encoded): Key(CryptoAlgorithm::X25519,KeyType::PRIVATE),
          encoded(encoded)
    {}

    const std::string& getEncoded() const {
        return encoded;
    }

    bool isEmpty() const override {
        return encoded.empty();
    }
};
}