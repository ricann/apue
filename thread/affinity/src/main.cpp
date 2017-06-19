#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#include <iostream>
#include <thread>

#include "arith.h"

using namespace std;

void func1();
void func2();
void func();

int main()
{
    thread thr1 = thread(&func1);
    thread thr2 = thread(&func2);

    thr1.join();
    thr2.join();

    return 0;
}

void func1()
{
    cpu_set_t mask;
    cpu_set_t get;
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
    cpu_set_t get;
    CPU_ZERO(&mask);
    CPU_SET(1, &mask);

    cout << "thread2 tart..." << endl;

    if(sched_setaffinity(0, sizeof(mask), &mask) == -1)
        cout << "warning: could not set CPU affinity, continuing..." << endl;

    func();
}

void func()
{
    int size = 65536;
    signed char *vecA_s8 = new signed char [size];
    float *vecA_f = new float [size];
    float *vecB = new float [size];
    float *vecC = new float [size];

    // use rand() to assign value to vecA
    // store vecA by column order
    cout << "generating vector ..." << endl;
    for(int i=0; i<size; i++) {
        vecA_s8[i] = rand() % 128;
        if(vecA_s8[i]%2 == 0)
            vecA_s8[i] = -vecA_s8[i];
        vecA_f[i] = (float)vecA_s8[i];

        vecB[i] = (rand() % 1024) / 128.0;
        vecC[i] = (rand() % 1024) / 64.0;
    }
    cout << "generating vector over!" << endl;

    //*/
    for(int i=0; i<10000; i++)
        vecxvec_add_vec_s8ff(vecA_s8, vecB, vecC, size);
    //*/

    delete []vecA_s8;
    delete []vecA_f;
    delete []vecB;
    delete []vecC;
}
