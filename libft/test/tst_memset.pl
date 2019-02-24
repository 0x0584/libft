#!/usr/bin/perl
# File: tst_memset.pl
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-10 Sun 02:05:06>
# Updated: <2019-02-24 Sun 02:14:54>
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

use strict;
use warnings;
use Cwd;
use lib '.';
use utils qw/rand_int put_string put_line/;

my $description = qq/memset() is used to set an array S
to a specific value V. The whole array is interpreted as
`unsigned char' thus the value too is interpreted as
`unsigned char'/;
my $exec = "tst_memset.out";
my $NARGS = 1;
my $NEXAMPLES = 1;

sub static_examples {
	# TODO: add some common tests
}

sub gen_example {
	my $val = rand_int;
	my $limit = 1 + int(rand($NARGS));
	my $args = "";

	$args .= rand_int . " " while $limit--;
	return "./$exec $val $args";
}

sub tst_memset {
	my $nexamples = 1 + int(rand($NEXAMPLES));
	my @exs;

	push @exs, static_examples;
	push @exs, gen_example while $nexamples--;

	put_line;
	put_string $description;
	put_line;
	foreach (@exs) {
		print "S: ", $_ =~ /.+\.out (.+)/, "$/";
		qx/$_/ =~ /'(.+)' \('(.+)' vs '(.+)'\)/;
		print "A: $2$/B: $3$/";
		put_line;
	}
}

tst_memset();
