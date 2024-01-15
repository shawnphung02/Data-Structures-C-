rem the following command uses 7z program to extract the code and readme.txt
7z.exe e *.zip *.c *.h *.txt -r

echo q1 > test_result.txt
gcc mysort.c mysort_main.c -o q1
q1 >> test_result.txt

echo\ >> test_result.txt
echo q2 >> test_result.txt
gcc mysort.c myrecord.c myrecord_main.c -o q2

q2 >> test_result.txt

fc test_result.txt test_solution.txt > test_report.txt
fc record_report.txt record_solution.txt >> test_report.txt
