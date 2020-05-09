// Copyright (c)  The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2020 The Ukcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef UKC_QT_UKCADDRESSVALIDATOR_H
#define UKC_QT_UKCADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class UkcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit UkcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Ukcoin address widget validator, checks for a valid ukcoin address.
 */
class UkcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit UkcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // UKC_QT_UKCADDRESSVALIDATOR_H
