#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <utility>

#include <nlohmann/json.hpp>

#include "profiling/LoggerManager.h"

class DatenBank {
public:
    std::filesystem::path dbPath;

    DatenBank(std::filesystem::path path)
        : dbPath(std::move(path))
    {
        std::error_code ec;
        bool created = std::filesystem::create_directories(dbPath, ec);

        if (ec) {
            LOG_ERROR("Failed to create database directory: " + ec.message());
        } else if (created) {
            LOG_INFO("Database directory created at: " + dbPath.string());
        } else {
            LOG_INFO("Database directory already exists at: " + dbPath.string());
        }
    }

    bool save(const std::string& collection, const nlohmann::json& data) {
        std::filesystem::path collectionPath = dbPath / (collection + ".json");

        std::ofstream file(collectionPath);
        if (!file.is_open()) {
            LOG_ERROR("Failed to open file for writing: " + collectionPath.string());
            return false;
        }

        file << data.dump(4);

        if (!file.good()) {
            LOG_ERROR("Failed to write data to: " + collectionPath.string());
            return false;
        }

        LOG_INFO("Data saved to " + collectionPath.string());
        return true;
    }

    bool append(const std::string& collection, const nlohmann::json& data) {
        std::filesystem::path collectionPath = dbPath / (collection + ".json");

        std::ofstream file(collectionPath, std::ios::app);
        if (!file.is_open()) {
            LOG_ERROR("Failed to open file for appending: " + collectionPath.string());
            return false;
        }

        file << data.dump() << "\n";

        if (!file.good()) {
            LOG_ERROR("Failed to append data to: " + collectionPath.string());
            return false;
        }

        LOG_INFO("Data appended to " + collectionPath.string());
        return true;
    }

    [[nodiscard]] nlohmann::json load(const std::string& collection) const {
        std::filesystem::path collectionPath = dbPath / (collection + ".json");

        if (!std::filesystem::exists(collectionPath)) {
            LOG_ERROR("File existiert nicht: " + collectionPath.string());
            return nlohmann::json::object();
        }

        std::ifstream file(collectionPath);
        if (!file.is_open()) {
            LOG_ERROR("File is not open: " + collectionPath.string());
            return nlohmann::json::object();
        }

        nlohmann::json data;

        try {
            file >> data;
        } catch (const nlohmann::json::parse_error& e) {
            LOG_ERROR("Parser error in " + collection + ": " + std::string(e.what()));
            return nlohmann::json::object();
        }

        return data;
    }

    [[nodiscard]] nlohmann::json loadLines(const std::string& collection) const {
        std::filesystem::path collectionPath = dbPath / (collection + ".json");

        if (!std::filesystem::exists(collectionPath)) {
            LOG_ERROR("File existiert nicht: " + collectionPath.string());
            return nlohmann::json::array();
        }

        std::ifstream file(collectionPath);
        if (!file.is_open()) {
            LOG_ERROR("File is not open: " + collectionPath.string());
            return nlohmann::json::array();
        }

        nlohmann::json allData = nlohmann::json::array();
        std::string line;
        size_t lineNumber = 1;

        while (std::getline(file, line)) {
            if (line.empty()) {
                ++lineNumber;
                continue;
            }

            try {
                auto jsonLine = nlohmann::json::parse(line);
                allData.push_back(jsonLine);
            } catch (const nlohmann::json::parse_error& e) {
                LOG_ERROR("Parser error in " + collection + " auf Zeile " + std::to_string(lineNumber) + ": " + std::string(e.what()));
            }

            ++lineNumber;
        }

        return allData;
    }

    bool exists(const std::string& collection) const {
        std::filesystem::path collectionPath = dbPath / (collection + ".json");
        return std::filesystem::exists(collectionPath);
    }

    bool destroy(const std::string& collection) {
        std::filesystem::path collectionPath = dbPath / (collection + ".json");

        if (!std::filesystem::exists(collectionPath)) {
            return false;
        }

        std::error_code ec;
        bool deleted = std::filesystem::remove(collectionPath, ec);

        if (ec) {
            LOG_ERROR("Failed to delete collection: " + ec.message());
            return false;
        }

        if (deleted) {
            LOG_INFO("Collection deleted: " + collectionPath.string());
            return true;
        }

        return false;
    }
    bool remove()
};