#!/usr/bin/perl
# File: tst_memset.pm
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-13 Sun 00:15:06>
# Updated: <2019-02-23 Sat 01:20:41>
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

# IDEA:
# =====
#
# 1.1. set a list of inputs
# 1.2. set a list of expected outputs for each input
# 1.3. set a list of program's outputs for each input
# 2. compare expected outputs with real outputs
# 3. print results

package memset;

use strict;
use warnings;

my $exec = "tst_memset.out";

sub gen_example {
	my @args = ("3 5", "\n\n");

	return "./$exec @args";
}

sub tst_memset {
	my $tmp = gen_example();
	my $out = `$tmp`;

	print $out, $/;
}
