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
#ifndef Xe_WINHDL_H
#define Xe_WINHDL_H
#include <gtkmm/window.h>
#include <gtkmm.h>
#include <webkit2/webkit2.h>
#include "nav.h"
#include "utils/fsop.h"

namespace windowhdl
{
    class MainWin : public Gtk::Window
    {
    private:
        Xe_Navigation::TabsBar tabsBar;
        Gtk::Widget* w_webview;

    public:
        MainWin();
        virtual ~MainWin();
        void init_webview();

    protected:
    };
}

#endif
