/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Designer of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef BUDDYEDITOR_PLUGIN_H
#define BUDDYEDITOR_PLUGIN_H

#include "buddyeditor_global.h"

#include <QtDesigner/QDesignerFormEditorPluginInterface>

#include <QtCore/QPointer>
#include <QtCore/QHash>

QT_BEGIN_NAMESPACE

class QDesignerFormWindowInterface;
class QAction;

namespace qdesigner_internal {

class BuddyEditorTool;

class QT_BUDDYEDITOR_EXPORT BuddyEditorPlugin: public QObject, public QDesignerFormEditorPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerFormEditorPluginInterface)
public:
    BuddyEditorPlugin();
    virtual ~BuddyEditorPlugin();

    virtual bool isInitialized() const;
    virtual void initialize(QDesignerFormEditorInterface *core);
    QAction *action() const;

    virtual QDesignerFormEditorInterface *core() const;

public slots:
    void activeFormWindowChanged(QDesignerFormWindowInterface *formWindow);

private slots:
    void addFormWindow(QDesignerFormWindowInterface *formWindow);
    void removeFormWindow(QDesignerFormWindowInterface *formWindow);

private:
    QPointer<QDesignerFormEditorInterface> m_core;
    QHash<QDesignerFormWindowInterface*, BuddyEditorTool*> m_tools;
    bool m_initialized;
    QAction *m_action;
};

}  // namespace qdesigner_internal

QT_END_NAMESPACE

#endif // BUDDYEDITOR_PLUGIN_H
