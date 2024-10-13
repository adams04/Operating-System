#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrivalT;
    int burstT;
    int turnaroundT; 
    int waitingT;
    int responseT;
};

void calculate_times(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundT = processes[i].waitingT + processes[i].burstT;
        processes[i].responseT = processes[i].waitingT;
    }
}

void fcfs(struct Process processes[], int n) {
    printf("\nFCFS Scheduling\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalT > processes[j + 1].arrivalT) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int current_time = processes[0].arrivalT;
    float total_waitingT = 0, total_turnaroundT = 0, total_responseT = 0;

    for (int i = 0; i < n; i++) {
        processes[i].waitingT  = current_time - processes[i].arrivalT;
        current_time += processes[i].burstT;
        processes[i].turnaroundT  = processes[i].waitingT + processes[i].burstT;
        processes[i].responseT  = processes[i].waitingT;

        total_waitingT += processes[i].waitingT;
        total_turnaroundT += processes[i].turnaroundT;
        total_responseT += processes[i].responseT;
    }

    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].pid);
    }
    printf("\n\n");

    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", processes[i].pid, processes[i].arrivalT, processes[i].burstT,
               processes[i].waitingT, processes[i].turnaroundT, processes[i].responseT);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waitingT / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaroundT / n);
    printf("Average Response Time: %.2f\n", total_responseT / n);
}

void sjf(struct Process processes[], int n) {
    printf("\nSJF Scheduling\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstT > processes[j + 1].burstT ||
                (processes[j].burstT == processes[j + 1].burstT &&
                 processes[j].arrivalT > processes[j + 1].arrivalT)) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int current_time = 0;
    float total_waitingT= 0, total_turnaroundT = 0, total_responseT = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrivalT) {
            current_time = processes[i].arrivalT;
        }
        processes[i].waitingT = current_time - processes[i].arrivalT;
        current_time += processes[i].burstT;
        processes[i].turnaroundT = processes[i].waitingT + processes[i].burstT;
        processes[i].responseT = processes[i].waitingT;

        total_waitingT += processes[i].waitingT;
        total_turnaroundT += processes[i].turnaroundT;
        total_responseT += processes[i].responseT;
    }

    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].pid);
    }
    printf("\n\n");

   
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", processes[i].pid, processes[i].arrivalT, processes[i].burstT,
               processes[i].waitingT, processes[i].turnaroundT, processes[i].responseT);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waitingT / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaroundT / n);
    printf("Average Response Time: %.2f\n", total_responseT / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
   
    for (int i = 0; i < n; i++) {
        printf("\nEnter the arrival time and burst time for process  %d ", i + 1);
        processes[i].pid = i + 1;
        scanf("%d", &processes[i].arrivalT);
        scanf("%d", &processes[i].burstT);
    }

    fcfs(processes, n);
    sjf(processes, n);

    return 0;
}

