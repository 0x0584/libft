# File: runtst.pl
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-10 Sun 02:05:06>
# Updated: <2019-02-14 Thu 19:22:25>
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

our @tst_params;
my @tst_files = glob "tst_*.pl";

foreach my $file (@tst_files) {
	print Cwd::realpath($file), "\n";
	system $^X, Cwd::realpath($file);
}

# print "Results: ", join " ", @tst_files, "\n";
# print "\nResults: ", join " ", @tst_params, "\n";