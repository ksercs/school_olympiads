#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir tests
echo "Generating test #1"
scripts/gen-input-via-stdout.sh "wine files/generator-test-1.exe" "tests/01" 1
echo "Generating test #2"
scripts/gen-input-via-stdout.sh "wine files/generator-test-2.exe" "tests/02" 2
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "wine files/generator-test-3.exe" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/generator-even.exe 5 1" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-nonuniform.exe 5 5 5 10 1" "tests/05" 5
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-evenlove.exe 5 3 4 10 1" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 5 5 5 10 1" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 5 3 5 10 1" "tests/08" 8
echo "Generating test #9"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-smallnums.exe 20 20 20 15 1" "tests/09" 9
echo "Generating test #10"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-smallnums.exe 20 20 20 15 2" "tests/10" 10
echo "Generating test #11"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-bignums.exe 20 20 20 15 1" "tests/11" 11
echo "Generating test #12"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-bignums.exe 20 20 20 15 2" "tests/12" 12
echo "Generating test #13"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-nonuniform.exe 17 18 19 13 55" "tests/13" 13
echo "Generating test #14"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-nonuniform.exe 17 18 19 13 77" "tests/14" 14
echo "Generating test #15"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-evenlove.exe 19 19 19 15 42" "tests/15" 15
echo "Generating test #16"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 1 1 2 1 1" "tests/16" 16
echo "Generating test #17"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 19 18 17 13 77" "tests/17" 17
echo "Generating test #18"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 20 20 20 15 42" "tests/18" 18
echo "Generating test #19"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 1 1 1 3 1" "tests/19" 19
echo "Generating test #20"
scripts/gen-input-via-stdout.sh "wine files/generator-even.exe 7" "tests/20" 20
echo "Generating test #21"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-smallnums.exe 500 500 500 2000 1" "tests/21" 21
echo "Generating test #22"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-smallnums.exe 500 500 500 2000 2" "tests/22" 22
echo "Generating test #23"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-bignums.exe 500 500 500 2000 1" "tests/23" 23
echo "Generating test #24"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-bignums.exe 500 500 500 2000 2" "tests/24" 24
echo "Generating test #25"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-nonuniform.exe 317 218 199 5 55" "tests/25" 25
echo "Generating test #26"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-nonuniform.exe 317 218 199 2000 55" "tests/26" 26
echo "Generating test #27"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-nonuniform.exe 500 500 500 2000 1" "tests/27" 27
echo "Generating test #28"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-nonuniform.exe 500 500 500 2000 2" "tests/28" 28
echo "Generating test #29"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-evenlove.exe 317 218 199 2000 55" "tests/29" 29
echo "Generating test #30"
scripts/gen-input-via-stdout.sh "wine files/generator-even.exe 20" "tests/30" 30
echo "Generating test #31"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 317 218 199 1997 55" "tests/31" 31
echo "Generating test #32"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform-evenlove.exe 500 500 500 2000 1" "tests/32" 32
echo "Generating test #33"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 317 218 199 2000 55" "tests/33" 33
echo "Generating test #34"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 500 500 500 2000 1" "tests/34" 34
echo "Generating test #35"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 500 500 500 2000 2" "tests/35" 35
echo "Generating test #36"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 500 500 500 2000 77" "tests/36" 36
echo "Generating test #37"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 477 500 500 1 42" "tests/37" 37
echo "Generating test #38"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 498 500 1 2000 1" "tests/38" 38
echo "Generating test #39"
scripts/gen-input-via-stdout.sh "wine files/generator-rand-uniform.exe 500 2 3 2000 2" "tests/39" 39
echo "Generating test #40"
scripts/gen-input-via-stdout.sh "wine files/generator-even.exe 500" "tests/40" 40
echo ""
echo "Generating answer for test #1"
scripts/gen-answer.sh tests/01 tests/01.a
echo ""
echo "Generating answer for test #2"
scripts/gen-answer.sh tests/02 tests/02.a
echo ""
echo "Generating answer for test #3"
scripts/gen-answer.sh tests/03 tests/03.a
echo ""
echo "Generating answer for test #4"
scripts/gen-answer.sh tests/04 tests/04.a
echo ""
echo "Generating answer for test #5"
scripts/gen-answer.sh tests/05 tests/05.a
echo ""
echo "Generating answer for test #6"
scripts/gen-answer.sh tests/06 tests/06.a
echo ""
echo "Generating answer for test #7"
scripts/gen-answer.sh tests/07 tests/07.a
echo ""
echo "Generating answer for test #8"
scripts/gen-answer.sh tests/08 tests/08.a
echo ""
echo "Generating answer for test #9"
scripts/gen-answer.sh tests/09 tests/09.a
echo ""
echo "Generating answer for test #10"
scripts/gen-answer.sh tests/10 tests/10.a
echo ""
echo "Generating answer for test #11"
scripts/gen-answer.sh tests/11 tests/11.a
echo ""
echo "Generating answer for test #12"
scripts/gen-answer.sh tests/12 tests/12.a
echo ""
echo "Generating answer for test #13"
scripts/gen-answer.sh tests/13 tests/13.a
echo ""
echo "Generating answer for test #14"
scripts/gen-answer.sh tests/14 tests/14.a
echo ""
echo "Generating answer for test #15"
scripts/gen-answer.sh tests/15 tests/15.a
echo ""
echo "Generating answer for test #16"
scripts/gen-answer.sh tests/16 tests/16.a
echo ""
echo "Generating answer for test #17"
scripts/gen-answer.sh tests/17 tests/17.a
echo ""
echo "Generating answer for test #18"
scripts/gen-answer.sh tests/18 tests/18.a
echo ""
echo "Generating answer for test #19"
scripts/gen-answer.sh tests/19 tests/19.a
echo ""
echo "Generating answer for test #20"
scripts/gen-answer.sh tests/20 tests/20.a
echo ""
echo "Generating answer for test #21"
scripts/gen-answer.sh tests/21 tests/21.a
echo ""
echo "Generating answer for test #22"
scripts/gen-answer.sh tests/22 tests/22.a
echo ""
echo "Generating answer for test #23"
scripts/gen-answer.sh tests/23 tests/23.a
echo ""
echo "Generating answer for test #24"
scripts/gen-answer.sh tests/24 tests/24.a
echo ""
echo "Generating answer for test #25"
scripts/gen-answer.sh tests/25 tests/25.a
echo ""
echo "Generating answer for test #26"
scripts/gen-answer.sh tests/26 tests/26.a
echo ""
echo "Generating answer for test #27"
scripts/gen-answer.sh tests/27 tests/27.a
echo ""
echo "Generating answer for test #28"
scripts/gen-answer.sh tests/28 tests/28.a
echo ""
echo "Generating answer for test #29"
scripts/gen-answer.sh tests/29 tests/29.a
echo ""
echo "Generating answer for test #30"
scripts/gen-answer.sh tests/30 tests/30.a
echo ""
echo "Generating answer for test #31"
scripts/gen-answer.sh tests/31 tests/31.a
echo ""
echo "Generating answer for test #32"
scripts/gen-answer.sh tests/32 tests/32.a
echo ""
echo "Generating answer for test #33"
scripts/gen-answer.sh tests/33 tests/33.a
echo ""
echo "Generating answer for test #34"
scripts/gen-answer.sh tests/34 tests/34.a
echo ""
echo "Generating answer for test #35"
scripts/gen-answer.sh tests/35 tests/35.a
echo ""
echo "Generating answer for test #36"
scripts/gen-answer.sh tests/36 tests/36.a
echo ""
echo "Generating answer for test #37"
scripts/gen-answer.sh tests/37 tests/37.a
echo ""
echo "Generating answer for test #38"
scripts/gen-answer.sh tests/38 tests/38.a
echo ""
echo "Generating answer for test #39"
scripts/gen-answer.sh tests/39 tests/39.a
echo ""
echo "Generating answer for test #40"
scripts/gen-answer.sh tests/40 tests/40.a
echo ""

