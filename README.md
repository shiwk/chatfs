# chatfs


## Prerequisite

 It is totally based on OSXFuse envirment. With lastest version of [FUSE for OS X](https://osxfuse.github.io/) installed, `fuse.pc` file placed in `/usr/local/lib/pkgconfig/` tells more details about `cflags`.

 `pkg-config fuse --cflags --libs`

 And else, [nlohmann/json](https://github.com/nlohmann/json?tab=readme-ov-file#external) is used for chating request/response post data parsing. Make sure it has been installed.

## Build & Clean

 `sh build.sh`
 
 `sh clean.sh`

## Chat 

<video src="https://github.com/shiwk/chatfs/blob/main/screen_cap.mp4" width="500" height="300" /> 

## Limitations

Only Apple Silicon of MacOS would be considered (dev/test) for now.
