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
#ifndef Xe_COLORS_H
#define Xe_COLORS_H
#include <iostream>
#include <string>
namespace Colors {
    std::string red = "\x1b[31m";
    std::string red2 = "\x1b[91m";
    std::string reset = "\x1b[0m";
    std::string blue = "\x1b[34m";
}
#endif
