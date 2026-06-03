#pragma once

namespace Status {
enum class ConnectionStatus {
    Unknown,
    Connected,
    Disconnected,
    Connecting,
    Disconnecting
};


enum class PresenceStatus {
    Unknown,
    Online,
    Offline,
    Away,
    DoNotDisturb
};

enum class TransferStatus {
    Unknown,
    NotStarted,
    InProgress,
    Completed,
    Failed
};

}