#!/bin/bash

CHAT_FS_ROOT=$(dirname $(readlink -f "$0"))
echo 'CHAT_FS_ROOT: ' ${CHAT_FS_ROOT}
cd ${CHAT_FS_ROOT} || exit

if [ ! -d "cmake-build-debug" ]; then
    mkdir cmake-build-debug
fi

${CMAKE_PATH}/cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -S ${CHAT_FS_ROOT} -B cmake-build-debug


cd ${CHAT_FS_ROOT}/cmake-build-debug || exit
make -j10