rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.c *.h *.txt -r

echo q1 > test_result.txt
gcc hash.c hash_main.c -o q1
q1 >> test_result.txt
echo\ >> test_result.txt

echo q2 >> test_result.txt
gcc common.c queue.c stack.c hash.c expression_symbol.c expression_symbol_main.c -o q2
q2 >> test_result.txt

echo\ >> test_result.txt
echo q3 >> test_result.txt
gcc heap.c heap_main.c -o q3
q3 >> test_result.txt

fc test_result.txt test_solution.txt > test_report.txt
