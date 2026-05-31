#pragma once

namespace Status {
enum class ConnectionStatus {
    Connected,
    Disconnected,
    Connecting,
    Disconnecting
};


enum class PresenceStatus {
    Online,
    Offline,
    Away,
    DoNotDisturb
};

enum class TransferStatus {
    NotStarted,
    InProgress,
    Completed,
    Failed
};

}