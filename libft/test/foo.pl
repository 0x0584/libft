use Data::Dumper;

my $func = "memset";
my $out = qx/man 3 $func/;

my $flag = undef;
my $desc = undef;

# print $out;

while ($out	 =~ /(.+)\n/g) {
	$flag = 1 if $1 =~ /DESCRIPTION/;
	$flag = undef if $1 =~ /RETURN/;
	$desc .= "$1 " if $flag;
}

$desc =~ s/^\s+|\s+$//g;
$desc =~ s/\s+/ /g;
print "Function: $func()$/Description: $desc$/" if defined $desc or print "undefined!";

sub bar {
	print "@_";
}

# bar "this", "that";

my (@foo, @bar, @baz);

push @bar, 10, 20;
push @baz, 22, 11;

push @foo, \@bar, \@baz;

use Data::Dumper;

print Dumper @foo;

print $foo[0][0];

# test args to sub



sub fuzz {
	print $/, Dumper shift;
}

fuzz 1, 2, 3, 5, 6, 7;
