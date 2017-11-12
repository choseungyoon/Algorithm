//
//  Semaphore.cpp
//  Algorithm
//
//  Created by seungyun cho on 2017. 11. 11..
//  Copyright © 2017년 seungyun cho. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

void Error(const char*mes);
int number = 0; // 일반 출력변수
sem_t bin_sem; // 세마포어 생성
void *sem_snd(void *arg);
void *sem_rev(void *arg);

int main(){
    
    int state = 0;
    pthread_t t1,t2,t3; //3개의 스레드 선언
    char thread1[] = "Thread_A";
    char thread2[] = "Thread_B";
    char thread3[] = "Thread_C";
    void *result_t = NULL;
    
    /*
    
     sem_init(sem_t *sem, int pshared, unsigned int value);
     
     sem가 가리키는 세마포어 객체를 초기화한다.
     아래 초기화문제에서는 세번째 인자 1로 객체가 초기화 뫼여, 두번째 인자 0은
     세마포어가 현재 프로세스에서만사용될지(현재 프로세스에서만 사용  = 0)
     아니면 여러 프로세스간에 공유될지 지정한다.
     LinuxThreads는 세마포어가 여러 프로세스 간에 공유되는 것을 지원하지 않기 때문에
     두번째 인자가 0이 아닐 경우 sem_init는 항상 ENOSYS 에러코드를 반환한다.
     
    */
    
    state = sem_init(&bin_sem, 0, 0); //최초으로 세팅
    if(state != 0) Error("sem_init Error\n");
    pthread_create(&t1, NULL, sem_snd, thread1); // 쓰레드1 생성
    pthread_create(&t2, NULL, sem_rev, thread2); // 쓰레드2 생성
    pthread_create(&t3, NULL, sem_rev, thread3); // 쓰레드3 생성
    
    pthread_join(t1, &result_t); //쓰레드가 종료되기를 기다린 ㅎ 메인 프로세스가 종료되도록
    pthread_join(t2, &result_t); //pthread_join을 호출
    pthread_join(t3, &result_t); //그 결과는 3개의 쓰레드 동작이 모두 종료되고 메인 프로세스가종료된다.
    
    printf("Final Number : %d\n", number);
    
    sem_destroy(&bin_sem);
    return 0;
}

void *sem_snd(void *arg){
    int i=0;
    for(i =0;i<4;i++){
        while(number !=0) sleep(1);
        number++;
        printf("%s Running %d\n", (char*)arg, number);
        sem_post(&bin_sem); //세마포어 값을 하나 증가시킨다.
    }
}

void *sem_rev(void *arg){
    int i=0;
    for(i=0;i<2;i++){
        sem_wait(&bin_sem); //세마포어 값을 하나 감소시킨다
        number--;
        printf("%s Running : %d\n", (char*)arg, number);
    }
}

void Error(const char *mes)
{
    printf("%s\n",mes);
    exit(0);
}
