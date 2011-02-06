/***************************************************************************
                          cvariable.h  -  one variable
                             -------------------
    begin                : Po sep 8 2003
    copyright            : (C) 2003-2008 by Tomas Mecir
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

#ifndef CVARIABLE_H
#define CVARIABLE_H

#include <kmuddy_export.h>

class cValue;

#include <QString>

/**
This class represents one variable.
  *@author Tomas Mecir
  */

class KMUDDY_EXPORT cVariable {
public: 
  cVariable ();
  ~cVariable ();

  QString name () { return _name; };
  /** sets new variable name; no duplicity check here - cVariableList must
  handle that */
  void setName (const QString &newname) { _name = newname; };
  cValue *getValue () { return val; };
  QString value ();
  void setValue (const QString &newvalue);
  void setValue (const cValue *v);
protected:
  QString _name;
  cValue *val;
};

#endif
