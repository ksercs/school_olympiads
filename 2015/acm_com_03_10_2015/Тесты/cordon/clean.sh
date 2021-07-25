#!/usr/bin/env bash

rm -f *.class src/*.class
rm -f tests/*
rm -f *.in *.out
rm -f log.txt
rm -f tests.desc
for a in `find -iname '*.cpp' -type f` ; do
    rm -f ${a%%.cpp}
done
rm -rf tests preliminary
