#include<stdio.h>

struct Process {
    int pid;   // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int rt;    // Remaining Time
    int wt;    // Waiting Time
    int tat;  // Turnaround Time
};

void swap(Process* xp, Process* yp)
{
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(Process* proc, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++)
            if (proc[j].at > proc[j+1].at)
                swap(&proc[j], &proc[j+1]);
}

int main()
{
    int n, i, j, t, total_bt = 0, complete = 0;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        proc[i].pid = i+1;
        printf("Enter arrival time: ");
        scanf("%d", &proc[i].at);
        printf("Enter burst time: ");
        scanf("%d", &proc[i].bt);
        proc[i].rt = proc[i].bt;
        total_bt += proc[i].bt;
    }

    sort(proc, n);

    printf("\nGantt Chart:\n");
    for (t = 0; t < total_bt; ) {
        int min_rt = 9999, min_pid = -1;
        for (i = 0; i < n; i++) {
            if (proc[i].at <= t && proc[i].rt < min_rt && proc[i].rt > 0) {
                min_rt = proc[i].rt;
                min_pid = i;
            }
        }

        if (min_pid == -1) {
            printf("| IDLE |");
            t++;
            continue;
        }

        printf("| P%d  |", proc[min_pid].pid);

        proc[min_pid].rt--;

        if (proc[min_pid].rt == 0) {
            complete++;

            int finish = t + 1;

            proc[min_pid].tat = finish - proc[min_pid].at;
            proc[min_pid].wt = proc[min_pid].tat - proc[min_pid].bt;

            avg_tat += proc[min_pid].tat;
            avg_wt += proc[min_pid].wt;
        }

        t++;
    }

    printf("\n");

    avg_tat /= n;
    avg_wt /= n;

    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f", avg_tat);

    return 0;
}
