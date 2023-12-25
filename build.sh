#!/bin/bash

CHAT_FS_ROOT=$(dirname $(readlink -f "$0"))
echo 'CHAT_FS_ROOT: ' ${CHAT_FS_ROOT}
echo 'FUSE_INC_DIR: ' ${FUSE_INC_DIR}

if [ -z ${FUSE_INC_DIR} ]; then
    echo '[STOPED] FUSE_INC_DIR is not set.'
    exit 1
fi
cd ${CHAT_FS_ROOT} || exit

if [ ! -d "cmake-build-debug" ]; then
    mkdir cmake-build-debug
fi

${CMAKE_PATH}/cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -S ${CHAT_FS_ROOT} -B cmake-build-debug -DFUSE_INC_DIR=${FUSE_INC_DIR} -DCMAKE_CXX_FLAGS="-D_FILE_OFFSET_BITS=64"


cd ${CHAT_FS_ROOT}/cmake-build-debug || exit
make -j10