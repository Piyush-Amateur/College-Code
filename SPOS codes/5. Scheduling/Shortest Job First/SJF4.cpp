#include <iostream>
#include <string>
#include <algorithm>
#define INT_MAX 999

using namespace std;

void SJF_preemptive(int n, int burst_time[], string p[], int arrival_time[]) {
    int finish_time[10] = {0};
    int turnaround_time[10] = {0};
    int waiting_time[10] = {0};
    int remaining_time[10];
    copy(burst_time, burst_time + n, remaining_time);

    float avg_turnaround_time = 0, avg_waiting_time = 0;
    
    int current_time = 0;
    int completed = 0;

    int exe_ord[10],curr_time[10],exe_ind=0;

    
    while (completed < n) {
        int shortest_job = -1;
        int shortest_time = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && remaining_time[i] < shortest_time && remaining_time[i] > 0) {
                shortest_job = i;
                shortest_time = remaining_time[i];
            }
        }
        
        if(shortest_job != exe_ord[exe_ind-1]){
            exe_ord[exe_ind]=shortest_job;
            curr_time[exe_ind] = current_time;
            exe_ind++;
        }
        

        if (shortest_job == -1) {
            current_time++;
        } else {
            
            remaining_time[shortest_job]--;
            current_time++;
            
            if (remaining_time[shortest_job] == 0) {
                completed++;
                finish_time[shortest_job] = current_time;
                turnaround_time[shortest_job] = finish_time[shortest_job] - arrival_time[shortest_job];
                waiting_time[shortest_job] = turnaround_time[shortest_job] - burst_time[shortest_job];
            }
        }
    }
    cout<<"GANTT-CHART"<<endl;
    for (int i = 0; i <exe_ind; i++)
    {
        cout<<"|   P"<<exe_ord[i]+1<<"\t";
    }
    cout<<"|"<<endl;
    for (int i = 0; i < exe_ind; i++)
    {
        cout<<curr_time[i]<<"\t";
    }
    cout<<current_time<<endl;

    for (int i = 0; i < n; i++) {
        avg_turnaround_time += turnaround_time[i];
        avg_waiting_time += waiting_time[i];
    }

    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    cout << "\nTURNAROUND TIME " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Turnaround time of P" << i + 1 << " = " << turnaround_time[i] << " msec" << endl;
    }

    cout << "\nAVERAGE TURNAROUND TIME = " << avg_turnaround_time << " msec" << endl;

    cout << "\nWAITING TIME" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Waiting time of P" << i + 1 << " = " << waiting_time[i] << " msec" << endl;
    }

    cout << "\nAVERAGE WAITING TIME = " << avg_waiting_time << " msec" << endl;
}

int main() {
    int n;
    cout << "\nEnter the number of processes : ";
    cin >> n;

    int burst_time[10];
    int arrival_time[10];
    string p[10];

    for (int i = 0; i < n; i++) {
        p[i]=i+1;
        cout << "\nEnter the Burst time for Process P" << i+1 << " : ";
        cin >> burst_time[i];
        cout << "Enter the Arrival time Process P" << i+1 << " : ";
        cin >> arrival_time[i];
    }

    SJF_preemptive(n, burst_time, p, arrival_time);

    return 0;
}
