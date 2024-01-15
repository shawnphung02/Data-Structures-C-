/**
--------------------------------------------------
Project: cp264-a1q1
File:    caseflip.c
Author: Shawn Phung
Version: 2023-01-20
--------------------------------------------------
*/
// program signature
#include <stdio.h>
int main() {
  //the following line is for Eclipse console none-buffered output, in case you use Eclipse to do your assignment
  setvbuf(stdout, NULL, _IONBF, 0); //or setbuf(stdout, NULL); 
    
  char c = 0, temp;
  do {
    printf("Please enter a character\n");
    scanf("%c", &c); //this is to get a character input from keyboard stdin.

    // flush the input buffer 
    do { // this loop is to get rid of additional characters in stdin buffer
      scanf("%c", &temp);
      if (temp == '\n') break;
    } while (1);
        if(c >= 'a' && c <= 'z'){
            printf("%c:%c\n", c, c-32);
        }else if(c >= 'A' && c <= 'Z'){
            printf("%c:%c\n", c, c+32);
        }else if(c == '*'){
            printf("%c:quit\n", c);
            break;
        }else{
            printf("%c:invalid\n", c);
        }  
  } while (1);
  return 0;
}