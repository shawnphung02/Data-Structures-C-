JobID: cp264-a8
Name: Shawn Phung
ID: 200814180

Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Grade_Item_ID [self-evaluation/total/marker-evaluation] Description


Q1 AVL tree
Q1.1 [2/2/*] balance_factor(),is_avl()               
Q1.2 [2/2/*] rotate_left()                           
Q1.3 [2/2/*] rotate_right()                          
Q1.4 [4/4/*] insert()                                
Q1.5 [4/4/*] delete()                                

Q2 AVL tree for set
Q2.1 [3/3/*] size(), contains_element(), clear_set() 
Q2.2 [3/3/*] add_element(),remove_element()          

Q3 AVL tree for record data processing
Q3.1 [5/5/*] merge_tree()                            
Q3.2 [5/5/*] merge_data()                            

Total: [30/30/*]

Copy and paste the console output of your public test in the following. 
This will help markers to evaluate your program if it fails the marking tests.  

Q1 output:
AVL insertions:
insert_avl(&root, A, 1.0):
insert_avl(&root, B, 2.0):
insert_avl(&root, C, 3.0):
insert_avl(&root, D, 4.0):
insert_avl(&root, E, 5.0):
insert_avl(&root, F, 6.0):
insert_avl(&root, G, 7.0):
|___:D,4.0,3
    |___R:F,6.0,2
        |___R:G,7.0,1
        |___L:E,5.0,1
    |___L:B,2.0,2
        |___R:C,3.0,1
        |___L:A,1.0,1
is_avl(&root):1
inorder:A B C D E F G
AVL deletions:
delete_avl(&root, A):
delete_avl(&root, C):
delete_avl(&root, E):
delete_avl(&root, G):
|___:D,4.0,2
    |___R:F,6.0,1
    |___L:B,2.0,1
is_avl(&root):1
inorder:B D F


Q2 output:
after declare set size(set):0
after declare set elements:empty
after add_element size(set):3
after add_element elements:a b c
contains(set,a):1
contains(set,d):0
after remove_element size(set):2
after remove_element elements:a b
after clear_set size(set):0
after clear_set elements:empty


Q3 output:
Inport data from marks1.txt to t1:
Bodnar,93.6
Chabot,80.4
Costa,45.1
Dabu,74.4
Giblett,59.1
Hatch,66.5
Myrie,76.7
Smith,60.1
Suglio,85.7
Sun,67.7

count:10
mean:70.9
stddev:13.5
median:0.0

Inport data from marks2.txt to t2:
Ali,88.0
Allison,67.7
Eccles,77.8
He,85.7
Koreck,77.4
Lamont,98.1
Parr,92.5
Pereira,80.3
Peters,82.3
Wang,98.1

count:10
mean:84.8
stddev:9.2
median:0.0

Merge t2 into t1:
Ali,88.0
Allison,67.7
Bodnar,93.6
Chabot,80.4
Costa,45.1
Dabu,74.4
Eccles,77.8
Giblett,59.1
Hatch,66.5
He,85.7
Koreck,77.4
Lamont,98.1
Myrie,76.7
Parr,92.5
Pereira,80.3
Peters,82.3
Smith,60.1
Suglio,85.7
Sun,67.7
Wang,98.1

count:20
mean:77.9
stddev:13.5
median:0.0

Remove data from t2:
count:0

count:20
mean:77.9
stddev:13.5
median:79.1

Write report to file record_report.txt:

Clean t1: