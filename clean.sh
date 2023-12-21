#!/bin/bash

# clean targets
CHAT_FS_ROOT=$(dirname $(readlink -f "$0"))
echo 'CHAT_FS_ROOT: ' ${CHAT_FS_ROOT}

cd ${CHAT_FS_ROOT}/cmake-build-debug || exit
make clean

# clean cmake stuff
cd ${CHAT_FS_ROOT}
rm -rf cmake-build-debug/
