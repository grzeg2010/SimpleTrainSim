/*
SimpleTrainSim - application immitating train HUD.
Copyright (C) 2026 Grzegorz Śnieżko

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef TRAIN_H
#define TRAIN_H

#include <QObject>
#include <QQmlEngine>
#include <QDebug>

class Train : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Train(QObject *parent = nullptr);

    Q_INVOKABLE void useHorn();

signals:
    void horn(QDateTime useTime);

private slots:
    void usedHorn(QDateTime useTime);
};

#endif // TRAIN_H
