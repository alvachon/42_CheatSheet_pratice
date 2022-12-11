#include <stdio.h>

#define true  1
#define false 0

int what_is_forty_two(void) 
{
   int n;
   
   n = true << 1 | false; // n = 0b10;
   while (__builtin_popcount(n) != 3) // stop when reaching 3 bits set ...0,0,0
   {
	n |= n << 2;  // n adds two empty bits with << 2 (x4) and add itself with | ... 1, 1, 0 (42)
   }
   return (++n == '*') ? n : !!n * (n - 1); // you may simply return n;
}

int main(void)
{
    char *question;
   
    question  = "What is the answer to Life, the Universe and Everything?\n";
    printf("%sDeep Thought: %d\n", question, what_is_forty_two()); // %s print a string, and %d an integer
    return 0;
}
