#!/usr/bin/perl
# File: runtst.pl
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-10 Sun 02:05:06>
# Updated: <2019-02-23 Sat 19:04:08>
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

# TODO: run all compiled programs in here
# TODO: compare outpited result with expected results
# TODO: print a nice log

# IDEA:
# =====
#
# find a away to include all the other tst_*.pl files in here
# which would have an array of program names and the arguments
# to call them with.

use strict;
use warnings;
use Cwd;

my $main_path = Cwd::realpath("main.pl");
require $main_path;

my @tst_files = glob "tst_*.pl";

print "Results: ", join " ", @tst_files, "\n\n";

foreach (@tst_files) {
	/tst_(.+)\.pl/;
	print $_, " to test $1()", $/;
	system $^X, Cwd::realpath($_);
}

# print "\nResults: ", join " ", @tst_params, "\n";

# call the sub by the name of $action
# &{\&{$action}}();

# look for valgrind using system
# test with corrent input first, then try things like passing a NULL or something, since even glibc functions would suffer from the same. an intuitive idea would be creating a function that would take a special syntax and turn it into things like proper strings or NULL.
