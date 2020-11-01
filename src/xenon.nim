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


when defined windows:
    const 
        cfgFolder: string = getConfigDir() & "xenon/"
        assetFolder: string = cfgFolder & "assets/"
else:
    const
        cfgFolder: string = getConfigDir() & "xenon\\"
        assetFolder: string = cfgFolder & "assets\\"
const startupprog: string = cfgFolder & "startup.exe"



proc init*(): void =
    #! C++ might burn your eyes
    #! 100% incompatible with win32
    var startup_cpp_code: string = """
            #include "webview.h"
            int main() {
                webview::webview w(true, nullptr);
                w.set_title("Xenon");
                w.set_size(1200, 1000, WEBVIEW_HINT_NONE);
                w.navigate("file://${assetFolder}home.html");
                w.run();
                return 0;
            }
            """.replace("${assetFolder}", assetFolder)
    when defined windows:
        startup_cpp_code = startup_cpp_code.replace("int main() {", "int WINAPI WinMain(HINSTANCE hInt, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {")
    echo "Initlizing... (this will show up only once)"
    writeFile(cfgFolder & "main.cpp", startupcppcode)
    when defined windows:
        const runcmd = "g++ " & cfgFolder & "main.cpp -mwindows -L./dll/x64 -lwebview -lWebView2Loader -o " & startupprog
    else:
        const runcmd = "g++ " & cfgFolder & "main.cpp `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0` -o "
    let compileExitCode = execShellCmd(runcmd)
    if compileExitCode != 0:
        echo "[FAILED] g++ compiler exited with exit code " & $compileExitCode & ", see above messages. **stop!!!"
        quit(2)
    removeFile cfgFolder & "main.cpp"
    echo "home page is at file://${assetFolder}home.html".replace("${assetFolder}", assetFolder)

proc main*(): void =
    if not existsFile startupprog:
        init()
    echo "Starting up..."
    discard execProcess startupprog


when isMainModule:
    main()
