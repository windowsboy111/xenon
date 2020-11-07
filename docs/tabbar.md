# How to implement ahhhhhhhhhh
- cls `windowhdl::TabsBar` of `Gtk::Box`
- dyn expand
- store content with sqlite3...?
## ctl
- press a btn or shortcut to open a new tab?
- pack_end() a btn? (but i don't think you can make an `x` btn on a btn)
## backend
- you append that into db
- then suck that btn into a C++ vector
- that vector is protected
## frontend
- clickable btn apparently
- need to change color when [in]active
- need to resize when bar is full (sizers)
