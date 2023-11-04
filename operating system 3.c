#include<stdio.h>

int main() {
    int n, i;
    float avg_waiting_time = 0, total_waiting_time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int arrival_time[n], burst_time[n], completion_time[n], waiting_time[n];
    printf("Enter arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    // Sort processes based on arrival time
    for (i = 0; i < n - 1; i++) {
        int j, min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arrival_time[j] < arrival_time[min_index]) {
                min_index = j;
            }
        }
        int temp = arrival_time[i];
        arrival_time[i] = arrival_time[min_index];
        arrival_time[min_index] = temp;
        temp = burst_time[i];
        burst_time[i] = burst_time[min_index];
        burst_time[min_index] = temp;
    }
    // Calculate completion and waiting times
    completion_time[0] = burst_time[0];
    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
        waiting_time[i] = completion_time[i - 1] - arrival_time[i];
        if (waiting_time[i] < 0) {
            waiting_time[i] = 0;
        }
    }
    // Calculate total and average waiting times
    for (i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
    }
    avg_waiting_time = total_waiting_time / n;
    // Print results
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], waiting_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}
