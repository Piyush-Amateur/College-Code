#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

void sjf(string pr[], int bt[], int at[], int n)
{
    int ft[20],tbt[20],ta[20],wt[20],count=0,count1=0;
    ft[0]=at[0];
    
    // Sort the processes based on their burst time and arrival time
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(bt[i],bt[j]);
                swap(pr[i],pr[j]);
                swap(at[i],at[j]);
            }
            else if(bt[i]==bt[j])
            {
                if(at[i]>at[j])
                {
                    swap(bt[i],bt[j]);
                    swap(pr[i],pr[j]);
                    swap(at[i],at[j]);
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        ft[i] = ft[i - 1] + bt[i - 1];
    }
    
    cout<<"\nGantt chart\n"<<endl;
    cout<<" | ";
    for(int j=0;j<n;j++)
    {
        cout<<pr[j]<<"  |  ";
    }
    cout<<endl;
    for(int j=0;j<=n;j++)
    {
        cout<<ft[j]<<setw(7);
    }
    
    cout<<"\n\n Turn Around Time"<<endl;
    for(int i=0;i<n;i++)
    {
        ta[i]=ft[i+1]-at[i];
        cout<<"\n Turn Around time of "<<pr[i]<<" is:"<<ta[i];
        count=count+ta[i];
    }
    cout << "\nAverage Turn Around time = " << static_cast<double>(count) / n << " msec" << endl;

    cout<<"\n Waiting Time"<<endl;
    for(int i=0;i<n;i++)
    {
        wt[i]=ta[i+1]-bt[i];
        cout<<"\n Waiting time of "<<pr[i]<<" is:"<<wt[i];
        count1=count1+wt[i];
    }
    cout << "\nAverage Waiting time = " << static_cast<double>(count1) / n << " msec" << endl;
}

int main()
{
    string pr[20];
    int n,at[20],bt[20];
    cout<<"SJF"<<endl;
    for(int i=0;i<20;i++)
    {
        bt[i]=0;
    }
    cout<<"Enter total number of Process: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter processes["<<i+1<<"] : ";
        cin>>pr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Burst Time of "<<pr[i]<<" : ";
        cin>>bt[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Arrival Time of "<<pr[i]<<" : ";
        cin>>at[i];
    }
    cout<<"\nProceses"<<"\tBurst Time"<<"\tArrival Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<pr[i]<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<endl;
    }
    sjf(pr,bt,at,n);
    return 0;
}