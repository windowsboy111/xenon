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

import times
let time_startup = getTime()

import neel
import os
import httpclient


exposeProcs:
    proc postLoad() =
        stdout.write "Xenon started up in " & $((getTime() - time_startup).inMilliseconds) & "ms.\n"
    proc switchUrl(url: string) =
        var tmpdir = os.getTempDir()
        # pass it to curl and dl? (import fetch?)



startApp(startURL="home.html", assetsDir="./assets/", position=[100,100], size=[1250, 800], chromeFlags= @["--force-dark-mode"], appMode=true)
