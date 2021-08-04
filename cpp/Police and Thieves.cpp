// Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
// Keep in mind the following conditions :

// Each policeman can catch only one thief.
// A policeman cannot catch a thief who is more than K units away from him.
// Example :

// Input:
// N = 5, K = 1
// arr[] = {P, T, T, P, T}
// Output: 2
// Explanation: Maximum 2 thieves can be 
// caught. First policeman catches first thief 
// and second police man can catch either second 
// or third thief.

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
      
    }
};


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 
