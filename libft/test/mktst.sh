#!/bin/bash
# File: mktst.sh
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-08 Fri 23:09:11>
# Updated: <2019-02-23 Sat 00:27:51>
#
# Copyright (C) 2019
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.	If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street, Fifth
# Floor, Boston, MA 02110-1301, USA.

# this is a simple script to create a test file for every file
# in src dir with a prefix tst_ and a main function

SRC_DIR=../src
TEST_DIR=./

C_BODY="int main(int argc, char *argv[]) {\n\treturn 0;\n}\n"
PERL_BODY="use strict;\n\nuse warnings;\n\nrequire \"main.pl\";\nour @tst_params;\n"

touch_files () {
	for file in	 $(find "$1" -name "$2"				| \
					   rev | cut -d/ -f1 | rev		| \
					   sed -e "$3" | tr '\n' ' ')
	do
		if [ ! -e $file ]; then
			echo -e "$4" >> $file
		fi
	done
}

touch_files "$SRC_DIR" "ft_*.c" "s/^ft_/tst_/" "$C_BODY"
touch_files "$TEST_DIR" "tst_*.c" "s/\.c$/.pl/" "$PERL_BODY"
