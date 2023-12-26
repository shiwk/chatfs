# chatfs


## Prerequisite

 It is totally based on OSXFuse envirment. With lastest version of [FUSE for OS X](https://osxfuse.github.io/) installed, 
 
`fuse.pc` file placed in `/usr/local/lib/pkgconfig/` tells more details about `cflags`.

 `pkg-config fuse --cflags --libs`

## Build & Clean

 `sh build.sh`
 
 `sh clean.sh`


## Limitations

Only Apple Silicon of MacOS would be considered (dev/test) for now.
