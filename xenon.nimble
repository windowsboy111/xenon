# Package

version       = "0.1.0"
author        = "windowsboy111"
description   = "an efficient, simple, and elegant browser."
license       = "GPL-3.0"
srcDir        = "src"
bin           = @["xenon"]

backend       = "cpp"
# Dependencies

requires "nim >= 1.2.6", "Neel"
