rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.c *.h *.txt -r

echo q1 > test_result.txt
gcc common.c queue.c queue_main.c -o q1
q1 >> test_result.txt

echo q2 >> test_result.txt
gcc common.c stack.c stack_main.c -o q2
q2 >> test_result.txt

echo q3 >> test_result.txt
gcc common.c queue.c stack.c expression.c expression_main.c -o q3
q3 >> test_result.txt
q3 "12 + 24*3" >> test_result.txt

fc test_result.txt test_solution.txt > test_report.txt
