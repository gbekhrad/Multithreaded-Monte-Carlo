/*
Estimating Pi (π) Suppose you have a circle inscribed within a square
Generate a series of random points as simple (x,y) coordinates. Between -1,1 1,-1 etc
Estimate π by performing the following calculation: π = 4 x (number of points in circle)/(total number of points)
Write a multithreaded version of this algorithm that creates a separate thread to generate a number of random points. 
The thread will count the number of points that occur within the circle and store that result in a global variable. 
When this thread has exited, the parent thread will calculate and output the estimated value of π
the greater the number of points, the closer the approximation to π.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Number of points that occur within the circle
int ptsInside = 0;

// Thread function declaration
void *generatePoints(void *arg);

// Generates a double precision random number 
// Function given in assignment brief
double random_double(){
    return random() / ((double)RAND_MAX + 1);
}

// Main method
int main (int argc, char *argv[]){
    // Error handle in the event of incorrect arguments
    if (argc != 2){
        printf("Invalid number of arguments.");
        return -1;
    }

    int inputPts = atoi(argv[1]); // Number of points provided from cl arg
    // Error handle
    if (inputPts <= 0){
        printf("Invalid number of points.\n");
        return -1;
    }

    srandom(time(NULL)); // Seed random num generator

    // Two worker threads to calculate the total number of points and the number of points inside the circle
    pthread_t calc_tid1, calc_tid2; // Create the two threads
    int npoints = inputPts / 2; // Divide the work amongst them
    
    // Create ints to start. Use pointer to alocate dynamically
    int *result1, *result2;

    // Allocate memory for results before passing them to threads
    result1 = (int *)malloc(sizeof(int));
    result2 = (int *)malloc(sizeof(int));

    // Create thread 1
    if (pthread_create(&calc_tid1, NULL, generatePoints, &npoints) != 0){
        printf("Error creating first calc_tid thread.\n");
        return -1;
    }

    // Create thread 2
    if (pthread_create(&calc_tid2, NULL, generatePoints, &npoints) != 0){
        printf("Error creating second calc_tid thread.\n");
        return -1;
    }

    // Wait for both threads to finish and get results from the threads
    pthread_join(calc_tid1, (void **)&result1);
    pthread_join(calc_tid2, (void **)&result2);

    ptsInside = *result1 + *result2; // put in the global variable 
    
    // Estimate π using the formula: π ≈ 4 * (points inside circle / total points)
    double piEst = 4.0 * ptsInside / inputPts;

    printf("Estimated Pi = %f\n", piEst);

    // Free the memory
    free(result1);
    free(result2);

    return 0;
}

void *generatePoints(void *arg){
    int npoints = *((int *)arg); // Assign and derefence, typecast arg to an integer 
    int *hit_count = (int *)malloc(sizeof(int));  // Allocate memory to store result
    *hit_count = 0;

    // Code given in assignment brief
    for (int i = 0; i < npoints; i++) {
        /* generate random numbers between -1.0 and +1.0 (exclusive) */
        double x = random_double() * 2.0 - 1.0;
        double y = random_double() * 2.0 - 1.0;

        if (sqrt(x*x + y*y) < 1.0) { // If lies within the circle
            (*hit_count)++;
        }
    }
    // return result to parent thread
    pthread_exit(hit_count); 
}
