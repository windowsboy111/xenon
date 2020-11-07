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
#ifndef Xe_DBCTL_H
#define Xe_DBCTL_H
#include <filesystem>
#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include "fsop.h"
#include "console.h"

namespace Xe_dbctl_private
{
    char **queryRes[3];
    int callback(void *NotUsed, int argc, char **argv, char **azColName)
    {
        queryRes[0] = (char **)argc;
        queryRes[1] = argv;
        queryRes[2] = azColName;
    }
} // namespace Xe_dbctl_private

namespace fs = std::filesystem;

class Db
{
private:
    sqlite3 *database;

public:
    Db()
    {
        int rc{openDb()};
        if (rc != 0)
        {
            //! FAILED TO OPEN FILE
            Console::err("failed to open sqlite3 db: " + std::string(sqlite3_errmsg(database)), "FRICK");
            return;
        }
    };
    ~Db(){};
    char ***exec(std::string query)
    {
        char *zErrMsg = 0;
        int rc = sqlite3_exec(this->database, query.c_str(), Xe_dbctl_private::callback, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
            Console::err(zErrMsg, "SQLITE3");
            sqlite3_free(zErrMsg);
        }
        else
        {
            return Xe_dbctl_private::queryRes;
        }
    }

protected:
    int openDb()
    {
        //* checks
        const char *path_db{get_path_db()};
        fs::path f{get_path_db()};
        if (!fs::exists(f))
        {
            //? create that file
            std::ofstream db_file(path_db);
            db_file.close();
        }
        //* open that file
        int rc{sqlite3_open(path_db, &database)};
        return rc;
    }
};
#endif
