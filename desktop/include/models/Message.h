#pragma once
#include <string>

class Message {
    std::string content;
    std::string sender;
    std::string timestamp;
    std::string recipient;

    public:
    Message(const std::string& content, const std::string& sender, const std::string& timestamp, const std::string& recipient)
        : content(content), sender(sender), timestamp(timestamp), recipient(recipient) {}
    std::string getRecipient() const { return recipient; }
    std::string getContent() const { return content; }
    std::string getSender() const { return sender; }
    std::string getTimestamp() const { return timestamp; }
};