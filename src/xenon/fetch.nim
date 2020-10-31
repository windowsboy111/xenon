import os, osproc
# import httpclient
# import strformat
import common


proc dl_f(url: string, dest: string) =
    when defined win32:
        #% implement download for win32
        raise newException(NotImplemented, "Not Implemented for win32!")
    else:
        #% curl in posix
        let output: TaintedString = execProcess("curl", args=[url, "-o", dest, "-s", "-S"])
        if $output != "":
            #? process the error - NI
