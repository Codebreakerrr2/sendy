#pragma once

namespace Crypto {

enum class CryptoAlgorithm {
    UNKNOWN,
    ED25519,
    X25519,
    AES256,
    CHACHA20
};

enum class KeyType {
    PUBLIC,
    PRIVATE,
    SESSION
};

class Key {

    CryptoAlgorithm algorithm;
    KeyType type;

public:
    Key(CryptoAlgorithm algorithm, KeyType type)
        : algorithm(algorithm), type(type) {}

    virtual ~Key() = default;

    CryptoAlgorithm getAlgorithm() const {
        return algorithm;
    }

    KeyType getType() const {
        return type;
    }

    virtual bool isEmpty() const = 0;
};

}