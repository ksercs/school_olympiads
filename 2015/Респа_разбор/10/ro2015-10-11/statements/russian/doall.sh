cd ../../problems/array/statements/russian
for file in ./*.mp
do
    mpost $file
done
rm -f *.log
cd -

cd ../../problems/cafe/statements/russian
for file in ./*.mp
do
    mpost $file
done
rm -f *.log
cd -

cd ../../problems/pair-of-nonintersected-intervals/statements/russian
for file in ./*.mp
do
    mpost $file
done
rm -f *.log
cd -

cd ../../problems/lcmer/statements/russian
for file in ./*.mp
do
    mpost $file
done
rm -f *.log
cd -

cd ../../problems/2n-matching/statements/russian
for file in ./*.mp
do
    mpost $file
done
rm -f *.log
cd -

cd ../../problems/compatible/statements/russian
for file in ./*.mp
do
    mpost $file
done
rm -f *.log
cd -

latex statements.tex
latex statements.tex
dvips statements.dvi
dvipdfmx -p a4 statements.dvi
rm -f *.log
rm -f *.aux
rm -f *.dvi
rm -f *.ps
