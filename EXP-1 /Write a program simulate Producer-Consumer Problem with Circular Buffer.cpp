#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int i,in,out,n=10,a[10],c=0;
int produce_item(int n)
{
	return 2*n+1;
}
int consume_item(int n)
{
	return n+1;
}
void producer()
{
	int itemp;
	in=0;
	while(true)
	{
		itemp=produce_item(in);
		c++;
		a[in]=itemp;
		in=(in+1)%n;
		if(c==n)
		break;
	}
	for(i=0;i<n;i++)
	cout<<a[i]<<endl;
}
void consumer()
{
	int itemc;
	out=0;
	while(true)
	{
		itemc=consume_item(a[out]);
		a[out]=itemc;
		out++;
		c--;
		if(c==0)
		break;
	}
	for(i=0;i<n;i++)
	cout<<a[i]<<endl;
}
int main()
{
	producer();
	consumer();
	return 0;
}
