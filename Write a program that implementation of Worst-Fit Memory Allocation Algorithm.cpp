#include <bits/stdc++.h>
using namespace std;

int main() {
    int process_size[10], block_size[10], P_no, B_no, allog[10], i, j;
    for (i = 0; i < 10; i++) {
        allog[i] = -1;
    }

    cout << "Enter no of blocks: ";
    cin >> B_no;
    cout << "Enter size of each block:\n";
    for (i = 0; i < B_no; i++) {
        cin >> block_size[i];
    }

    cout << "Enter no of processes: ";
    cin >> P_no;
    cout << "Enter size of each process:\n";
    for (i = 0; i < P_no; i++) {
        cin >> process_size[i];
    }
    // Worst-Fit Allocation
    for (i = 0; i < P_no; i++) {
        int worst_idx = -1;
            if (block_size[j] >= process_size[i]) {
                if (worst_idx == -1 || block_size[j] > block_size[worst_idx]) {
                    worst_idx = j;
                }
            }
        }
        if (worst_idx != -1) {
            allog[i] = worst_idx;
            block_size[worst_idx] -= process_size[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < P_no; i++) {
        cout << " " << i + 1 << "\t\t" << process_size[i] << "\t\t";
        if (allog[i] != -1)
            cout << allog[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }

    return 0;
}
