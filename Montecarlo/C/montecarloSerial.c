#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
    clock_t start = clock();
    double niter = 1000000;
    double x,y;
    int i;
    int count=0;
    double z;
    double pi;
    srand(time(NULL));
    
    //main loop
    for (i=0; i<niter; ++i)
    {
        //get random points
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        z = sqrt((x*x)+(y*y));
        //check to see if point is in unit circle
        if (z<=1)
        {
            ++count;
        }
    }
    pi = ((double)count/(double)niter)*4.0;          //p = 4(m/n)
    printf("Pi: %f\n", pi);
    clock_t stop = clock();
    double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time: %f", elapsed);
    return 0;
}