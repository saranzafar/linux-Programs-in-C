
#include<stdio.h>

struct process {
	int pid;
	int bt;
	int wt;
	int tt;
} p[10], temp;

int main() {
	int i, j, n, totwt = 0, tottt = 0;
	float avg1, avg2;
	printf("\nEnter the number of processes:\t");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		p[i].pid = i + 1;
		printf("\nEnter the burst time for process %d:\t", p[i].pid);
		scanf("%d", &p[i].bt);
	}

	// Sorting processes based on burst time using Bubble Sort
	for(i = 0; i < n - 1; i++) {
		for(j = 0; j < n - i - 1; j++) {
			if(p[j].bt > p[j + 1].bt) {
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}

	p[0].wt = 0;
	p[0].tt = p[0].bt;

	for(i = 1; i < n; i++) {
		p[i].wt = p[i - 1].bt + p[i - 1].wt;
		p[i].tt = p[i].bt + p[i].wt;
		totwt += p[i].wt;
		tottt += p[i].tt;
	}

	avg1 = (float)totwt / n;
	avg2 = (float)tottt / n;

	printf("\nProcess id\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i = 0; i < n; i++) {
		printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
	}
	printf("\nAverage Waiting Time: %f\n", avg1);
	printf("Average Turnaround Time: %f\n", avg2);

	return 0;
}
