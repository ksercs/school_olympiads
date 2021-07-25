@echo off

for %%i in (.) do set problem=%%~ni

set author=%1
set lang=%2
if "%2" == "" (
    set lang=""
)

rem set problem=prescription

if "%1" == "" (
  echo No parameters
  goto End
)

set exec = echo No execution command

echo Compiling solution

set chosenlang=""
set go=false
if [%lang%]==[dpr] set go=true
if %lang% == "" set go=true
if "%go%" == "true" (
    if EXIST %problem%_%author%.dpr (
        set chosenlang=dpr
        dcc32 -cc %problem%_%author%.dpr || goto CompSourceError
        set exec=run -m 256M %problem%_%author%.exe
    )
)

set go=false
if [%lang%]==[cpp] set go=true
if %lang% == "" set go=true
if "%go%" == "true" (
    if EXIST %problem%_%author%.cpp (
        set chosenlang=cpp
        g++ %problem%_%author%.cpp -O2 -Wall -Wl,--stack=67108864 -o %problem%_%author%.exe || goto CompSourceError
        set exec=run -m 256M %problem%_%author%.exe
    )
)

set go=false
if [%lang%]==[java] set go=true
if %lang% == "" set go=true
if "%go%" == "true" (
    if EXIST %problem%_%author%.java (
        set chosenlang=java
        javac %problem%_%author%.java -encoding utf8 || goto CompSourceError
        set exec=run -t 2 -m 256M -t 4s java -ea -Xss64M -Xmx256M %problem%_%author%
    )
)

set go=false
if [%lang%]==[python] set go=true
if %lang% == "" set go=true
if "%go%" == "true" (
    if EXIST %problem%_%author%.py (
        set chosenlang=python
        set exec=run -m 256M python %problem%_%author%.py
    )
)

if %chosenlang% == "" (
    echo Can't choose language, something is wrong
    goto End
)
echo Chosen language: %chosenlang%
                               
if exist check.dpr dcc32 -U..\..\..\lib -cc check.dpr
if exist Check.java javac -classpath ../../../lib/testlib4j.jar Check.java -encoding utf8 
if exist Check.class jar cf Check.jar *.class

echo Checking solution...

echo %date% %time% > result_%problem%_%author%_%chosenlang%.log

rem you can add tests folders here. For example: for %%s in (preliminary, tests, tests\subtask1, tests\subtask2)
for %%s in (preliminary, tests) do (
    for %%i in (%%s\??) do (
        del %problem%.out
        echo running on test %%i
        copy %%i %problem%.in > nul

        %exec%
        
        if exist check.exe check %%i %problem%.out %%i.a
        if exist Check.class java -Xmx256M -Xss64M -cp ../../../lib/testlib4j.jar;. ru.ifmo.testlib.CheckerFramework Check %%i %problem%.out %%i.a
        if errorlevel 1 (
            echo %%i failed >> result_%problem%_%author%_%chosenlang%.log    
        ) else (
            echo %%i ok >> result_%problem%_%author%_%chosenlang%.log
        )
    )
)

goto End

:CompSourcesError
  echo Cannot compile source
  goto End
:SourceRunningError
  echo Fail in running on tests

:End
    