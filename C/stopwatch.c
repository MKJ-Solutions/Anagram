/*
 * File: stopwatch.c
 * Author: Miles Tjandrawidjaja
 * Last Updated: 01/12/2013
 * ===============================
 * Description: This file is use as a stopwatch
 *
 * Notes: When compiling use -pthred
 *        Example gcc stopwatch.c -pthread -o stopwatch
 */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

struct StopWatch{
    bool isOn;
    clock_t start,end;
};
typedef struct StopWatch StopWatch;

StopWatch *InitTimer();
void StartTimer( StopWatch *stopwatch );
void EndTimer  ( StopWatch *stopwatch );
void *threadFunc(void *seconds);
void CountDown(int time_sec);
double getTimer( StopWatch *stopwatch );

main(void){

    //CountDown(6);
    //Hang Program
    //while(1);

    
    /* Showing what happens when you forget the start the timer and when you actually start the timer */
    StopWatch *stopwatch = InitTimer();
    sleep(1);
    printf( "%g seconds have now passed\n", getTimer(stopwatch));
    StartTimer(stopwatch);
    sleep(3);
    printf( "%g seconds have now passed\n", getTimer(stopwatch));
    EndTimer(stopwatch);

    /* Forgot why I have the stuff below 
    clock_t start, end;
    double elasped;
    Return the current time
    time_t current_time= time(NULL);
    printf("Current time is %s", ctime(&current_time));
    start = clock;
    clock(void) return the proccessor time
    clock(void)/CLOCKS_PER_SEC gets time in seconds
    end = clock();
    printf(" Took %ld ticks \n", end-start);
    elasped = ((double) (end - start)) / CLOCKS_PER_SEC;
    */
    return 0;
}

/*
 * Function: InitTimer
 * Usage:    Stopwatch *stopwatch = InitTimer();
 * -----------------------------------------------
 *  This function initializes a stopwatch
 */

StopWatch *InitTimer(){
    StopWatch *stopwatch = (StopWatch *) malloc(sizeof(StopWatch));
    stopwatch -> isOn = false;
    return stopwatch;
}

/*
 * Function: StartTimer
 * Usage:    StartTimer(stopwatch);
 * -----------------------------------------------
 *  This function started the stopwatch
 */
void StartTimer( StopWatch *stopwatch){
    stopwatch -> isOn = 1;
    time( &( stopwatch -> start ) );
}

/*
 * Function: getTimer
 * Usage:    getTimer(stopwatch);
 * ----------------------------------------------------------------------
 *  This function returns how much time has past since the timer started
 */
double getTimer( StopWatch *stopwatch ){
    if (!(stopwatch -> isOn ))
        return -1.0;
    return ( difftime( time(NULL) , stopwatch->start ) );
}

/*
 * Function: EndTimer
 * Usage:    EndTimer(stopwatch);
 * ----------------------------------------------------------------------
 *  This function stops the stopwatch
 */
void EndTimer( StopWatch *stopwatch){
    stopwatch -> isOn = false;
    time( &( stopwatch -> end ) );
}

/*
 * Function: threadFunc
 * Usage:    pthread_create(&pthread_t , threadFunc, int *)
 * ----------------------------------------------------------------------
 *  This function Counts the given time in seconds down to zero in a seperate thread
 */
void *threadFunc(void *seconds){
    int secs = seconds;
    while ( secs > 0 ){
        printf("%d\n", secs);
        sleep(1);
        --secs;
    }
    return NULL;
}

/*
 * Function: CountDown
 * Usage:    CountDown( int )
 * ----------------------------------------------------------------------
 *  This function initializes the countdown to zero
 */
void CountDown(int time_sec){
    pthread_t pth; // Thread identifier
    int i = 0;
    int *seconds = time_sec;
    pthread_create(&pth,NULL,threadFunc,seconds);

    //Below will hold up proccesses
    //pthread_join(pth, NULL /* void ** return value could go here */);

}
