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
#ifndef Xe_FSOP_H
#define Xe_FSOP_H
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string>

std::string get_homedir();
std::string get_cfgdir();
const char *get_path_db();

#endif