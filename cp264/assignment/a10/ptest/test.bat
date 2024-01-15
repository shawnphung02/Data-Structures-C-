
7z.exe e *.zip *.h *.c *.txt -r

echo batch public test > test_result.txt
gcc -std=c99 edgelist.c edgelist_main.c -o q1
echo q1 >> test_result.txt
q1.exe >> test_result.txt

gcc -std=c99 queue_stack.c graph.c graph_main.c -o q2
echo q2 >> test_result.txt
q2.exe >> test_result.txt

gcc -std=c99 queue_stack.c heap.c edgelist.c graph.c algorithm.c algorithm_main.c -o q3
echo q3 >> test_result.txt
q3.exe >> test_result.txt


fc test_result.txt test_solution.txt > test_report.txt
