#!/bin/bash

docker build -t kmuddy.deb . && \
    docker run -ti --rm -v $(pwd):/dest kmuddy.deb cp /work/deb/kmuddy.deb /dest
    