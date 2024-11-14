#include<bits/stdc++.h>
using namespace std;
vector<int>res;
int need[100][100],alloc[100][100],Max[100][100];
int n,m,resource[100],avail[100],work[100],request[100];
bool vis[100];
int find_safe()
{
    int f=1;
    memset(vis,0,sizeof vis);
    while(f){
        f=0;
        for(int i=0;i<n;i++){
            if(vis[i]==1)continue;
            for(int j=0;j<m;j++){
                if(need[i][j]>avail[j]){
                    f=0;
                    break;
                }
                f=1;
            }
            if(f==0)continue;
            vis[i]=1;
            res.push_back(i);
            for(int k=0;k<m;k++) avail[k]+=alloc[i][k];
        }
    }

    if(res.size()!=n){
        cout<<"Process is not safe"<<endl;
        for(int i=0;i<m;i++)
            avail[i]=work[i];
        res.clear();
        return 0;
    }
    else{
        cout<<"Process sequence"<<endl;
        for(int i=0;i<res.size();i++)
            cout<<"p["<<res[i]<<"] ";
        cout<<endl;
        for(int i=0;i<m;i++){
            work[i]-=request[i];
            avail[i]=work[i];
        }
        res.clear();
        return 1;
    }
}
int find_res(int z)
{
    int f=1;
    for(int j=0;j<m;j++){
        cout<<j<<' '<<request[j]<<' '<<avail[j]<<endl;
        if(request[j]<=need[z][j] and request[j]<=avail[j])
            f=1;
        else {
            f=0;
            break;
        }
    }
    if(f==0){
        cout<<"Request can not be allocated"<<endl;
        return 0;
    }

    for(int i=0;i<m;i++) avail[i]=work[i];
    for(int k=0;k<m;k++){
        avail[k]-=request[k];
        alloc[z][k]+=request[k];
        need[z][k]-=request[k];
    }
    int c=find_safe();
    if(c==0){
        cout<<"This request can not be processed"<<endl;
        for(int k=0;k<m;k++){
            avail[k]=work[k];
            alloc[z][k]-=request[k];
            need[z][k]+=request[k];
        }
    }
    else{
       cout<<"Request is processed successfully"<<endl;
    }
}
int find_need()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=Max[i][j]-alloc[i][j];
            cout<<need[i][j]<<' ';
        }
        cout<<endl;
    }
}
int find_avail()
{
    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=alloc[i][j];
        }
        avail[j]=resource[j]-sum;
        work[j]=avail[j];
        cout<<avail[j]<<' ';
    }
    cout<<endl;
}
int make_request()
{
    cout<<"Enter process no: ";
    int z;
    cin>>z;
    cout<<"Enter request: ";
    for(int i=0;i<m;i++)
        cin>>request[i];
    find_res(z);
}
int main()
{
    cout<<"Enter number of process: ";
    cin>>n;
    cout<<"Enter number of resource: ";
    cin>>m;
    cout<<"Enter available resource instances: ";
    for(int i=0;i<m;i++)cin>>resource[i];

    cout<<"Enter allocation of resources per process"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>alloc[i][j];
    }

    cout<<"Enter maximum allocation of resources per process"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>Max[i][j];
    }
    find_avail();
    cout<<"Finding need of resources per process"<<endl;
    find_need();
    find_safe();
    for(int i=0;i<10;i++){
        make_request();
    }
}
