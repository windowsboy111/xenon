/*
 * This file is part of Xenon.
 *
 * Xenon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Xenon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Xenon.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "winhdl.h"

windowhdl::MainWin::MainWin() : Gtk::Window()
{
    this->set_default_size(1600, 900);
    this->init_webview();
    this->add(this->tabsBar);
    this->show_all();
}

void windowhdl::MainWin::init_webview()
{
    //? fank you to https://stackoverflow.com/questions/17039942/example-of-using-webkitgtk-with-gtkmm-3-0
    WebKitWebView *one = WEBKIT_WEB_VIEW(webkit_web_view_new());
    /*
     * the next line does some tricks:
     * GTK_WIDGET( one ) -> convert WebKitWebView to GtkWidget (one->two)
     * Glib::wrap( GTK_WIDGET( one ) ) -> convert GtkWidget to Gtk::Widget (two->three)
     */
    Gtk::Widget *three = Glib::wrap(GTK_WIDGET(one));

    this->add(*three);
    this->w_webview = three;
    webkit_web_view_load_uri(one, ("file://" + get_cfgdir() + "/assets/home.html").c_str());
}

windowhdl::MainWin::~MainWin()
{
}
