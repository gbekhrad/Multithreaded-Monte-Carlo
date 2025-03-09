Name: Gabriella (Gabi) Bekhrad
Email: gbekhrad@chapman.edu
ID: 2417841

Title of Assignment: Programming Assignment 3 - Threads

Overview/Source Files:
- mcarlo.c: C program that uses threads and a random number generator to run an algorithm that estimates pi.   

To compile: 
gcc mcarlo.c -o mcarlo

To run:
./mcarlo <number of points (integer)>

Sample Output:
./mcarlo hello        
Invalid number of points.

./mcarlo 5
Estimated Pi = 2.400000

./mcarlo 10
Estimated Pi = 2.800000

./mcarlo 100
Estimated Pi = 3.200000

./mcarlo 1000
Estimated Pi = 3.068000

./mcarlo 10000
Estimated Pi = 3.103200

./mcarlo 100000
Estimated Pi = 3.133600

./mcarlo 10000000
Estimated Pi = 3.143018

./mcarlo 100000000 
Estimated Pi = 3.141686

Sources:
https://www.geeksforgeeks.org/multithreading-in-c/
https://www.design-reuse.com/articles/25090/dynamic-memory-allocation-fragmentation-c.html#:~:text=In%20C%2C%20dynamic%20memory%20is,pointer%20to%20the%20allocated%20memory.
https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/ThreadArgs.html
https://stackoverflow.com/questions/2251452/how-to-return-a-value-from-pthread-threads-in-c
https://openai.com/chatgpt/ (For debugging purposes)