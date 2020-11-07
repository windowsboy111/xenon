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
#pragma once
#ifndef Xe_NAVCTL_H
#define Xe_NAVCTL_H

// #include <sqlite3.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include "utils/fsop.h"
// #include "utils/dbctl.h"
#include <filesystem>

namespace Xe_Navigation
{
    class Tab : public Gtk::Button
    {
    public:
        int pos;
        std::string url;
        std::string title;
        Tab(int pos, std::string url, std::string title);
        ~Tab();
    };
    class TabsBar : public Gtk::Box
    {
    private:
        std::vector<Tab> tabs;
    public:
        TabsBar(/* args */);
        ~TabsBar();
    };
} // namespace Xe_Navigation

#endif
