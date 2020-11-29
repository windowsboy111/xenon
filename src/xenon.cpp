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
#include <gtkmm/application.h>
#include <iostream>
#include <cstring>
#include <sqlite3.h>
#include "winhdl.h"


int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.xenon");

    windowhdl::MainWin mainwin;
    mainwin.show_all_children();

    //Shows the window and returns when it is closed.
    return app->run(mainwin);
}
