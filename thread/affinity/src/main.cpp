#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#include <iostream>
#include <thread>

#include "arith.h"
#include "matrix.h"

#define BUF_NUM     128

using namespace std;

int n_kb = 0;
int n_thr = 0;
int n_arr = 0;

void func1();
void func2();
void func();

int main(int argc, char *argv[])
{
    n_kb = atoi(argv[1]);
    n_thr = atoi(argv[2]);
    n_arr = atoi(argv[3]);

    thread *thr1;
    thread *thr2;

    if(n_thr == 1) {
        thr1 = new thread(&func1);
        thr1->join();
    } else {
        thr1 = new thread(&func1);
        thr2 = new thread(&func2);

        thr1->join();
        thr2->join();
    }

    return 0;
}

void func1()
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(0, &mask);

    cout << "thread1 tart..." << endl;

    if(sched_setaffinity(0, sizeof(mask), &mask) == -1)
        cout << "warning: could not set CPU affinity, continuing..." << endl;

    func();
}

void func2()
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(1, &mask);

    cout << "thread2 tart..." << endl;

    if(sched_setaffinity(0, sizeof(mask), &mask) == -1)
        cout << "warning: could not set CPU affinity, continuing..." << endl;

    func();
}

void func()
{
    int size = 1024*n_kb;
    signed char *vecA_s8 = new signed char [size];
    float *vecA_f[BUF_NUM];
    for(int i=0; i<BUF_NUM; i++)
        vecA_f[i] = new float [size];
    float *vecB = new float [size];
    float *vecC = new float [size];

    // use rand() to assign value to vecA
    // store vecA by column order
    cout << "generating vector ..." << endl;
    for(int i=0; i<size; i++) {
        vecA_s8[i] = rand() % 128;
        if(vecA_s8[i]%2 == 0)
            vecA_s8[i] = -vecA_s8[i];
        for(int j=0; j<BUF_NUM; j++)
            vecA_f[j][i] = (float)vecA_s8[i];

        vecB[i] = (rand() % 1024) / 128.0;
        vecC[i] = (rand() % 1024) / 64.0;
    }
    cout << "generating vector over!" << endl;
    //*/
    
    for(int i=0; i<100000; i++) {
        if(n_arr == 1) {
            vecxvec_add_vec_fff(vecA_f[0], vecB, vecC, size);
        } else {
            vecxvec_add_vec_fff(vecA_f[i%BUF_NUM], vecB, vecC, size);
        }
    }

    delete []vecA_s8;
    for(int i=0; i<BUF_NUM; i++)
        delete [] vecA_f[i];
    delete []vecB;
    delete []vecC;
}

