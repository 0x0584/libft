#!/usr/bin/perl
# File: tst_memset.pl
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-10 Sun 02:05:06>
# Updated: <2019-02-25 Mon 03:20:57>
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

# IDEA:
# =====
#
# the function name would be the title of this script with changing
# `tst_' prefix to `ft_' and the executable would be by changing
# the post-fix `.pl' to `.out'. the description of glibc functions
# would be extracted from the man (somehow)

use strict;
use warnings;
use Cwd;
use lib '.';
use utils;
use settings;
use Data::Dumper;

my ($script, $exec, $func, $desc) = init_info $0;

sub static_args {
	# TODO: add some common tests
}

# returns random set args
sub gen_args {
	my $limit = 1 + int(rand($ARG_LIMIT));
	my $args = rand_int;

	$args .= ' ' . rand_int	 while $limit--;
	return $args;
}

sub tst_memset {
	my $nexamples = $EXAMPLE_LIMIT;
	my (@args, @func_info, @func_tsts);
	my ($counter, $ok, $ko, $foo) = (0, 0, 0);

	push @args, static_args;
	push @args, gen_args while $nexamples--;

	foreach (@args) {
		my @tmp;

		qx/.\/$exec $_/ =~ /'(.+)' \('(.+)' vs '(.+)'\)/;
		if ($2 eq $3) {
			$ok++;
			$foo = "OK";
		} else {
			$ko++;
			$foo = "KO";
		}
		push @tmp, ++$counter, $foo, "S: $_", "A: $2", "B: $3";
		push @func_tsts, \@tmp;
	}

	push @func_info, $func, ($desc eq "" ? "true" : "false"),
		"$counter $ok/$ko", $desc;
	$counter = 1;
	foreach my $aref (@func_tsts) {
		log_tst $counter, @func_info, @$aref;
		$counter = 0;
	}
}

tst_memset;

__END__
# make something like this

our @func_info = (
	"ft_memset()",				# function name
	"true",						# is glibc function
	"30 27/2",					# number of test OK/KO
	qq/set an array S to a specific value V. are
interpreted as `unsigned char' ie, 1 Byte
(which 8 bits on most systems)/	# description
);

our @func_tst = (
	"01",						# test ID
	"S: 4 0 2 0 0 0 0 0 0 0 0",	# input
	"A: 0 0 0 0 0 0 0 0 0 0 0",	# output
	"B: 0 0 0 0 0 0 0 0 0 0 0"	# expected
);

log_tst 1, @func_info, @func_tst;
