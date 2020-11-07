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
#include "nav.h"


namespace fs = std::filesystem;


Xe_Navigation::Tab::Tab(int pos, std::string url, std::string title) : Gtk::Button(), pos{pos}, url{url}, title{title}
{
    this->set_label(title);
}

Xe_Navigation::Tab::~Tab()
{}

Xe_Navigation::TabsBar::TabsBar()
{
    Tab tab(0, "", "Home");
    this->pack_end(tab);
    //// Db db;
    //// char*** res
    //// { 
    ////     db.exec("CREATE TABLE tabs"
    ////         "("
    ////         "id INT PRIMARY KEY NOT NULL,"
    ////         "URL TEXT NOT NULL,"
    ////         "POS INT NOT NULL,"
    ////         ");") 
    //// };
    //// if (!res) {
    ////     Console::out("Failed to create table :/", "TabsBar");
    //// }
}

Xe_Navigation::TabsBar::~TabsBar()
{}
