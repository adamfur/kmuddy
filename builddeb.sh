#!/bin/bash

cmake -DQT_QMAKE_EXECUTABLE=/usr/bin/qmake-qt4
DESTDIR=deb/kmuddy/ make install -j8
dpkg-deb -z8 -Zgzip --build deb/kmuddy
