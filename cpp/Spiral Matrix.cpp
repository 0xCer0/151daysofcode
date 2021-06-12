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


class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int r=0,c=0,i=0;
        while(k>=1){
            for(i=r;i<=m-1;++i,--k)
                if(k==1)
                return a[r][i];
                ++r;
                for(i=r;i<=n-1 && k>=1;++i,--k)
                    if(k ==1)
                    return a[i][m-1];
                    --m;
                    for(i=m-1;1>=c && k>=1;--i,--k)
                    if (k==1)
                    return a[n-1][i];
                    --n;
                    for(i=n-1;i>=r && k>=1;--i,--k)
                    if (k==1)
                    return a[i][c];
                    ++c;
        }
    }

};