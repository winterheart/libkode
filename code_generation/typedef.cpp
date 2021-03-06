/*
    This file is part of KDE.

    Copyright (c) 2004 Cornelius Schumacher <schumacher@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include <QtCore/QString>

#include "typedef.h"

using namespace KODE;

class Typedef::Private
{
public:
    QString mType;
    QString mAlias;
};

Typedef::Typedef() : d(new Private) {}

Typedef::Typedef(const Typedef &other) : d(new Private)
{
    *d = *other.d;
}

Typedef::Typedef(const QString &type, const QString &alias) : d(new Private)
{
    d->mType = type;
    d->mAlias = alias;
}

Typedef::~Typedef()
{
    delete d;
}

Typedef &Typedef::operator=(const Typedef &other)
{
    if (this == &other)
        return *this;

    *d = *other.d;

    return *this;
}

QString Typedef::declaration() const
{
    return QLatin1String("typedef ") + d->mType + QLatin1Char(' ') + d->mAlias + QLatin1Char(';');
}
