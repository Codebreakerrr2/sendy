#pragma once
#include "datenbank/DatenBank.h"
#include "models/peer/Contact.h"

namespace Repositories {
    class ContactRepo {

        DatenBank db{"desktop/db"};
    public:
        bool save(const Contact& contact) {
            nlohmann::json contacts = db.loadLines("contacts");
            nlohmann::json contactJson = getDBJson(contact);
            if (!contacts.contains(contactJson)) {
                return db.append("contacts", contactJson);
            }
            return true;
        }

        bool exists(const Contact& contact) {
            nlohmann::json contacts = db.loadLines("contacts");
            nlohmann::json contactJson = getDBJson(contact);
             return (contacts.contains(contactJson)) ;
        }

        nlohmann::json getAll(){
            return db.loadLines("contacts");
        }
        nlohmann::json remove(const Contact& contact) {
            nlohmann::json contacts = db.loadLines("contacts");
            nlohmann::json contactJson = getDBJson(contact);
            if (contacts.contains(contactJson)) {
                return db.remove("contacts", contactJson);
            }
            return false;
        }

        nlohmann::json getDBJson(const Contact& contact){
            nlohmann::json contactJson;
            contactJson["displayName"] = contact.getDisplayName();
            contactJson["publicKey"] = contact.getPublicKey().getEncoded();
            return contactJson;
        }


    };
}
