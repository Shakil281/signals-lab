#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t alarm_fired = 0;

void handler(int signum) {
    printf("Hello World!\n");
    alarm_fired = 1;
}

int main(void) {
    signal(SIGALRM, handler);
    while (1) {
        alarm_fired = 0;
        alarm(5);
        while (!alarm_fired);      /* wait for the alarm */
        printf("Turing was right!\n");
    }
    return 0;
}
