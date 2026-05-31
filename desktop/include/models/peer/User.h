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
    std::vector<Contact> contacts;
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
    bool addToContacts(const Contact& contact){
        for(const auto& cont: contacts){
            if(cont.hasSameIdentityAs(contact)){
                return false;
            }
        }
        contacts.push_back(contact);
        return true;
    }
};