#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Implement SHORTEST JOB FIRST Scheduling Algorithm........"<<endl;
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
    /* Sorting execution part-->
      According BURST Time we sort the array because small value
      comes first .
      Key Point ---> In SJF , Main criteria is Burst time so we use that to sorting
    */
    int i,j,temp = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           if(BT[i] > BT[j]){
              temp = P[i];
              P[i] = P[j];
              P[j] = temp;
              temp = AT[i];
              AT[i] = AT[j];
              AT[j] = temp;
              temp = BT[i];
              BT[i] = BT[j];
              BT[j] = temp;
           }
        }
    }
    int min=AT[0] , d;  // We don't know the minimum value though we sorted the array, So first index defined as min value
    //now we find minimum value using for loop
    for(i=0;i<n;i++){
        if(min > AT[i]){
            min = AT[i];   //Get small ARRIVAL time and
            d = i;         //In which index we find that store in d
        }
    }
    // Here we find COMPLETION time of small value ,In other word , we say that we find first CT value
    int tt=min;
    CT[d] = tt + BT[d];
    tt = CT[d];
    // Now calculate the others COMPLETION Time
    for(i=0;i<n;i++){
        if(AT[i] != min){  // this condition for ,Discard first value that calculate recentaly
            CT[i] = tt + BT[i];
            tt = CT[i];
        }
    }
    // Calculate TURNAROUND TIME & WAITING TIME
    float  Total_TAT = 0 , Total_WT = 0;
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
}
