    #pragma once
    #include <vector>
    #include "models/peer/Peer.h"
    #include "models/key/KeyPair.h"
    #include "models/Status.h"
    #include "models/peer/Contact.h"
    class User : public Peer {
    private:
        Crypto::KeyPair keyPair;
        Status::ConnectionStatus connectionStatus;

    public:
        User(
            const std::string& displayName,
            const Crypto::KeyPair& keyPair,
            Status::PresenceStatus presenceStatus,
            Status::ConnectionStatus connectionStatus
        )
            : Peer(displayName, keyPair.getPublicKey(), presenceStatus),
              keyPair(keyPair),
              connectionStatus(connectionStatus)
        {}

        const Crypto::KeyPair& getKeyPair() const {
            return keyPair;
        }

        const Crypto::PrivateKey& getPrivateKey() const {
            return keyPair.getPrivateKey();
        }

        Status::ConnectionStatus getConnectionStatus() const {
            return connectionStatus;
        }

        void setConnectionStatus(Status::ConnectionStatus connectionStatus) {
            this->connectionStatus = connectionStatus;
        }


    };