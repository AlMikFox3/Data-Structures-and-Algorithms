#include <bits/stdc++.h>
using namespace std;
long long firstkdigits(int n,int k)
{
   long double product = n * log10(n);
 
   long double decimal_part = product - floor(product);
   decimal_part = pow(10, decimal_part);
   long long digits = pow(10, k - 1), i = 0;
 
   return decimal_part * digits;
}
int main()
{
   int n = 1450;
   int k = 6;
   cout << firstkdigits(n, k);
   return 0;
}