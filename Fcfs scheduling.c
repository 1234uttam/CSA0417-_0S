#include<stdio.h>

struct Process{
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

int main(){
    int i,j,n = 3;
    struct Process p[n];
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    //Initialize the processes
    for(i=0; i<n; i++){
        p[i].pid = i;
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &p[i].burst_time);
        p[i].arrival_time = 0;
    }

    //Calculate waiting time and turnaround time
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    for(i=1; i<n; i++){
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    //Calculate average waiting time and average turnaround time
    for(i=0; i<n; i++){
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    //Display results
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    return 0;
}
