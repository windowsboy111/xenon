import os
createDir(getConfigDir() & "/xenon/assets")
copyDir(getCurrentDir() & "/assets", getConfigDir() & "/xenon/assets")
copyFile(getCurrentDir() & "/src/webview.h", getConfigDir() & "/xenon/webview.h")
