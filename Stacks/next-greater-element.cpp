#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[10] = {1,2,2,2,4,8,1,19,22,21};
	int n = sizeof(a)/sizeof(a[0]);
	stack<int> stk;

	int element, next;
	stk.push(a[0]);

	for(int i=1; i<n; i++)
	{
		next = a[i];
		if(!stk.empty())
		{
			element = stk.top();
			stk.pop();
			while(element < next)
			{
				cout<<element<<"--"<<next<<endl;
				if(stk.empty())
					break;
				element = stk.top();
				stk.pop();
			}
			if(element > next)
				stk.push(element);
		}
		stk.push(next);
	}
	while(!stk.empty())
	{
		int t = stk.top();
		stk.pop();
		cout<<t<<"--"<<"-1"<<endl;
	}

	return 0;

}