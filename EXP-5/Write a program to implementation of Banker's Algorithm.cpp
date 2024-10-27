#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, i, j, k, y, ind = 0;
    cout << "Enter the number of Processes: ";
    cin >> n;
    cout << "Enter the number of Resources: ";
    cin >> m;

    int alloc[20][20], max[20][20], avail[50];
    int finish[20] = {0}, safesequence[20], work[50], need[20][20];

    cout << "Enter the Allocation Matrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }
    cout << "Enter the Max Matrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }
    cout << "Enter the Available Matrix:\n";
    for (i = 0; i < m; i++) {
        cin >> avail[i];
    }
    // Calculating the NEED matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    cout << "NEED Matrix is:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }
    // Initializing the work array with available resources
    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }
    // Main loop to find the safe sequence
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    safesequence[ind++] = i;
                    for (y = 0; y < m; y++) {
                        work[y] += alloc[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    cout << "Following is the SAFE Sequence:\n";
    for (i = 0; i < n; i++) {
        cout << " P" << safesequence[i];
        if (i < n - 1) cout << " ->";
    }
    cout << endl;

    return 0;
}
