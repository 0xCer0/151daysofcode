// Given Preorder, Inorder and Postorder traversals of some tree of size N. The task is to check if they are all of the same tree or not.

// Example :

// Input:
// N = 5
// preorder[] = {1, 2, 4, 5, 3}
// inorder[] = {4, 2, 5, 1, 3}
// postorder[] = {4, 5, 2, 3, 1}
// Output: Yes
// Explanation: 
// All of the above three traversals 
// are of the same tree.
//            1
//          /   \
//         2     3
//       /   \
//      4     5


//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 
bool checktree(int preorder[], int inorder[], int postorder[], int len) ;


 // } Driver Code Ends



bool checktree(int preorder[], int inorder[], int postorder[], int len) 
{
    //Your code goes here
    
    if(len==0)
    {
        return true;
        
    }
    if(preorder[0]!=postorder[len-1])
    {
        return false;
        
    }
    if(len==1)
    {
        if(preorder[0] == inorder[0] && inorder[0] == postorder[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int rootIndex=-1;
    for(int i=0;i<len;i++)
    {
        if(inorder[i]==preorder[0])
        {
            
            rootIndex=i;
            
        }
    }
    if(rootIndex==-1)
    {
        return false;
    }
    else
    {
        bool flag1=checktree(preorder+1,inorder,postorder,rootIndex);
        bool flag2=checktree(preorder+1+rootIndex,inorder+rootIndex+1,postorder+rootIndex,len-rootIndex-1);
        if(flag1)
        {
            if(flag2)
            {
                return true;
            }
            
        }
        return false;
    }
    
   
}



// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];

		if(checktree(preorder, inorder, postorder, n) )
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 

  // } Driver Code Ends