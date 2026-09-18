#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile sig_atomic_t alarm_fired = 0;
volatile sig_atomic_t alarm_count = 0;
time_t start_time;

void alarm_handler(int signum) {
    printf("Hello World!\n");
    alarm_count++;
    alarm_fired = 1;
}

void int_handler(int signum) {
    time_t end_time = time(NULL);
    printf("\nNumber of alarms: %d\n", alarm_count);
    printf("Total time executed: %ld seconds\n", (long)(end_time - start_time));
    exit(0);
}

int main(void) {
    start_time = time(NULL);
    signal(SIGALRM, alarm_handler);
    signal(SIGINT, int_handler);
    while (1) {
        alarm_fired = 0;
        alarm(1);
        while (!alarm_fired);
        printf("Turing was right!\n");
    }
    return 0;
}
