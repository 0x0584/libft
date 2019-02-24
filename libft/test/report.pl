# Perl 5 code...

our ($func, $isglibc, $ok_ko, $desc) = (
    "ft_memset()",
    "true",
    "30 27/2",
    qq/set an array S to a specific value V. are interpreted as `unsigned char' ie, 1 Byte (which 8 bits on most systems)/
);

our ($tst_id, $tst_in, $tst_out, $tst_expct) = (
    "01",
    "S: 4 0 2 0 0 0 0 0 0 0 0 0 0 0 0 0 1 4 5 1 3 7 8 4 5 1 2 3 5 4 5",
    "A: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
    "B: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
);

format STDOUT_TOP =
 ===================================================
|     Function     |     Glibc?     | Tests - OK/KO |
|------------------+----------------+---------------|
| @||||||||||||||| | @||||||||||||| | @|||||||||||| |
  $func,             $isglibc,        $ok_ko,
| ==================================================|
|                                                   |
| Description:                                      |
|                                                   |
|  ^||||||||||||||||||||||||||||||||||||||||||||||  |~~
   $desc,
|                                                   |
.

format STDOUT =
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

write STDOUT;
print $^L;