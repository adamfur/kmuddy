//
// C++ Interface: cstatusvareditor
//
// Description: 
//
/*
Copyright 2002-2011 Tomas Mecir <kmuddy@kmuddy.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of 
the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CSTATUSVAREDITOR_H
#define CSTATUSVAREDITOR_H

#include <clisteditor.h>


class cStatusVarEditor : public cListEditor {
 Q_OBJECT
 public:
  cStatusVarEditor (QWidget *parent);
  ~cStatusVarEditor () override;

  void createGUI(QWidget *parent) override;
  void fillGUI (const cListObjectData &data) override;
  void getDataFromGUI (cListObjectData *data) override;
 protected:
  struct Private;
  Private *d;
};

#endif  // CSTATUSVAREDITOR_H
