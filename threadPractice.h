//
// Created by Tommy Lea on 6/27/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#ifndef THREADPRACTICE_THREADPRACTICE_H
#define THREADPRACTICE_THREADPRACTICE_H

struct data
{
    char *name;
    char *writeBuf;
    size_t len;
};


static void * writeThread(void *arg);

#endif //THREADPRACTICE_THREADPRACTICE_H
