// Copyright (c) 2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2020 The Ukcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/

#ifndef UKCCOIN_DARKSTYLE_H
#define UKCCOIN_DARKSTYLE_H

#include <QApplication>
#include <QProxyStyle>
#include <QStyleFactory>
#include <QFont>
#include <QFile>

class DarkStyle : public QProxyStyle
{
Q_OBJECT

public:
    DarkStyle();
    explicit DarkStyle(QStyle *style);

    QStyle *baseStyle() const;

    void polish(QPalette &palette) override;
    void polish(QApplication *app) override;

private:
    QStyle *styleBase(QStyle *style = Q_NULLPTR) const;
};

#endif //UKCCOIN_DARKSTYLE_H
