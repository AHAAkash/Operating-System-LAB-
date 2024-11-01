#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Implement FIRST COME FIRST SERVE Algorithm........"<<endl;
    /*Step-1: First we declare some different int type array to store Process,
    Arrival time, Burst Time, TurnAround Time, Waiting Time and Completion Time.
    In array declaration we set by default ZERO(0) for all array ..............
    */
    int n;
    cout<< "Enter Number of Processes:" ;
    cin>>n;
    int P[n]={0},AT[n]={0},BT[n]={0},TAT[n]={0},WT[n]={0},CT[n]={0};
    cout<< "Enter Process Sequence:";
    for(int i=0;i<n;i++){
        cin>>P[i];
    }
    cout<< "Enter Arrival Time:";
    for(int i=0;i<n;i++){
        cin>>AT[i];
    }
    cout<< "Enter Burst Time:";
    for(int i=0;i<n;i++){
        cin>>BT[i];
    }
        /*
           In this part, we are sorting the processes based on their Arrival Time.
           That is, the process with the lower Arrival Time will come first.
           Why this is important----->>>>
            If the processes are not sorted according to their Arrival Time,
            then the process that is supposed to execute first based on FCFS might get executed later.
            For example:
                       Process 1 Arrival Time: 2
                       Process 2 Arrival Time: 0
            If we don't sort them by Arrival Time, Process 1 might get executed before Process 2,
            which would violate the rules of the FCFS algorithm.
        */
        // Use Bubble Sorting ........... Concept---->>
    int i,j,temp=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           if(AT[i] > AT[j]){
              temp = AT[i];
              AT[i] = AT[j];
              AT[j] = temp;
              temp = BT[i];
              BT[i] = BT[j];
              BT[j] = temp;
              temp = P[i];
              P[i] = P[j];
              P[j] = temp;
           }
        }
    }
    //Calculate Completion Time
    int sum=0;
    for(i=0;i<n;i++){
        sum=sum + BT[i];
        CT[i]=CT[i] + sum;
    }
    //Calculate TurnAround Time & Waiting Time
    float  Total_TAT = 0;
    float  Total_WT = 0;
    for(i=0;i<n;i++){
        TAT[i] = CT[i] - AT[i];
        Total_TAT = Total_TAT + TAT[i];
        WT[i] = TAT[i] - BT[i];
        Total_WT = Total_WT + WT[i];
    }
    cout<< "Showing Result ------>" <<endl;
    cout<< "Process\t AT\t BT\t CT\t TAT\t WT\t " <<endl;
    for(i=0;i<n;i++){
        cout<<P[i]<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i] <<endl;
    }
    cout<< "Average TurnAround Time:" << (Total_TAT/n) <<endl;
    cout<< "Average Waiting Time:" << (Total_WT/n) <<endl;
    return 0;
}
