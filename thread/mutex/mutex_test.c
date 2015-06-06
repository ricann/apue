
#include "libunp.h"
#include "mutex_test.h"

int counter;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
  pthread_t tida, tidb;

  if(pthread_create(&tida, NULL, &doit, NULL) != 0)
    err_quit("pthread_create tida fail");

  if(pthread_create(&tidb, NULL, &doit, NULL) != 0)
    err_quit("pthread_create tidb fail");

  pthread_join(tida, NULL);
  pthread_join(tidb, NULL);

  return 0;
}

void *doit(void *vptr)
{
  int i, val;

  for(i=0; i<NLOOP; i++) {
    pthread_mutex_lock(&counter_mutex);
    val = counter;
    printf("%d: %d\n", (int)pthread_self(), val + 1);
    counter = val + 1;
    pthread_mutex_unlock(&counter_mutex);
  }

  return NULL;
}
