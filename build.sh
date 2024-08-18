#!/bin/bash

docker build -t kmuddy.deb . && \
    docker run -ti --rm -v $(pwd):/dest kmuddy.deb cp -v /work/deb/kmuddy.deb /dest
    
