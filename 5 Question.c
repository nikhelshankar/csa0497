#include<stdio.h>
struct priority_scheduling {
    char process_name;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    int priority;
};
int main() 
{
	int i,j;
    int number_of_process;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    float average_waiting_time;
    float average_turnaround_time;

    printf("Enter the total number of Processes: ");
    scanf("%d", &number_of_process);

    struct priority_scheduling process[number_of_process];

    printf("\nPlease Enter the Burst Time and Priority of each process:\n");

    for (i = 0; i < number_of_process; i++) 
	{
        printf("\nEnter the details of the process %d\n", i + 1);

        process[i].process_name = 'A' + i;

        printf("Enter the burst time: ");
        scanf("%d", &process[i].burst_time);

        printf("Enter the priority: ");
        scanf("%d", &process[i].priority);
    }

    for (i = 0; i < number_of_process - 1; i++) 
	{
        for (j = 0; j < number_of_process - i - 1; j++) 
		{
            if (process[j].priority < process[j + 1].priority) 
			{
                struct priority_scheduling temp_process = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp_process;
            }
        }
    }

    process[0].waiting_time = 0;
    process[0].turn_around_time = process[0].burst_time;

    for (i = 1; i < number_of_process; i++) 
	{
        process[i].waiting_time = process[i - 1].waiting_time + process[i - 1].burst_time;
        process[i].turn_around_time = process[i].waiting_time + process[i].burst_time;
    }

    for (i = 0; i < number_of_process; i++) 
	{
        total_waiting_time += process[i].waiting_time;
        total_turnaround_time += process[i].turn_around_time;
    }

    average_waiting_time = (float)total_waiting_time / number_of_process;
    average_turnaround_time = (float)total_turnaround_time / number_of_process;

    printf("\n\nProcess_name \t Burst Time \t Waiting Time \t Turnaround Time\n");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < number_of_process; i++) 
	{
        printf("\t %c \t\t %d \t\t %d \t\t %d\n", process[i].process_name, process[i].burst_time, process[i].waiting_time, process[i].turn_around_time);
        printf("-----------------------------------------------------------\n");
    }

    printf("\n\n Average Waiting Time : %f", average_waiting_time);
    printf("\n Average Turnaround Time: %f\n", average_turnaround_time);

    return 0;
}
