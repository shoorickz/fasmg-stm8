rem converts stm8 .h file to regular .inc to use with fasmg
rem install sed for windows & set path to it to use this batch file
rem usage: stm8h2inc STM8xxx.h STM8xxx.inc 
sed "s|/\*|;\/\*|" %1 | sed "s|#|;#|" | sed "s|\(DEF.*AT\)\((\)\(.*\)\,\(.*\)\()\)\;|\3 equ \4|" > %2