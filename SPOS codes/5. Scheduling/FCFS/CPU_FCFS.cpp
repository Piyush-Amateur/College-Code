#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

int main()
{
    int np,bt[10],wt[10],tt[10],ft[10],i,j;
    cout<<"Enter the number of process : ";
    cin>>np;
    for(i=0;i<np;i++)
    {
        cout<<"\nEnter the Burst time for Process "<<i+1<<" : ";
        cin>>bt[i];
    }
    //calculating finish time 
    ft[0]=bt[0];
    for(i=1;i<np;i++)
    {
        ft[i]=bt[i]+ft[i-1];
    }
    /*
    for(i=0;i<np;i++)
    {
        cout<<ft[i]<<" ";
    
    }
    */

    //calculating turn around time 
    for(j=0;j<np;j++)
    {
        tt[j]=ft[j]-0;
        //if specific arrival time is given take that arrival time instead of zero
    }

    //calculating waiting time
    wt[0]=0;
    for(i=1;i<np;i++)
    {
        wt[i] = tt[i] - bt[i];
    }
    //calculating average turn around time and waiting time 
    int avgtt,avgwt,sumtt=0,sumwt=0;
    for(i=0 ; i<np;i++)
    {
        sumtt +=tt[i];
        sumwt +=wt[i];
    }


    //output code
    cout<<"\n\tProcess\t\tBurst time\t\tTurn around time\t\tWaiting time"<<endl<<endl;
    for(int k=0 ; k<np ; k++)
    {
        cout<<"\tProcess "<<k+1<<"\t\t"<<bt[k]<<"\t\t\t"<<tt[k]<<"\t\t\t"<<wt[k]<<endl;
    }

    //Gantt chart
    cout<<endl<<"\nGantt Chart:"<<endl<<endl;
    for(j=0;j<np;j++)
    {
        cout<<" | "<<"P"<<j+1;
    }
    cout<<" |";
    cout<<"\n0";
    for(j=0;j<np;j++)
    {
        cout<<setw(6)<<ft[j];
    }

    cout<<"\n\n\nThe average Turn Around Time is : "<<sumtt/np;
    cout<<"\nThe average Waiting Time is : "<<sumwt/np;

    return 0;
}