//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		int currmax1 = arr[0],first = 100;
        for(int i =1;i <n;i++)
        { 
            if(arr[i]>currmax1)
            {
                currmax1 = arr[i-1];
                first = min(first ,arr[i-1]);
             }
        if (currmax1 != 0 && arr[i] > first && currmax1> first && currmax1>arr[i])
        return true;
        }
        return false;
        } 
        	
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends
