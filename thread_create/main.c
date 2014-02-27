#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

void *work(void *i){
   printf("Hello, world from %i\n", pthread_self());
   pthread_exit(NULL);
}

int main(int argc, char **argv){
   
   int i;
   pthread_t id[NUM_THREADS];
   
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
   return 0;
}
