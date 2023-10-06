#include <stdio.h>

struct process {
    int pid; // process id
    int bt;  // burst time
    int wt, tt; // turn around time
} p[10]; // array

int main() {
    int i, n, totwt = 0, tottt = 0;
    float avg1, avg2; // changed to float type

    printf("enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("enter the burst time: ");
        scanf("%d", &p[i].bt);
    }

    p[0].wt = 0;
    p[0].tt = p[0].bt + p[0].wt;

    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tt = p[i].bt + p[i].wt;
    }

    printf("\n processid \t bt\t wt\t tt\n");

    for (i = 0; i < n; i++) {
        printf("\n\t%d \t%d \t%d \t%d", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
        totwt += p[i].wt;
        tottt += p[i].tt;
    }

    avg1 = (float)totwt / n; // casting to float
    avg2 = (float)tottt / n; // casting to float

    printf("\navg1=%.2f \t avg2=%.2f\t", avg1, avg2); // printing with two decimal places

    return 0;
}
