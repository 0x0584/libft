# File: mktst.sh
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-08 Fri 23:09:11>
# Updated: <2019-02-12 Tue 03:27:03>
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
LAST=$(ls -1t | head -1)

touch $(find $SRC_DIR -name '*.c'	| \
			rev | cut -d/ -f1 | rev	| \
			sed -e 's/^ft_/tst_/'	| \
			tr '\n' ' ')
for f in $(find . -name '*.c' -newer $(ls -1t | head -1) ! -newer $LAST)
do
	echo "int main(int argc, char *argv[]) {\n\treturn 0;\n}\n" >> $f
done
