#pragma once

#include "connections-tree/operations.h"

class ItemOperationsMock : public ConnectionsTree::Operations {

public:

    DatabaseList databases;

    virtual void getDatabases(std::function<void(DatabaseList)> callback) {
        callback(databases);
    }

    RawKeysList keys;
    virtual void getDatabaseKeys(uint dbIndex, std::function<void(const RawKeysList&)> callback) {
        callback(keys);
    }

    virtual QSharedPointer<Console::Operations> getConsoleOperations()
    {
        return QSharedPointer<Console::Operations>();
    }

    QString namespaceSeparator = ":";
    QString getNamespaceSeparator() { return namespaceSeparator; }

    void disconnect() {}

    virtual void openKeyTab(const QString& fullPath, int dbIndex, bool openInNewTab) override {}
    virtual void openConsoleTab() override {}
};
