FROM ubuntu:24.04
RUN apt update
# RUN apt install -y nala
# RUN nala install -y cmake build-essential extra-cmake-modules qtbase5-dev qtscript5-dev qtmultimedia5-dev libkf5kio-dev libkf5parts-dev libkf5i18n-dev libkf5config-dev libkf5coreaddons-dev libkf5kdelibs4support-dev libkf5archive-dev libkf5xmlgui-dev libkf5parts-dev libkf5kcmutils-dev libecm-dev libecm1-dev
RUN apt install -y build-essential cmake extra-cmake-modules
RUN apt install -y qtbase5-dev
RUN apt install -y qtscript5-dev
RUN apt install -y qtmultimedia5-dev
RUN apt install -y libkf5kio-dev
RUN apt install -y libkf5parts-dev
RUN apt install -y libkf5i18n-dev
RUN apt install -y libkf5config-dev
RUN apt install -y libkf5coreaddons-dev
RUN apt install -y libkf5kdelibs4support-dev
RUN apt install -y libkf5archive-dev
RUN apt install -y libkf5xmlgui-dev
RUN apt install -y libkf5parts-dev
RUN apt install -y libkf5kcmutils-dev
# RUN apt install -y libecm-dev
# RUN apt install -y libecm1-dev


WORKDIR /work
ADD . .
RUN cmake .
RUN DESTDIR=deb/kmuddy/ make install -j$(nproc --all)
RUN dpkg-deb -z8 -Zgzip --build deb/kmuddy

# # docker build -t kmuddy.deb .
# # docker run -ti --rm -v /tmp:/tmp kmuddy.deb cp /work/deb/kmuddy.deb /tmp
