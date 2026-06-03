#pragma once
#include "repositories/Repo.h"
#include "datenbank/DatenBank.h"
#include "models/peer/User.h"
#include <nlohmann/json.hpp>

namespace Repositories {

class UserRepo  {


    DatenBank db{"desktop/db"};

    public:
    bool save(const User& user){    
        nlohmann::json userJson = getDBJson(user);
        return db.save("user",userJson);
    }

    bool exists()  {
      return db.exists("user");
    }
    bool remove()  {
       return db.destroy("user");
    }

    User get(const Crypto::PublicKey& pk) {
        nlohmann::json userJson = db.load("user");
        return  User(userJson.at("displayName"),
            Crypto::PrivateKey(userJson.at("publicKey")),
            Crypto::PublicKey(userJson.at("privateKey")),
            Status::PresenceStatus::Unknown,
            Status::ConnectionStatus::Unknown);
    }


    nlohmann::json getDBJson(const User& user) {
        nlohmann::json userJson;
        userJson["displayName"] = user.getDisplayName();
        userJson["publicKey"] = user.getPublicKey().getEncoded();
        userJson ["privateKey"] = user.getStatus();
        return userJson;
    }
};
}