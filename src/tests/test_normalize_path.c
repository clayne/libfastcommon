/*
 * Copyright (c) 2020 YuQing <384681@qq.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the Lesser GNU General Public License, version 3
 * or later ("LGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the Lesser GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>
#include <sys/time.h>
#include "fastcommon/logger.h"
#include "fastcommon/shared_func.h"

int main(int argc, char *argv[])
{
    char full_filename[PATH_MAX];
    const char *from;
    const char *filename;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <base> <filename>\n", argv[0]);
        return 1;
    }

    log_init();
    from = argv[1];
    filename = argv[2];
    normalize_path_ex(from, filename, full_filename, sizeof(full_filename),
            NORMALIZE_FLAGS_URL_ENABLED_AND_APPEND_PARAMS);
    printf("%s\n", full_filename);
    return 0;
}