#pragma once
#include "models/peer/Peer.h"
#include "models/key/KeyPair.h"
#include "models/Status.h"


    #include "models/peer/Contact.h"
    class User : public Peer {
    private:
        Crypto::PrivateKey privateKey;
        Crypto::PublicKey publicKey;
        Status::ConnectionStatus connectionStatus;

    public:
        User(
            const std::string& displayName,
            const  Crypto::PrivateKey privateKey,
            const Crypto::PublicKey publicKey,
            Status::PresenceStatus presenceStatus,
            Status::ConnectionStatus connectionStatus
        )
            : Peer(displayName, publicKey, presenceStatus),
              publicKey(publicKey),
               privateKey(privateKey),
              connectionStatus(connectionStatus)
        {}



        const Crypto::PrivateKey& getPrivateKey() const {
            return privateKey;
        }

        Status::ConnectionStatus getConnectionStatus() const {
            return connectionStatus;
        }

        void setConnectionStatus(Status::ConnectionStatus connectionStatus) {
            this->connectionStatus = connectionStatus;
        }

        const Crypto::PublicKey& getPublicKey() const {
            return publicKey;
        }


    };