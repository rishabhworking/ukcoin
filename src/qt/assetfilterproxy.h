// Copyright (c) 2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2020 The Ukcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef UKCCOIN_ASSETFILTERPROXY_H
#define UKCCOIN_ASSETFILTERPROXY_H

#include <QSortFilterProxyModel>

class AssetFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit AssetFilterProxy(QObject *parent = 0);

    void setAssetNamePrefix(const QString &assetNamePrefix);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex & source_parent) const;

private:
    QString assetNamePrefix;
};


#endif //UKCCOIN_ASSETFILTERPROXY_H
