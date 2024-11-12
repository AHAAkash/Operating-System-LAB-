/// FIRST FIT Allocation

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nb; ///number of blocks or How many blocks 5
    cin>>nb;
    int blksiz[nb]; // block sizes
    for(int i=0; i<nb; i++)
    {
        cin>>blksiz[i]; // 100, 500, 200, 300, 600
    }

    int np; //number of processes 4
    cin>>np;
    int prsiz[np]; //processes sizes

    for(int i=0; i<np; i++)
    {
        cin>>prsiz[i]; // 212 ,417, 112, 426
    }

    int allocate[nb];
    memset(allocate, -1, sizeof(allocate)); // allocate[0]=-1, allocate[1]=-1,......allocate[4]=-1, no process assigned.
    /// allocate the processes
    sort(blksiz, blksiz+nb); /// 100,200,300, 500, 600
    for(int i=0; i<np; i++)
    {
        for(int j=0; j<nb; j++)
        {
            if (blksiz[j]>=prsiz[i])
            {
                allocate[i] = j;

                blksiz[j] = blksiz[j] - prsiz[i];
                break;
            }

        }
    }
    cout<<"\n Process No. \tProcess size\tBlock no.\n";
    for(int i=0; i<np; i++)
    {
        cout<<" "<<i+1<<"\t\t"<<prsiz[i]<<"\t\t";
        if(allocate[i] != -1)
            cout<<allocate[i]+1;
        else
            cout<<"Not allocated\n";
        cout<<endl;
    }

}
