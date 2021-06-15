// In Geekland there is a grid of coins of size N x N. You have to find the maximum sum of coins in any sub-grid of size K x K.
// Note: Coins of the negative denomination are also possible at Geekland.

// Example:

// Input: N = 5, K = 3 
// mat[[]] = {1, 1, 1, 1, 1} 
//           {2, 2, 2, 2, 2} 
//           {3, 8, 6, 7, 3} 
//           {4, 4, 4, 4, 4} 
//           {5, 5, 5, 5, 5}
// Output: 48
// Explanation: {8, 6, 7}
//              {4, 4, 4}
//              {5, 5, 5}
// has the maximum sum



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        int r1=0,r2=K,c1=0,c2=K;
        int res=INT_MIN,sum=0;
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<K;j++)
            {
                sum+=mat[i][j];
            }
        }
        res=max(res,sum);
        int temp=sum;
        while(r2<=N){
            while(c2<N)
            {
                for(int i=r1;i<r2;i++)
                {
                    sum=sum-mat[i][c1];
                    sum=sum+mat[i][c2];
                }
                c1++;c2++;
                res=max(res,sum);
            }
            c1=0; c2=K;
            if(r2==N)
            break;
            for(int i=c1;i<c2;i++)
            {
                temp=temp+mat[r2][i];
                temp=temp-mat[r1][i];
            }
            sum=temp;
            r1++;r2++;
            res=max(res,sum);
        }
        return res;
    }
           
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends
