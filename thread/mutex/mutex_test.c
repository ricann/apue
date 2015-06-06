
#include <pthread.h>
#include "libunp.h"
#include "mutex_test.h"

int counter;

int main()
{
  pthread_t tida, tidb;

  pthread_create(&tida, NULL, &doit, NULL);
  pthread_create(&tidb, NULL, &doit, NULL);

  pthread_join(tida, NULL);
  pthread_join(tidb, NULL);

  return 0;
}

void *doit(void *vptr)
{
  int i, val;

  for(i=0; i<NLOOP; i++) {
    val = counter;
    printf("%d: %d\n", (int)pthread_self(), val + 1);
    counter = val + 1;
  }

  return NULL;
}
