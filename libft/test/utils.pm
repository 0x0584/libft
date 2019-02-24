# File: utils.pm
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-10 Sun 02:05:06>
# Updated: <2019-02-25 Mon 00:09:25>
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

package utils;

use strict;
use warnings;
use lib '.';
use report;
use Exporter 'import';

our @EXPORT = qw/init_info put_string put_line rand_int log_tst/;

my $SIZE = 60;

sub put_line {
	print "=" x $SIZE, $/;
}

sub put_string	{
	my $str = shift;
	my $counter = 0;

	$str =~ s/\n/ /g;
	$str =~ s/\s+/ /g;
	while ($str =~ m/(.{1,$SIZE})/gs) {
		print $1, "\n";
	}
}

sub rand_int {
	my $min = int(rand(2147483648));
	my $max = int(rand(2147483647));

	return $max % rand($min) - $min % rand($max);
}


sub init_info {
	my $script = shift;
	my ($func, $exec, $desc, $foo);
	my ($flag, $out);

	$script =~ /.+\/(tst_.+.pl)/;

	$script = $1;
	$exec = $1;
	$func = $1;
	$foo = $1;
	$desc = "";

	$foo =~ s/^tst_|\.pl$//g;
	$exec =~ s/\.pl$/.out/g;
	$func =~ s/^tst_/ft_/g;
	$func =~ s/\.pl$/()/g;

	$flag = undef;
	$out = qx/man 3 $foo/;
	while ($out	=~ /(.+)\n/g) {
		$flag = undef if $1 =~ /(RETURN)/;
		$desc .= "$1 " if $flag;
		$flag = 1 if $1 =~ /(DESCRIPTION)/;
	}

	$desc =~ s/^\s+|\s+$//g;
	$desc =~ s/\s+/ /g;

	return ($script, $exec, $func, $desc);
}

1;
