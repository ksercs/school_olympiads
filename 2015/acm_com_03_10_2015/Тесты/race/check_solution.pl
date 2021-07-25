#!/usr/bin/env perl

use strict;
use warnings;

use Term::ANSIColor;
use Cwd qw/getcwd/;
use File::Copy;
use File::Basename;

my $TL = 5;
my $problem = basename getcwd;
my $author = shift;
my $source_name = $problem . "_" . $author;

die colored("Usage ./check_solution.pl author", 'red') if !defined($author);

my $lang = undef;
`g++ -std=c++11 -O3 $source_name.cpp -o $source_name`;
if ($? == 0) {
	$lang = "cpp";
} else {
	`javac $source_name.java`;
	if ($? == 0) {
		$lang = "java";
	} else {
		die colored("Cannot compile $source_name", 'red')
	}
}

sub test {
    for my $test (glob shift) {
        next if ($test =~ /\.a$/);
        copy "$test", "$problem.in";
        if ($lang eq "cpp") {
            `bash -c '{ time timeout $TL ./$source_name ; } 2>log.txt'`;
        } else {
            `bash -c '{ time timeout $TL java -Xss256M $source_name ; } 2>log.txt'`;
        }
        my $res = $?;
        open F, "<log.txt";
        my $time = "";
        $time .= $_ while <F>;
        close F;
        $time =~ /real\s(.*)/;
        $time = $1;
        if ($res == 0) {
            my $output = `java -Xmx256M -Xss256M -cp ../../../lib/testlib4j.jar:. ru.ifmo.testlib.CheckerFramework Check $test $problem.out $test.a`;
            if ($? == 0) {
                print colored("OK on test $test in $time .\n", 'green');
            } else {
                print colored("WA/PE on test $test in $time s.\n$output", 'red');
            }
        } else {
            print colored("TL/RE on test $test in $time s.\n", 'red');
        }
    }
}

test "tests/*";

