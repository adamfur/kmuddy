/***************************************************************************
                          dlgquickconnect.cpp  -  QuickConnect dialog
    This file is a part of KMuddy distribution.
                             -------------------
    begin                : �t Jul 23 2002
    copyright            : (C) 2002 by Tomas Mecir
    email                : kmuddy@kmuddy.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "dlgquickconnect.h"

//needed by gcc 3.2
#define max(a,b) (((a) >= (b)) ? (a) : (b))

#include <qlabel.h>
#include <QGridLayout>

#include <klocale.h>
#include <klineedit.h>
#include <krestrictedline.h>

dlgQuickConnect::dlgQuickConnect(QWidget *parent) : KDialog (parent)
{
  //initial dialog size
  setInitialSize (QSize (300, 120));
  setCaption (i18n ("Quick Connect"));
  setButtons (KDialog::Ok | KDialog::Cancel);

  //create main dialog's widget
  QWidget *page = new QWidget (this);
  QGridLayout *layout = new QGridLayout (page);
  
  setMainWidget (page);
  
  //put some edit boxes there
  QLabel *l1 = new QLabel (i18n ("&Host:"), page);
  ed1 = new KLineEdit (page);
  QLabel *l2 = new QLabel (i18n ("&Port:"), page);
  ed2 = new KRestrictedLine (page);
  ed2->setValidChars ("0123456789");
  int w = max (l1->width(), l2->width());
  l1->setFixedWidth (w);
  l2->setFixedWidth (w);
  ed1->setGeometry (ed1->x(), ed1->y(), 200, ed1->height());
  ed2->setFixedWidth (80);

  l1->setBuddy (ed1);
  l2->setBuddy (ed2);
  
  layout->addWidget (l1, 0, 0);
  layout->addWidget (l2, 1, 0);
  layout->addWidget (ed1, 0, 1);
  layout->addWidget (ed2, 1, 1);

  //update button text
  setButtonText (KDialog::Ok, i18n ("&Connect"));
  setButtonToolTip (KDialog::Ok, i18n ("Establishes connection with specified parameters."));

  //humm, this one seems to be causing some X Error 42 BadMatch...
  //I have no idea why does it happen; however, everything seems
  //to be working perfectly...
  ed1->setFocus ();
}

dlgQuickConnect::~dlgQuickConnect()
{
  //all widgets are destroyed in Qt's destructors, so we needn't care about it

}

QString dlgQuickConnect::host ()
{
  return ed1->text();
}

int dlgQuickConnect::port ()
{
  return ed2->text().toInt ();
}

#include "dlgquickconnect.moc"

