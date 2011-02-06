/***************************************************************************
                          dlgdumpbuffer.h  -  Dump Buffer dialog
                             -------------------
    begin                : Pi feb 28 2003
    copyright            : (C) 2003 by Tomas Mecir
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

#ifndef DLGDUMPBUFFER_H
#define DLGDUMPBUFFER_H

#include <qwidget.h>
#include <kdialog.h>

class QCheckBox;
class QComboBox;
class KLineEdit;

/**
Dump Buffer dialog.
  *@author Tomas Mecir
  */

class dlgDumpBuffer : public KDialog {
   Q_OBJECT
public:
  dlgDumpBuffer (QWidget *parent=0);
  ~dlgDumpBuffer ();
  bool curPos ();
  QString fileName ();
  void setFileName (const QString &fName);
  int type ();
  void setType (int t);
protected slots:
  void browseFiles ();
  void updateFname (int option);
protected:
  QCheckBox *chkcurpos;
  QComboBox *ttype;
  KLineEdit *fname;
};

#endif
