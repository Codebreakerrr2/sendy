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
        nlohmann::json userJson;
        userJson["displayName"] = user.getDisplayName();
        userJson["publicKey"] = user.getPublicKey().getEncoded();
        return db.save("user",userJson);
    }

    bool exists()  {
      return db.exists("user");
    }
    bool remove()  {
       return db.remove("user");
    }
};
}