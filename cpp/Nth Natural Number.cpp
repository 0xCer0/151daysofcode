// Given a positive integer N. You have to find Nth natural number after removing all the numbers containing digit 9.

// Example :
// Input:
// N = 8
// Output:
// 8
// Explanation:
// After removing natural numbers which contains
// digit 9, first 8 numbers are 1,2,3,4,5,6,7,8
// and 8th number is 8.

class Solution{
public:
long long findNth(long long N)
{
long ans=0;
long m=1;
while(N!=0)
{
long dig=N%9;
N=N/9;
ans+=(m*dig);
m=m*10;
}
return ans;
}
};