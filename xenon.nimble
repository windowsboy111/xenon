# Package

version       = "0.1.0"
author        = "windowsboy111"
description   = "an efficient, simple, and elegant browser."
license       = "GPL-3.0"
srcDir        = "src"
bin           = @["xenon"]

backend       = "cpp"
# Dependencies

task assets, "Save assets to cfg folder":
    exec "nim -r c inst/mvassets.nim"

requires "nim >= 1.2.6", "Neel"
