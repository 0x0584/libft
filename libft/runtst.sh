#!/bin/bash
# File: runtst.sh
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-24 Fri 23:09:11>
# Updated: <2019-02-25 Mon 21:30:57>
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

# this is a dumb solution, since when I create a symbolic link
# of `runtst.pl' I got a message that tell's me can't find some
# file.
run_tst () {
	cd test;
	perl runtst.pl;
	cd ..;
}

run_tst;
