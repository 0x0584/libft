#!/usr/bin/perl
# File: tst_memset.pl
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-10 Sun 02:05:06>
# Updated: <2019-02-25 Mon 20:50:43>
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

# why removing random/generated args?
#
# well for the moment, i cannot think of a way to generate some
# "common random input". I might havea set of example whether for
# integers or strings and choose randomly one input each time,
# without repetition. IDK, that comes later!

use strict;
use warnings;
use lib '.';
use utils;

sub static_args {
	my $input = "41 32 -17 8 59 -54 -6 65 2 12 11 7 -85 1024";
	my @args = ();

	push @args, "11 $input";
	push @args, "-11 $input";
	push @args, "-1 $input";
	push @args, "0 $input";
	push @args, "-2147483648 $input";
	push @args, "2147483647 $input";

	return @args;
}

run_tst $0, static_args;
