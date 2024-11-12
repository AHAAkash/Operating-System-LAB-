#include<bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{

	unordered_set<int> s;
	unordered_map<int, int> indexes;

	int page_faults = 0;
	for (int i=0; i<n; i++)
	{
		// Check if the set can hold more pages
		if (s.size() < capacity)
		{
			// Insert it into set if not present
			// already which represents page fault
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);

				// increment page fault
				page_faults++;
			}

			// Store the recently used index of
			// each page
			indexes[pages[i]] = i;
		}

		// If the set is full then need to perform lru
		// i.e. remove the least recently used page
		// and insert the current page
		else
		{
			// Check if current page is not already
			// present in the set
			if (s.find(pages[i]) == s.end())
			{
				// Find the least recently used pages
				// that is present in the set
				int lru = INT_MAX, val;
				for (auto it=s.begin(); it!=s.end(); it++)
				{
					if (indexes[*it] < lru)
					{
						lru = indexes[*it];
						val = *it;
					}
				}

				// Remove the indexes page
				s.erase(val);

				// insert the current page
				s.insert(pages[i]);

				// Increment page faults
				page_faults++;
			}

			// Update the current page index
			indexes[pages[i]] = i;
		}
	}

	return page_faults;
}

// Driver code
int main()
{
	int pages[] = { 0, 6, 3, 0, 2, 6, 3,
				5, 2,4,1, 3, 0,6,1,4,2, 3, 5,7};
	int n = sizeof(pages)/sizeof(pages[0]);
	int capacity = 4;
	cout << pageFaults(pages, n, capacity);
	return 0;
}

