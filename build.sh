#!/bin/bash

CHAT_FS_ROOT=$(dirname $(readlink -f "$0"))
cd ${CHAT_FS_ROOT} || exit

if [ ! -d "cmake-build-debug" ]; then
    mkdir cmake-build-debug
fi

FUSE_CFLAGS=`pkg-config fuse --cflags-only-other`
echo 'CFLAGS:' ${FUSE_CFLAGS}
FUSE_INC=`pkg-config fuse --cflags-only-I`
echo 'FUSE_INC:' ${FUSE_INC}
FUSE_LIB=`pkg-config fuse --libs-only-L`
echo 'FUSE_LIB:' ${FUSE_LIB}

${CMAKE_PATH}/cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -S ${CHAT_FS_ROOT} -B cmake-build-debug  -DCMAKE_CXX_FLAGS="${FUSE_INC} ${FUSE_CFLAGS} ${FUSE_LIB} " 


cd ${CHAT_FS_ROOT}/cmake-build-debug || exit
make -j10