#include "threadPractice.h"

#define INMAXSIZE 40

int main(int argc, char **argv)
{
    pthread_t threadArr[2];
    int s;
    void *ret;

    char *buf = malloc(INMAXSIZE);
    memset(buf, 0, INMAXSIZE);

    read(0, buf, INMAXSIZE);

    struct data *myData = malloc(sizeof(struct data));
    myData->writeBuf = buf;
    myData->len = strlen(buf);

    myData->name = argv[1];
    pthread_create(&threadArr[0], NULL, writeThread, myData);
    myData->name = argv[2];
    pthread_create(&threadArr[1], NULL, writeThread, myData);

    for(int i = 0; i < 2; i++)
    {
        s = pthread_join(threadArr[i], &ret);
        if(ret != NULL)
        {
            printf("Thread %d has failed.", i+2);
        }
    }

    return 0;
}

static void * writeThread(void * arg)
{
    struct data *threadInfo = arg;

    FILE *writeFile1 = fopen(threadInfo->name, "w");

    int fd1 = fileno(writeFile1);

    write(fd1, threadInfo->writeBuf, threadInfo->len);

    fclose(writeFile1);
    return 0;
}