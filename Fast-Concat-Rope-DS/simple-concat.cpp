#include <iostream>
using namespace std;
void concat(char*a, char*b, char*c, int n1, int n2, int n3){
	for(int i = 0;i<n1;i++)
	{
		c[i] = a[i];
	}
	for(int i=0;i<n2;i++)
	{
		c[n1+i] = b[i];
	}
	c[n3] = '\0';
}

int main()
{
	char a[] = "Hey Man. ";
	int n1 = sizeof(a)/sizeof(a[0]);
	char b[] = "How you holdin up?";
	int n2 = sizeof(b)/sizeof(b[0]);
	char c[n1+n2-1];
	concat(a,b,c,n1,n2,n1+n2-1);
	for(int i=0;i<n1+n2-1;i++)
		cout<<c[i];
	return 0;
}