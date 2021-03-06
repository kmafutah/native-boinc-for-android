/*
 *  Copyright (c) 2008-2010 Travis Desell, Nathan Cole, Dave Przybylo
 *  Copyright (c) 2008-2010 Boleslaw Szymanski, Heidi Newberg
 *  Copyright (c) 2008-2010 Carlos Varela, Malik Magdon-Ismail
 *  Copyright (c) 2008-2011 Rensselaer Polytechnic Institute
 *  Copyright (c) 2010-2011 Matthew Arsenault
 *
 *  This file is part of Milkway@Home.
 *
 *  Milkway@Home is free software: you may copy, redistribute and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or (at your
 *  option) any later version.
 *
 *  This file is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <windows.h>
#include <stdio.h>

#include <popt.h>
#include "milkyway_util.h"

extern int main(int argc, const char* argv[]);

/* FIXME: undefined reference to _set_invalid_parameter_handler */
void AppInvalidParameterHandler(const wchar_t* expression,
                                const wchar_t* function,
                                const wchar_t* file,
                                unsigned int line,
                                uintptr_t pReserved )
{
    fprintf(stderr, "Invalid parameter detected in function %ls. File: %ls Line: %d\n", function, file, line);
    fprintf(stderr, "Expression: %ls\n", expression);
    // Cause a Debug Breakpoint.
    DebugBreak();
}


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR Args, int WinMode)
{
    LPSTR commandLine;
    const char** argv;
    int argc, rc;

    //_set_invalid_parameter_handler(AppInvalidParameterHandler);

    commandLine = GetCommandLine();
    if (poptParseArgvString(commandLine, &argc, &argv))
    {
        mw_printf("Failed to parse command line into argv\n");
        return 1;
    }

    rc = main(argc, argv);
    free(argv);

    return rc;
}


