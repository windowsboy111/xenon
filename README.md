# Xenon
An efficient, simple, and elegant browser.

## Install
## Pre-Installation
- run `inst/mvassets.py` using python3; or
- move all the files from `assets/` to `%USERPROFILE%\.xenon\` or `~/.config/xenon/`
### Linux
- Xenon is precompiled. run with `./xenon`
- To compile, you will need to have `webkit2gtk-4.0` and `gtk+-3.0` installed, then run `./compile.sh`
### Windows
- There is little support on Windows, but AFAIK, you will also need `webkit2gtk-4.0` and `gtk+-3.0`. A compiler is also needed (`g++`).
- run `g++ -o xenon.exe src/xenon.cpp -std=c++17  -IC:\path\to\lib1 -IC:\path\to\lib2 -IC:\path\to\more\libs\etc`

## License
- GPLv3
