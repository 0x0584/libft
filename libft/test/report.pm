# File: report.pm
# Author: Anas Rchid (0x0584)
#
# Created: <2019-02-10 Sun 02:05:06>
# Updated: <2019-02-24 Sun 05:00:32>
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
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.    If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street, Fifth
# Floor, Boston, MA 02110-1301, USA.

package report;

use strict;
use warnings;
use Exporter 'import';

our @EXPORT = qw/log_tst/;

sub log_tst {
    my ($head, $func, $isglibc, $ok_ko, $desc,
        $tst_id, $tst_in, $tst_out, $tst_expct) = @_;

    format LOG_TOP =
 ===================================================
|     Function     |     Glibc?     | Tests - OK/KO |
|------------------+----------------+-------------- |
| @||||||||||||||| | @||||||||||||| | @|||||||||||| |
  $func,             $isglibc,        $ok_ko,
| ================================================= |
|                                                   |
| Description:                                      |
|                                                   |
|  ^||||||||||||||||||||||||||||||||||||||||||||||  |~~
   $desc,
|                                                   |
 ===================================================
.

    format LOG =
 == @## ============================================
    $tst_id,
| ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< |~~
  $tst_in,
|---------------------------------------------------|
| ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< |~~
  $tst_out,
|---------------------------------------------------|
| ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< |~~
  $tst_expct,
.

   $^L = " =================================================== $/";

    if ($head) {
        $~ = "LOG_TOP";
        write;
    }
    format_name STDOUT "LOG";
    format_top_name STDOUT "LOG_TOP";
    write; print $^L;
}

1;
