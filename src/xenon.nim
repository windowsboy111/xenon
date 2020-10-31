## This file is part of Xenon.
## 
## Xenon is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## Xenon is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with Xenon.  If not, see <https://www.gnu.org/licenses/>.

import os, strutils, osproc


const 
    cfgFolder: string = getConfigDir() & "xenon/"
    assetFolder: string = cfgFolder & "assets/"
    #! C++ might burn your eyes
    #! 100% incompatible with win32
    startup_cpp_code: string = """
        #include "webview.h"
        int main() {
            webview::webview w(true, nullptr);
            w.set_title("Xenon");
            w.set_size(480, 320, WEBVIEW_HINT_NONE);
            w.navigate("file://${assetFolder}home.html");
            w.run();
            ////w.destroy();
            return 0;
        }
        """.replace("${assetFolder}", assetFolder)


proc init*(): void =
    echo "Initlizing... (this will shows up only once)"
    writeFile(cfgFolder & "main.cpp", startupcppcode)
    discard execShellCmd "g++ " & cfgFolder & "main.cpp `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0` -o " & cfgFolder & "startup"
    removeFile cfgFolder & "main.cpp"
    echo "home page is at file://${assetFolder}home.html".replace("${assetFolder}", assetFolder)

proc main*(): void =
    if not existsFile cfgFolder & "startup":
        init()
    echo "Starting up..."
    discard execProcess cfgFolder & "startup"


when defined windows:
    raise newException(OSError, "100% incompatible with win32 verified!!! :check:")

when isMainModule:
    main()
