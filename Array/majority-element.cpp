#include <bits/stdc++.h>
using namespace std;
int findCandidate(int *a, int n)
{
	int maj = 0, count = 1;
	for(int i=1; i<n; i++)
	{
		if(a[maj] == a[i])
			count++;
		else
			count--;
		if(count == 0)
		{
			maj = i;
			count = 1;
		}
	}
	return maj;
}

bool checkMajority(int *a, int n, int c)
{
	int count = 0;
	for(int i = 0; i<n ; i++)
	{
		if(a[c] == a[i])
			count++;
	}
	if(count > n/2)
		return true;
	else 
		return false;
}

int main()
{
	int a[10] = {1,1,1,2,3,4,1,1,3,1};
	int size = sizeof(a)/sizeof(a[0]);
	int c = findCandidate(a, size);
	if(checkMajority(a, size, c))
		cout<<a[c];
	else
		cout<<"No Majority Element";
	return 0;
}