#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define LOOPS 100000

pthread_mutex_t mutex;

static int shared = 0;

void *work(void *stub){
   int i;
   printf("Hello, world from %i\n", pthread_self());
   
   for(i=0; i<LOOPS; i++) {
      pthread_mutex_lock(&mutex);
      shared++;
      pthread_mutex_unlock(&mutex);
   }
   
   pthread_exit(NULL);
}

int main(int argc, char **argv){
   
   int i;
   pthread_t id[NUM_THREADS];

   pthread_mutex_init(&mutex, NULL);
   
   for(i = 0; i < NUM_THREADS; i++){
      if(pthread_create(&id[i], NULL, work, NULL)){
         printf("Error creating the thread\n"); exit(19);
      }
   }
   
   printf("After creating the thread. My id is: %i\n", 
   pthread_self());

   for(i=0; i<NUM_THREADS; i++)
   {
      pthread_join(id[i], NULL);
   }
   printf("Result is %i\n", shared);
   return 0;
}
