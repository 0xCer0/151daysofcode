//Spiderman is stuck in a difficult situation. His arch-enemy the Green Goblin has planted several of his infamous Pumpkin Bombs in various locations in a building. Help Spiderman activate his Spidey Sense and identify the impact zones. 
//He has a blueprint of the building which is a M x N matrix that is filled with the characters ‘O’, ‘B’, and ‘W’ where: 
//‘O’ represents an open space.
//‘B’ represents a bomb.
//‘W’ represents a wall.
//You have to replace all of the O’s (open spaces) in the matrix with their shortest distance from a bomb without being able to go through any walls. Also, replace the bombs with 0 and walls with -1 in the resultant matrix. If no path exists between a bomb and an open space replace the corresponding 'O' with -1.

//Example :

//Input: N = 3, M = 3
//A[] = {{O, O, O}, 
//       {W, B, B}, 
//       {W, O, O}}
//Output: {{2, 1, 1}, 
//         {-1, 0, 0},  
//         {-1, 1, 1}}
//Explanation: The walls at (1,0) and (2,0) 
//are replaced by -1. The bombs at (1,1) and 
//(1,2) are replaced by 0. The impact zone 
//for the bomb at (1,1) includes open spaces at index (0,0), (0,1) and (2,1) with distance 
//from bomb calculated as 2,1,1 respectively. The impact zone for the bomb at (1,2) includes open spaces at index (0,3) and (2,2) with distance from bomb calculated as 1,1 respectively.



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{

    public:
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        queue<vector<int>> q;
        vector<vector<int>> k(M,vector<int> (N,-1));
        vector<vector<int>> vis(M,vector<int>(N,0));
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[i][j]=='B')
                {
                    vis[i][j]=1;
                    k[i][j]=0;
                    q.push({i,j,0});
                }
                
                
            }
        }int u,v,w;
        
        int r,c;
        while(!q.empty())
        {
            u=q.front()[0];
            v=q.front()[1];
            w=q.front()[2];
            k[u][v]=w;
            q.pop();
                for(int j=0;j<4;j++)
                {
                    r=row[j]+u;
                    c=col[j]+v;
                    if(r>=0 && c>=0 && r<M && c<N && vis[r][c]==0 && matrix[r][c]=='O')
                    {
                        matrix[r][c]='W';
                        vis[r][c]=1;
                        q.push({r,c,w+1});
                    }
                }
            
        }
        return k;
        // Your code goes here
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends