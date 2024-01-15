JobID: cp264-a1
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


Q1 Case flip
Q1.1 [3/3/*] prompt for input                        
Q1.2 [4/4/*] input upper/lower case                  
Q1.3 [3/3/*] others, quit                            

Q2 Computing factorial
Q2.1 [e/3/*] command line argument                   
Q2.2 [4/4/*] correctness of computing                
Q2.3 [3/3/*] overflow testing                        

Q3 Solving quadratic equation
Q3.1 [6/6/*] correctness of computing                
Q3.2 [2/2/*] robust for invalid input                
Q3.3 [2/2/*] output format                           

Total: [30/30/*]

Copy and paste the console output of your public test in the following. 
This will help markers to evaluate your program if it fails the marking tests.  

Q1 output:
Please enter a character
A:a
Please enter a character
d:D
Please enter a character
4:invalid
Please enter a character
$:invalid
Please enter a character

Q2 output:
C:\cp264\assignment\a1>factorial 3
3!:6

C:\cp264\assignment\a1>factorial 0
0:invalid

C:\cp264\assignment\a1>factorial 11
11!:39916800

C:\cp264\assignment\a1>factorial 13
13!:overflow

C:\cp264\assignment\a1>factorial 17
17!:overflow

Q3 output:
C:\cp264\assignment\a1>quadratic 1,3,3
(1.000000)x^2+(3.000000)x+(3.000000)=0 has two complex roots: -1.500000+0.866025i, -1.500000-0.866025i

C:\cp264\assignment\a1>quadratic 1,-1,-6
(1.000000)x^2+(-1.000000)x+(-6.000000)=0 has two distinct real roots: 3.000000 and -2.000000

C:\cp264\assignment\a1>quadratic 1,-4,4
(1.000000)x^2+(-4.000000)x+(4.000000)=0 has two equal real roots: 2.000000

C:\cp264\assignment\a1>quadratic 0,1,5
(0.000000)x^2+(1.000000)x+(5.000000)=0 is not a quadratic equation