#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 




void monteCarlo(int N, int K)
{
	// Stores X and Y coordinates
	// of a random point
	double x, y;
	// Stores distance of a random
	// point from origin
	double d;

	// Stores number of points
	// lying inside circle
	int pCircle = 0;

	// Stores number of points
	// lying inside square
	int pSquare = 0;

	int i = 0;

	// Parallel calculation of random
	// points lying inside a circle
	clock_t start2 = clock();
	#pragma omp parallel for  num_threads(K)
	{
		
		// Initializes random points
		// with a seed
		srand(time(NULL));

		for (i = 0; i < N; i++) {
			// Finds random X co-ordinate
			x = (double)rand()/RAND_MAX;

			// Finds random X co-ordinate
			y = (double)rand()/RAND_MAX;

			// Finds the square of distance
			// of point (x, y) from origin
			float d = sqrt((x*x) + (y*y));

			// If d is less than or
			// equal to 1
			if (d <= 1) {
				// Increment pCircle by 1
				pCircle++;
			}
			// Increment pSquare by 1
			pSquare++;
		}
	}
	clock_t stop2 = clock();
	double elapsed1 = (double)(stop2 - start2) / CLOCKS_PER_SEC;
	printf("Time paralelo: %f", elapsed1);

	// Stores the estimated value of PI
	double pi = 4.0 * ((double)pCircle / (double)(pSquare));

	// Prints the value in pi
	printf("Final Estimation of Pi = %f\n", pi);
}


int main()
{
	clock_t start1 = clock();
	// Input
	int N = 1000000;
	int K = 12;
	// Function call
	
	monteCarlo(N, K);
	
	clock_t stop = clock();


	double elapsed = (double)(stop - start1) / CLOCKS_PER_SEC;
	printf("Time total: %f", elapsed);
}
