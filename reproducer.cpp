#include <shared_mutex>

namespace ClientManager
{

class Client
{
private:
    bool _procRegistered, _netRegistered;
    mutable std::shared_mutex _procMutex;
    mutable std::shared_mutex _netMutex;
public:
    bool isProcRegistered() const;
    bool isNetRegistered() const;
    bool isUnregistering() const;
    bool handleNotifStream();
};

}

bool ClientManager::Client::isProcRegistered() const
{
    std::shared_lock<std::shared_mutex> lock(_procMutex);
    return _procRegistered;
}

bool ClientManager::Client::isNetRegistered() const
{
    std::shared_lock<std::shared_mutex> lock(_netMutex);
    return _netRegistered;
}

bool ClientManager::Client::isUnregistering() const
{
    return !isProcRegistered() || !isNetRegistered();
}

bool ClientManager::Client::handleNotifStream()
{
    if (!isNetRegistered())
    {
    }
    if (!isUnregistering())
    {
    }
    return true;
}
