/*  This file is part of the KDE project
    Copyright (C) 2007-2008 Gökçen Eraslan <gokcen@pardus.org.tr>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public
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

#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <polkit/polkit.h>

#include <QtCore/QObject>

#include "ui_authdialogui.h"

class AuthDialog : public KDialog, public Ui::AuthDialogUI
{
public:
    AuthDialog( const QString &header, PolKitResult type);
    ~AuthDialog();
    void setType(PolKitResult type);
    void setContent(const QString &);
    void setContent();
    void setHeader(const QString &);

private:
    void showUsersCombo();
    void hideUsersCombo();
    void setPasswordFor(bool set, const QString& user = NULL);
    PolKitResult m_type;
};

#endif // AUTHDIALOG_H
