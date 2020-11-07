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
#ifndef Xe_CONSOLE_H
#define Xe_CONSOLE_H
#include <iostream>
#include "colors.h"

namespace Console
{
    void out(std::string msg) {
        std::cout << Colors::reset << "[" << Colors::blue << " INFO " << Colors::reset << "]\t"
            << msg << std::endl;
    }
    void out(std::string msg, std::string type) {
        std::cout << Colors::reset << "[" << Colors::blue << type << Colors::reset << "]\t"
            << msg << std::endl;
    }
    void err(std::string msg, std::string type) {
        std::cerr << Colors::reset << "[" << Colors::red << type << Colors::reset << "]\t"
            << msg << std::endl;
    }
} // namespace console

#endif