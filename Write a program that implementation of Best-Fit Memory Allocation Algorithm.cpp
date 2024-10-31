#include <bits/stdc++.h>
using namespace std;

int main() {
    int process_size[10], block_size[10], P_no, B_no, allog[10], i, j;

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
        allog[i] = -1;  // Initialize allocation to -1 (not allocated)
    }

    // Best-Fit Allocation
    for (i = 0; i < P_no; i++) {
        int best_idx = -1;  // Track the index of the best block
        for (j = 0; j < B_no; j++) {
            if (block_size[j] >= process_size[i]) {
                if (best_idx == -1 || block_size[j] < block_size[best_idx]) {
                    best_idx = j;  // Find the smallest block that fits
                }
            }
        }
        if (best_idx != -1) {
            allog[i] = best_idx;
            block_size[best_idx] -= process_size[i];  // Reduce block size
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
