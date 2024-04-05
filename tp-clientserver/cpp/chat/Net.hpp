#include <hv/WebSocketServer.h>

#include <list>
#include <thread>
#include <optional>

class Net {
    private:
        std::list<WebSocketChannelPtr> _channels;

        // pour gérer les noms de client :
        std::list<WebSocketChannelPtr> _pendings;
        std::map<WebSocketChannelPtr, std::string> _connections;

    public:
        Net() = default;
        Net(const Net &) = delete;

        void addPending(const WebSocketChannelPtr & c) {
            _pendings.push_front(c);
        }

        void delPending(const WebSocketChannelPtr & c) {
            auto it = std::find(_pendings.begin(), _pendings.end(), c);
            if (it != _pendings.end()) {
                _pendings.erase(it);
            }
        }

        void addConnection(const WebSocketChannelPtr & c, const std::string& n) {
            _connections[c] = n;
        }

        void delConnection(const WebSocketChannelPtr & c) {
            const auto connection = _connections.find(c);
            if (connection != _connections.end()) _connections.erase(c);

        }

        void map(std::function<void(const WebSocketChannelPtr &)> f) {
            for (const auto& [channel, name] : _connections)
                f(channel);
        }


        // pour gérer les noms de client :
        bool giveName(const WebSocketChannelPtr& c, const std::string& n) {
            for (const auto& [channel, name] : _connections)
                if (name == n) return false;

            delPending(c);
            addConnection(c, n);
            return true;
        }

        bool isPending(const WebSocketChannelPtr& c) const {
            auto it = std::find(_pendings.begin(), _pendings.end(), c);
            return it != _pendings.end();
        }

        std::optional<std::string> findName(const WebSocketChannelPtr& c) const {
            const auto connection = _connections.find(c);
            if (connection != _connections.end()) return std::optional<std::string>{ connection->second };
            else return std::nullopt;
        }
};

