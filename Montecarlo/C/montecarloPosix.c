#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>
#define NUM_THREADS 12         //number of threads
#define TOT_COUNT 1000000      //total number of iterations



/**
Task of threads
**/
void *doCalcs(void *threadid)
{
   srand(time(NULL));
   long longTid= (long)threadid;

      
   int tid = (int)longTid;       //obtain the integer value of thread id

   //using malloc for the return variable in order make
   //sure that it is not destroyed once the thread call is finished
   float *in_count = (float *)malloc(sizeof(float));
   *in_count=0;
   
   //get the total number of iterations for a thread
   float tot_iterations= TOT_COUNT/NUM_THREADS;
   
   int counter=0;
   
   //calculation
   for(counter=0;counter<tot_iterations;counter++){
      float x = (double)rand()/RAND_MAX;
      float y = (double)rand()/RAND_MAX;
      
      float result = sqrt((x*x) + (y*y));
      
      if(result<1){
         *in_count+=1;         //check if the generated value is inside a unit circle
      }
      
   }
   
   //get the remaining iterations calculated by thread 0
   if(tid==0){
      float remainder = TOT_COUNT%NUM_THREADS;
      
      for(counter=0;counter<remainder;counter++){
      float x = (double)rand()/RAND_MAX;
      float y = (double)rand()/RAND_MAX;
      
      float result = sqrt((x*x) + (y*y));
      
      if(result<1){
         *in_count+=1;         //check if the generated value is inside a unit circle
      }
      
   }
   }


   
   
   pthread_exit((void *)in_count);     //return the in count
}

int main(int argc, char *argv[])
{
   clock_t start = clock();
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   void *status;
   float tot_in=0;
   
   
   clock_t start2 = clock();
   for(t=0;t<NUM_THREADS;t++){
     rc = pthread_create(&threads[t], NULL, doCalcs, (void *)t);

     }

   //join the threads
   for(t=0;t<NUM_THREADS;t++){
           
      pthread_join(threads[t], &status);
      //printf("Return from thread %ld is : %f\n",t, *(float*)status);
      
      tot_in+=*(float*)status;            
     
     }
     printf("Value for Pi is %f \n", 4*(tot_in/TOT_COUNT));
   
   clock_t stop = clock();
   double elapsed2 = (double)(stop - start2) / CLOCKS_PER_SEC;
   printf("Time2:  %f\n", elapsed2);
   double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
   printf("Time: %f", elapsed);

   pthread_exit(NULL);
}