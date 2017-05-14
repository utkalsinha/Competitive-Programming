===========
|| Stone ||
===========

Roman has no idea, why this problem is called Stone. He also has no idea on how to solve the followong problem: given array of N integers A and a number K. During a turn the maximal value over all Ai is chosen, let's call it MAX. Then Ai =
MAX - Ai is done for every 1 <= i <= N. Help Roman to find out how will the array look like after K turns.
Input
The numbers N and K are given in the first line of an input. Then N integers are given in the second line which denote the array A.
Output
Output N numbers on a single line. It should be the array A after K turns.
Constraints
 
1 <= N <= 105
0 <= K <= 109
Ai does not exceed 2 * 109 by it's absolute value.
 
Example
Input:
4 1
5 -1 7 0

Output:
2 8 0 7

===============Problem Details=================
Author:	Rubanenko (http://www.codechef.com/users/Rubanenko)
Tester:	xcwgf666 (http://www.codechef.com/users/xcwgf666)
Tags	Rubanenko (http://www.codechef.com/tags/problems/Rubanenko)
Date Added:	14-04-2014
Time Limit:	1 sec
Source Limit:	50000 Bytes
Languages:	ADA, ASM, BASH, BF, C, C99 strict, CAML, CLOJ, CLPS, CPP 4.3.2, CPP 4.8.1, CPP11, CS2, D, ERL, FORT, FS, GO, HASK, ICK, ICON, JAR, JAVA, JS, LISP clisp, LISP sbcl, LUA, NEM, NICE, NODEJS, PAS fpc, PAS gpc, PERL, PERL6, PHP, PIKE, PRLG, PYTH, PYTH 3.1.2, RUBY, SCALA, SCM guile, SCM qobi, ST, TCL, TEXT, WSPC