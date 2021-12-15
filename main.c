#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <sys/types.h>//dd

#include <pthread.h>
#include <time.h>

void* timer(){
	struct timespec timerr = {1,000000000};
	struct timespec timerost;
	printf("\033[K");
	printf("%s\n"," -- ");
	nanosleep (&timerr, &timerost);
	printf("\033[1A");
	printf("%s\n","  | ");
	nanosleep (&timerr, &timerost);
	printf("\033[1A");
	pthread_exit(0);
}

void* mem(void *p){
	float *ptrs = (float*)malloc(1000); 
	realloc(ptrs, 0);
	sleep(1);
	pthread_exit(0);
	
}

void* mem2(){
	float *ptr = (float*)malloc(1000);  
	pthread_exit(0);
}

int  main(int argc, char *argv[]) {
	if (argc <= 1) {
		if (argv[0]){
			printf("%s\n",argv[0]);
			printf("%s\n","no arguments!");
		}
		else
			printf("%s\n","Net argv0");
	}
	printf("PID__ %d\n", (int)getpid());
	if (argc > 1) {
		printf("%s\n","yes arg");
	        for (int i = 1; i < argc; i++) {
            		if (strncmp (argv[1],"-a",2) == 0) {
				printf("%s%s\n",argv[i]," - zapusk piloobraznii neitralnii");
				pthread_t* thread = (pthread_t*) malloc(5*sizeof(pthread_t));
				pthread_create(&(thread[0]), NULL, timer, NULL);
				int k;
				int gg=0;
    				do	{
					for (k = 1; k < 5; k ++) {
						pthread_create(&(thread[k]), NULL, mem, (void *)(size_t)k);}	
					pthread_join(thread[0], NULL);
					gg = gg+1;
  					for (k = 1; k < 5; k ++) {
    						pthread_detach(thread[k]);}
					pthread_create(&(thread[0]), NULL, timer, NULL);
    				}
				while(gg != 0);
				free(thread);
           		}
			if (strncmp (argv[1],"-b",2) == 0) {
				printf("%s%s\n",argv[i]," - zapusk piloobraznii rastushii");
				pthread_t* thread = (pthread_t*) malloc(2*sizeof(pthread_t));
				pthread_create(&(thread[0]), NULL, timer, NULL);
				int gg=0;
    				do	{			
					pthread_join(thread[0], NULL);
					pthread_create(&(thread[1]), NULL, mem2, NULL);
					gg = gg+1;
					pthread_detach(thread[1]);
					pthread_create(&(thread[0]), NULL, timer, NULL);
    				}
				while(gg != 0);
				free(thread);
			}
			if ((strncmp (argv[1],"-a",2) != 0) && (strncmp (argv[1],"-b",2) != 0)) {
				printf("%s%s%s\n"," argument not found- '", argv[i], "'");
			}
		}
	}
	return 0;
}