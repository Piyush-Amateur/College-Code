#include<iostream>
#define max 20
using namespace std;

int main()
{
    struct process
    {
        string p;
        int id,BT,WT,TT,AT,FT=0;
    }pro[20];
    int n,quantum,completed=0,exe_ind=0,cur_time=0,exe_ord[max],remain[max],current_time[max];
    float avgtt=0,avgwt=0;
    cout<<"Enter the number of process: ";
    cin>>n;
    cout<<"Enter the time quantum: ";
    cin>>quantum;
    for (int i = 0; i<n; i++)
    {
        pro[i].id=i;
        cout<<"Enter the Burst time for process "<<i+1<<" :";
        cin>>pro[i].BT;
        remain[i]=pro[i].BT;
        cout<<"Enter the Arrival time for process "<<i+1<<" :";
        cin>>pro[i].AT;
    }
    while(completed<n)
    {
        current_time[0]=0;
        for(int i=0;i<n;i++)
        {
            if (remain[i]>0 && pro[i].AT<=cur_time)
            {
                int time=min(quantum,remain[i]);
                remain[i]-=time;
                cur_time+=time;
                exe_ord[exe_ind]=i;
                current_time[exe_ind+1]=cur_time;
                exe_ind++;

                if (remain[i]==0)
                {
                    completed++;
                    pro[i].FT=cur_time;
                    pro[i].TT=pro[i].FT-pro[i].AT;
                    pro[i].WT=pro[i].TT-pro[i].BT;
                    avgtt+=pro[i].TT;
                    avgwt+=pro[i].WT;
                }
            }  
        }
    }
    cout<<"GANTT-CHART"<<endl;
    for (int i = 0; i <exe_ind; i++)
    {
        cout<<" | P"<<pro[exe_ord[i]].id+1<<"\t";
    }
    cout<<"|"<<endl;
    for (int i = 0; i <= exe_ind; i++)
    {
        cout<<current_time[i]<<"\t";
    }
    cout<<endl;
    cout<<endl<<"\nTURN-AROUND TIME "<<endl;
    for (int i = 0; i<n; i++)
    {
        cout<<"Turn-around time of process "<<i+1<<"= "<<pro[i].TT<<" msec"<<endl;
    }
    avgtt=avgtt/n;
    cout<<"Average Turn-around time = "<<avgtt<<" msec"<<endl;
    cout<<endl;
    cout<<endl<<"WAITING TIME "<<endl;
    for (int i = 0; i<n; i++)
    {
        cout<<"Waiting time of "<<i+1<<"= "<<pro[i].WT<<" msec"<<endl;
    }
    avgwt=avgwt/n;
    cout<<"Average Waiting time = "<<avgwt<<" msec"<<endl;
    return 0;
}
