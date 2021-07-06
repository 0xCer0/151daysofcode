// There are N buildings in Linear Land. They appear in a linear line one after the other and their heights are given in the array arr[]. Geek wants to select three buildings in Linear Land and remodel them as recreational spots. The third of the selected building must be taller than the first and shorter than the second.
// Can geek build the three-building recreational zone? 


// Example :

// Input:
// N = 6
// arr[] = {4, 7, 11, 5, 13, 2}
// Output:
// True
// Explanation:
// [4, 7, 5] fits the condition

#include <bits/stdc++.h>
using namespace std;



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