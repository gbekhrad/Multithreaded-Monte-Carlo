# Multithreaded Monte Carlo 

Gabriella (Gabi) Bekhrad  
gabimbek@gmail.com  

## Overview/Source Files:
- mcarlo.c: C program that uses threads and a random number generator to run an algorithm that estimates pi.   

Estimating π can be done by supposing there exists a circle inscribed within a square. A series of random points are generated as simple (x, y) coordinates between (-1, 1) and (1, -1). π is estimated by performing the following calculation: π = 4 × (number of points in the circle) / (total number of points). This program simulates this in a multithreaded version of this algorithm that creates a separate thread to generate a number of random points. The thread counts the number of points that occur within the circle and stores that result in a global variable. When this thread has exited, the parent thread calculates and outputs the estimated value of π. The greater the number of points, the closer the approximation to π.

### To compile: 
gcc mcarlo.c -o mcarlo

### To run:
./mcarlo <number of points (integer)>

## Sample Output:
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

## Sources:  
https://www.geeksforgeeks.org/multithreading-in-c/
https://www.design-reuse.com/articles/25090/dynamic-memory-allocation-fragmentation-c.html#:~:text=In%20C%2C%20dynamic%20memory%20is,pointer%20to%20the%20allocated%20memory.
https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/ThreadArgs.html
https://stackoverflow.com/questions/2251452/how-to-return-a-value-from-pthread-threads-in-c
https://openai.com/chatgpt/ (For debugging purposes)
