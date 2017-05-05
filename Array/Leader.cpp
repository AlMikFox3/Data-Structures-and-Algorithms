#include <iostream>
using namespace std;
void leader(int* a, int n)
{
	int m = a[n-1];
	cout<<m<<" ";
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]>m)
		{
			m = a[i];
			cout<<m<<" ";
		}
	}
}
int main()
{
	int arr[5] = {21,2,14,1,15};
	int n = sizeof(arr)/sizeof(int);
	leader(arr,n);
	return 0;
}