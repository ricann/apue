#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREAD_NUM      10

int cnt;

pthread_mutex_t mtx;
pthread_cond_t cond;

void *doit(void *vptr);
void send_frame();
void init_mutex();
void init_cond();

int main()
{
    pthread_t tid[MAX_THREAD_NUM];

    cnt = 0;

    init_mutex();
    init_cond();

    // create 10 threads
    for(int i=0; i<MAX_THREAD_NUM; i++) {
        if(pthread_create(&tid[i], NULL, &doit, NULL) != 0) {
            printf("create thread %d error!\n", i);
            exit(1);
        }

    }

    // join threads
    for(int i=0; i<MAX_THREAD_NUM; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}

void *doit(void *vptr)
{
    int dosig = 0;

    for(int i=0; i<5; i++) {
        send_frame();


        pthread_mutex_lock(&mtx);
        cnt++;
        printf("%d\n", cnt);
        while(cnt>=1 && cnt<MAX_THREAD_NUM) {
            pthread_cond_wait(&cond, &mtx);
        }

        if(cnt == MAX_THREAD_NUM) {
            cnt = 0;
            dosig = 1;
            printf("\n");
        } else {
            dosig = 0;
        }
        pthread_mutex_unlock(&mtx);

        if(dosig)
            pthread_cond_broadcast(&cond);
    }

    return NULL;
}

void send_frame()
{
    /*
    pthread_mutex_lock(&mtx);
    printf("send frame: %d !\n", cnt);
    if(cnt+1 == MAX_THREAD_NUM)
        printf("\n");
    pthread_mutex_unlock(&mtx);
    //*/
}

void init_mutex()
{
	pthread_mutexattr_t mattr;

	pthread_mutexattr_init(&mattr);
	pthread_mutex_init(&mtx, &mattr);
}

void init_cond()
{
	pthread_condattr_t cattr;

	pthread_condattr_init(&cattr);
	pthread_cond_init(&cond, &cattr);
}
