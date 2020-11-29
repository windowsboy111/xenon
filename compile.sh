# This file is part of Xenon.
# 
# Xenon is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# Xenon is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with Xenon.  If not, see <https://www.gnu.org/licenses/>.

# g++ `pkg-config --libs webkit2gtk-4.0` `pkg-config --cflags webkit2gtk-4.0` `pkg-config --cflags gtkmm-3.0` `pkg-config --libs gtkmm-3.0` -std=c++17 src/{xenon,nav,winhdl,utils/{fsop,colors,console}}.cpp -o xenon -g
g++ `pkg-config --libs webkit2gtk-4.0` `pkg-config --cflags webkit2gtk-4.0` `pkg-config --cflags gtkmm-3.0` `pkg-config --libs gtkmm-3.0` -std=c++17 -g -c src/winhdl.cpp
# g++ `pkg-config --libs webkit2gtk-4.0` `pkg-config --cflags webkit2gtk-4.0` `pkg-config --cflags gtkmm-3.0` `pkg-config --libs gtkmm-3.0` -std=c++17 -g -c src/nav.cpp
# g++ `pkg-config --libs webkit2gtk-4.0` `pkg-config --cflags webkit2gtk-4.0` `pkg-config --cflags gtkmm-3.0` `pkg-config --libs gtkmm-3.0` -std=c++17 -g -c src/xenon.cpp
g++ `pkg-config --libs webkit2gtk-4.0` `pkg-config --cflags webkit2gtk-4.0` `pkg-config --cflags gtkmm-3.0` `pkg-config --libs gtkmm-3.0` -std=c++17 -g -o xenon *.o
