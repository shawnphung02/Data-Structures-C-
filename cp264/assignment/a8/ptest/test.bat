rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.c *.h *.txt -r

echo q1 > test_result.txt
gcc avl.c avl_main.c -o q1
q1 >> test_result.txt

echo q2 >> test_result.txt

gcc avl.c set_avl.c set_avl_main.c -o q2
q2 >> test_result.txt

echo q3 >> test_result.txt

gcc queue_stack.c avl.c myrecord_avl.c myrecord_avl_main.c -o q3
q3 >> test_result.txt

fc test_result.txt test_solution.txt > test_report.txt
