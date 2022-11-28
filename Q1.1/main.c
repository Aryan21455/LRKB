#include <math.h>
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void f_append(float t) {
  FILE *fp;
  fp = fopen("Output.txt", "a");
  fprintf(fp, "%f\n", t);
  fclose(fp);
}

void *countA() {
  long long int l;
  long long int a = 0;
  for (l = 1; l <= 4294967296; l++) {
    // a++;
  }
}
void *countB() {
  long long int l;
  long long int a = 0;
  for (l = 1; l <= 4294967296; l++) {
    // a++;
  }
}

void *countC() {
  long long int l;
  long long int a = 0;
  for (l = 1; l <= 4294967296; l++) {
    // a++;
  }
}
int main() {

  pthread_t A;
  pthread_t B;
  pthread_t C;
  struct timespec start;
  struct timespec stop;
  struct sched_param pmeter;

  clock_gettime(CLOCK_REALTIME, &start);

  pthread_create(&A, NULL, countA, NULL);
  pthread_create(&A, NULL, countB, NULL);
  pthread_create(&A, NULL, countC, NULL);
  pthread_setschedparam(A, SCHED_OTHER, &pmeter);
  pthread_join(A, NULL);

  clock_gettime(CLOCK_REALTIME, &stop);

  double t = ((double)(stop.tv_nsec - start.tv_nsec)) / CLOCKS_PER_SEC;
  f_append(t);

  clock_gettime(CLOCK_REALTIME, &start);

  pthread_create(&B, NULL, countA, NULL);
  pthread_create(&B, NULL, countB, NULL);
  pthread_create(&B, NULL, countC, NULL);
  pthread_setschedparam(B, SCHED_RR, &pmeter);

  pthread_join(B, NULL);

  clock_gettime(CLOCK_REALTIME, &stop);

  t = ((double)(stop.tv_nsec - start.tv_nsec)) / CLOCKS_PER_SEC;
  f_append(t);

  clock_gettime(CLOCK_REALTIME, &start);

  pthread_create(&C, NULL, countA, NULL);
  pthread_create(&C, NULL, countB, NULL);
  pthread_create(&C, NULL, countC, NULL);
  pthread_setschedparam(C, SCHED_FIFO, &pmeter);
  pthread_join(C, NULL);

  clock_gettime(CLOCK_REALTIME, &stop);

  t = ((double)(stop.tv_nsec - start.tv_nsec)) / CLOCKS_PER_SEC;
  f_append(t);

 

  for (int i = 1; i<= 6;i++) {


    clock_gettime(CLOCK_REALTIME, &start);

    pthread_create(&A, NULL, countA, NULL);
    pthread_create(&A, NULL, countB, NULL);
    pthread_create(&A, NULL, countC, NULL);
    pthread_setschedparam(A, SCHED_OTHER, &pmeter);
    nice(0);
    pthread_join(A, NULL);

    clock_gettime(CLOCK_REALTIME, &stop);
 
    t = ((double)(stop.tv_nsec - start.tv_nsec)) / CLOCKS_PER_SEC;
    f_append(t);

    clock_gettime(CLOCK_REALTIME, &start);
    pthread_setschedprio(B, i);
    pthread_join(B, NULL);
    clock_gettime(CLOCK_REALTIME, &stop);

    t = ((double)(stop.tv_nsec - start.tv_nsec)) / CLOCKS_PER_SEC;
    f_append(t);

    clock_gettime(CLOCK_REALTIME, &start);
    pthread_setschedprio(C,i);
    pthread_join(C, NULL);
    clock_gettime(CLOCK_REALTIME, &stop);

    t = ((double)(stop.tv_nsec - start.tv_nsec)) / CLOCKS_PER_SEC;
    f_append(t);
  }
  exit(0);
}