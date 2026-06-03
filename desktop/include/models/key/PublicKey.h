#pragma once
#include "models/key/Key.h"
#include <string>
namespace Crypto{

class PublicKey : public Key{

    std::string encoded;
public:
   explicit  PublicKey(const std::string& encoded): Key(CryptoAlgorithm::X25519,KeyType::PUBLIC), encoded(encoded) {}

    bool isEmpty() const override {
        return encoded.empty();
    }
    std::string getEncoded() const{
        return encoded;
   }
    bool operator==(const PublicKey& other) const {
    return encoded == other.encoded;
}

};


}