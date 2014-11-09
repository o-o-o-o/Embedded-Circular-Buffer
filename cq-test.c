#include <stdio.h>
#include <stdlib.h>
#include "circular-queue.h"

int main(int argc, char* argv[])
{
    int i = 0;

    int m_int = 0;
    float m_float = 0.0;
    char m_char = 0;

    circularbuffer buff1;
    unsigned char init1 = InitializeBuffer(&buff1);

    circularbuffer buff2;
    unsigned char init2 = InitializeBuffer(&buff2);

    printf("Buffer1 queue size is %d, initialization %s\n", QUEUE_SIZE, init1?"Succeeded":"Failed");
    printf("Buffer2 queue size is %d, initialization %s\n", QUEUE_SIZE, init2?"Succeeded":"Failed");

    membertype dequeue;
    membertype member1 = { .member_int = 100, .member_float = 1.55, .member_char = 77};
    membertype member2 = { .member_int = 101, .member_float = 2.55, .member_char = 77};
    membertype member3 = { .member_int = 102, .member_float = 3.55, .member_char = 77};
    membertype member4 = { .member_int = 103, .member_float = 4.55, .member_char = 77};

    printf("Attempting to add member %d to buffer 1...\n", 0);
    if (AddMember(&buff1, &member1)){
        printf("Success!\n");
    }
    printf("Attempting to add member %d to buffer 2...\n", 1);
    if (AddMember(&buff1, &member2)){
        printf("Success!\n");
    }

    printf("Attempting to add member %d to buffer 1...\n", 0);
    if (AddMember(&buff2, &member3)){
        printf("Success!\n");
    }
    printf("Attempting to add member %d to buffer 2...\n", 1);
    if (AddMember(&buff2, &member4)){
        printf("Success!\n");
    }

    for(i = 2; i< 275; i++){
        m_int += 10;
        m_float += 1.001;
        m_char += 1;

        membertype iter = { .member_int = m_int, .member_float = m_float, .member_char = m_char};

        printf("Attempting to add member %d to buffer 1...\n", i);
        if (AddMember(&buff1, &iter)){ 
            printf("Success!\n");
        }

        if (BufferFull(&buff1)) printf("Buffer Now Full\n");
        if (BufferEmpty(&buff1)) printf("Buffer Now Empty\n");
    }

        
    for(i = 0; i < 300; i++){
        printf("Attempting to remove member %d from buffer 1...\n", i);
        if (SubtractMember(&buff1, &dequeue)){
            printf("Success!\n");
        }

        printf("\tint: %d\n", dequeue.member_int);
        printf("\tfloat: %f\n", dequeue.member_float);
        printf("\tfloat: %d\n", (int)dequeue.member_char);

        if (BufferFull(&buff1)) printf("Buffer Full\n");
        if (BufferEmpty(&buff1)) printf("Buffer Empty\n");
    }

    printf("Freeing buffer 1\n");
    FreeBuffer(&buff1);

    printf("Freeing buffer 2\n");
    FreeBuffer(&buff2);

    return 1;
}
