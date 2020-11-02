g++ -o xenon src/xenon.cpp `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0` `pkg-config --libs webkit2gtk-4.0` `pkg-config --cflags webkit2gtk-4.0` -std=c++17
