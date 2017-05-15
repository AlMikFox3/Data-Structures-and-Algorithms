#include<bits/stdc++.h>
using namespace std;
int maxLen(string str)
{
	int n = str.length();
	int result = 0;
	stack<int> stk;
    stk.push(-1);
	for(int i=0;i<n;i++)
	{
		if(str[i] == '(')
		{
			stk.push(i);
		}
		else
		{
			stk.pop();
			if(!stk.empty())
				result = max(result, i-stk.top());
			else
				stk.push(i);
		}
	}
	return result;
}

int main()
{
	string str = "((()()";
    cout << maxLen(str) << endl;
 
    str = "()(()))))";
    cout << maxLen(str) << endl ;
 
    return 0;
}