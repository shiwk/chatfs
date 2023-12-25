# chatfs


## Prerequisite

 OSXFuse envirment. With lastest version of [FUSE for OS X](https://osxfuse.github.io/) installed, you need set below environment variable:

 `export FUSE_INC_DIR={FUSE_HEADERS_DIR}`

 `FUSE_HEADERS_DIR` is where fuse headers are placed. MacFUSE installs a `fuse.pc` file in `/usr/local/lib/pkgconfig/` in which you can check for more details.

## Build & Clean

 `sh build.sh`
 `sh clean.sh`


## Limitations

Only Apple Silicon of MacOs would be considered (dev/test) for now.