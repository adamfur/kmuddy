FROM ubuntu:16.04
#FROM ubuntu:latest

RUN apt update
RUN apt install -y cmake kdelibs5-dev libqt4-dev qt4-qmake g++ zlib1g-dev
RUN apt install -y clang
ADD . /work
WORKDIR /work
RUN cmake -DQT_QMAKE_EXECUTABLE=/usr/bin/qmake-qt4
RUN DESTDIR=deb/kmuddy/ make install -j$(nproc --all)
RUN dpkg-deb -z8 -Zgzip --build deb/kmuddy

# docker build -t kmuddy.deb .
# docker run -ti --rm -v /tmp:/tmp kmuddy.deb cp /work/deb/kmuddy.deb /tmp
