#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int at[n], bt[n], rt[n];
    int completionTime, time = 0, remain = 0;
    int sum_wait = 0, sum_turnAround = 0;
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for process p" << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter burst time for process p" << i + 1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i];
    }
    cout << "\nProcess\tTurnaround Time\tWaiting Time\n";
    while (remain != n) {
        int smallestTime = -1;
        int minTime = INT_MAX;
        // Find the process with the smallest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < minTime) {
                minTime = rt[i];
                smallestTime = i;
            }
        }
        // If no valid process found, increment time and continue
        if (smallestTime == -1) {
            time++;
            continue;
        }
        rt[smallestTime]--;  // Reduce the remaining time of the selected process
        if (rt[smallestTime] == 0) {     // If the process completes
            remain++;
            completionTime = time + 1;
            int turnaroundTime = completionTime - at[smallestTime];
            int waitingTime = turnaroundTime - bt[smallestTime];
            cout << "p" << smallestTime + 1 << "\t" << turnaroundTime << "\t\t" << waitingTime << "\n";
            sum_wait += waitingTime;
            sum_turnAround += turnaroundTime;
        }
        time++;
    }
    cout << "\nAverage Waiting Time: " << (sum_wait * 1.0) / n << endl;
    cout << "Average Turnaround Time: " << (sum_turnAround * 1.0) / n << endl;
    return 0;
}
