#include <bits/stdc++.h>
using namespace std;
int main() {
    int process_size[10], block_size[10], P_no, B_no, allog[10], i, j;
    for (i = 0; i < 10; i++) {
        allog[i] = -1;
    }
    cout << "Enter no of blocks: ";   cin >> B_no;
    cout << "Enter size of each block:\n";
    for (i = 0; i < B_no; i++) {
        cin >> block_size[i];
    }
    cout << "Enter no of processes: ";    cin >> P_no;
    cout << "Enter size of each process:\n";
    for (i = 0; i < P_no; i++) {
        cin >> process_size[i];
    }    // First-Fit Allocation
    for (i = 0; i < P_no; i++) {
        for (j = 0; j < B_no; j++) {
            if (block_size[j] >= process_size[i]) {
                allog[i] = j;  // Allocate block j to process i
                block_size[j] -= process_size[i];  // Reduce available memory
                break;  // Move to the next process
            }        }    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < P_no; i++)
    {
        cout << " " << i+1 << "\t\t"<< process_size[i] << "\t\t";
        if (allog[i] != -1)            cout << allog[i] + 1;
        else                cout << "Not Allocated";
        cout << endl;
    }
    return 0;
}
