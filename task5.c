#include<stdio.h>

struct process {
	int pid;
	int bt;
	int wt;
	int tt;
	int prior;
} p[10], temp;

int main() {
	int i, j, n, totwt = 0, tottt = 0, arg1, arg2;
	printf("Enter the number of processes: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		p[i].pid = i;
		printf("Enter the burst time for process %d: ", p[i].pid);
		scanf("%d", &p[i].bt);
		printf("Enter the priority for process %d: ", p[i].pid);
		scanf("%d", &p[i].prior);
	}

	for (i = 1; i < n; i++) {
		for (j = i + 1; j <= n; j++) {
			if (p[i].prior > p[j].prior) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

	p[1].wt = 0;
	p[1].tt = p[1].bt;

	for (i = 2; i <= n; i++) {
		p[i].wt = p[i - 1].bt + p[i - 1].wt;
		p[i].tt = p[i].bt + p[i].wt;
	}

	printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for (i = 1; i <= n; i++) {
		printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
		totwt += p[i].wt;
		tottt += p[i].tt;
	}

	arg1 = totwt / n;
	arg2 = tottt / n;
	printf("\narg1 = %d\targ2 = %d\n", arg1, arg2);

	return 0;
}
