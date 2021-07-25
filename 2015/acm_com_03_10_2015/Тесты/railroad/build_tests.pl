#!/usr/bin/env perl

# Set author name here
my $author = "ip";

use strict;
use warnings;

use Term::ANSIColor;
use File::Copy;
use File::Basename;
use Cwd qw/getcwd/;

my $fail_test = "";
my $top_dir = getcwd;
my $problem = basename($top_dir);
my $sol_name = $problem . "_" . $author;

sub compile_cpp {
    my $name = shift;
    system("g++ $name.cpp -O3 -o $name") == 0 or die colored("Cannot compile $name", 'red');
}

sub compile_java {
    my $name = shift;
    system("javac $name.java") == 0 or die colored("Cannot compile $name", 'red');
}

sub run_java {
    my $name = shift;
    system("java -Xss256M -ea $name") == 0 or die colored("Cannot run $name", 'red');
}

sub run_cpp {
    my $name = shift;
    system("./$name") == 0 or die colored("Cannot run $name", 'red');
}

sub run_py {
    my $name = shift;
    system("python $name.py") == 0 or die colored("Cannot run $name", 'red');
}

`./clean.sh`;

mkdir "tests";
chdir "src";
print "Compiling generator\n";
compile_java("TestGen") if (-e ("TestGen.java"));
print "Generating tests\n";
my $have_gen = 0;
if (-e ("TestGen.java")) {
	$have_gen = 1;
	run_java("TestGen");
}
if (-e ("TestGen.py")) {
	$have_gen = 1;
	run_py("TestGen");
}

$have_gen or die colored("No generator found", 'red');

chdir "..";

print "Compiling validator\n";
compile_java("Validate");

print "Compiling author solution\n";
my $have_sol = 0;
if (-e ($sol_name . ".cpp")) {
	$have_sol = 1;
    compile_cpp($sol_name) 
}
if (-e ($sol_name . ".java")) {
	$have_sol = 1;
	compile_java($sol_name) if (-e ($sol_name . ".java"));
}

$have_sol or die colored("Author solution not found", 'red');

# Only support java checkers
`javac -cp ../../../lib/testlib4j.jar Check.java -encoding utf8`;
if ($? != 0) {
	die colored("Cannot compile checker", 'red');
}

sub generate_answers {
    my $test_dir = shift;
    print "Generating answers\n";
    for my $test (glob "./$test_dir/*") {
        next if $test =~ /\.a$/;
        next if -d $test;
        copy "$test", "$problem.in";
        my $output = `java Validate < $problem.in`;
		if ($? != 0) {
			warn colored("Validator doesn't accept test $test\n$output", 'red');
		} else {
			print colored("Validator accepts $test\n", 'green');
		}

		eval {
			run_cpp($sol_name) if (-e ($sol_name . ".cpp"));
			run_java($sol_name) if (-e ($sol_name . ".java"));
		};
		my $re = $@;
        copy "$problem.out", "$test.a";
        (!$re && system("java -Xmx256M -Xss64M -cp '../../../lib/testlib4j.jar:.' ru.ifmo.testlib.CheckerFramework Check $test $test.a $test.a") == 0) or warn colored("Author solution failed on $test", 'red');
    }
}

generate_answers "tests";

