#ifndef QTGAMECLIENT_H
#define QTGAMECLIENT_H

#include <QObject>
#include <net/game/pnGameClient.h>

class qtVaultNode;

class qtGameClient : public QObject, public pnGameClient
{
    Q_OBJECT
private:
    hsUint32 fMcpId;
    hsTArray<unsigned int> fAgePlayers;
    qtVaultNode* fPlayerNode;
    qtVaultNode* fAgeInfoNode;

public:
    qtGameClient(QObject* parent = 0);
    ~qtGameClient();

    void setPlayer(qtVaultNode* player);
    void setAgeInfo(qtVaultNode* ageInfo);
    void joinAge(hsUint32 serverAddr, hsUint32 mcpId);
    void onPropagateMessage(plCreatable *msg);
    void onJoinAgeReply(hsUint32 transId, ENetError result);

public slots:
    void sendAgeChat(plString message);
    void sendBuddyBroadcast(plString message, QList<hsUint32> buddies);
    void sendPrivate(plString message, hsUint32 target);

signals:
    void receivedGameMsg(QString);
    void setMeOnline(hsUint32 player, plString ageFilename, plUuid ageUuid);
    void addAgePlayer(hsUint32, plString);
    void removeAgePlayer(hsUint32, plString);
    void clearAgeList();
};

#endif // QTGAMECLIENT_H
