// Given a matrix of size N x M. You have to find the Kth element which will obtain while traversing the matrix spirally starting from the top-left corner of the matrix.

// Example :

// Input: 
// N = 3, M = 3, K = 4
// A[] = {{1, 2, 3}, 
//        {4, 5, 6}, 
//        {7, 8, 9}}
// Output: 
// 6
// Explanation: Spiral traversal of matrix: 
// {1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
// is 6.


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
vector<int>v;
int top = 0;
int bottom = n - 1;
int right = m - 1;
int left = 0;
int side = 0;
int constexpr total_sides = 4;
while(top <= bottom && left <= right){
if(side == 0){
for(int i = left;i<=right;++i){
v.push_back(a[top][i]);
}
top++;
}
if(side == 1){
for(int i = top;i<=bottom;++i){
v.push_back(a[i][right]);
}
right--;
}
if(side == 2){
for(int i = right;i>=left;--i){
v.push_back(a[bottom][i]);
}
bottom--;
}
if(side == 3){
for(int i = bottom;i>=top;--i){
v.push_back(a[i][left]);
}
left++;
}
side = (side + 1) % total_sides;
}
return v[k-1];
    }

};

