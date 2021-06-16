// Given an array of size N, find the number of distinct pairs {a[i], a[j]} (i != j) in the array with their sum greater than 0.

// Example :

// Input: N = 3, a[] = {3, -2, 1}
// Output: 2
// Explanation: {3, -2}, {3, 1} are two 
// possible pairs.


#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


//User function Template for C++

int search(int a[], int lo, int hi, int k){
        if(hi < lo)
            return -1; 
        
        
        int mid = (lo+hi)/2;
        /*cout<<"mid "<<mid<<endl;
        cout<<"a[mid]"<<a[mid]<<endl;
        cout<<"hi "<<hi;
        cout<<"lo "<<lo;*/
        if(mid < hi && a[mid] + k <= 0 && a[mid+1]+k > 0 ){
            //cout<<"inside mid<hi, hi "<<hi<<"a[mid]"<<a[mid]<<"a[mid+1]"<<a[mid+1]<<endl;
            return mid;
        }
        if(mid > lo && a[mid]+k > 0 && a[mid-1]+k <=0){
            //cout<<"inside mid>lo, lo "<<lo<<"a[mid]"<<a[mid]<<"a[mid-1]"<<a[mid-1]<<endl;
            //cout<<"lo "<<lo<<endl;
            return mid-1;
        }
        if(lo == hi)
        {
            if(a[mid]+k <= 0){
                //cout<<"inside lo==hi ,lo "<<lo<<"a[mid]"<<a[mid]<<endl;
                return lo;
            }
            else
            {
                //cout<<"inside -1 lo "<<lo<<"a[mid]"<<a[mid]<<endl;
                return -1;
            }
        }
        
        if(a[mid]+k < 0){
           search(a, mid+1, hi, k);
        }else{
             search(a, lo, mid, k);
        }
    
   
}
class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	// Your code goes here 
    	sort(a, a+n);
    /*	long long count = 0;
    	int i = 0;
    	int j = n-1;
    for(int i = n-1; i > 0; i--){
        if(a[i] + a[0]  > 0){
            count += i;
        }else if(a[i] < 0){
            continue;
        }else{
            int p = search(a, 0, i-1, a[i]);
           // cout<<"p "<<p<<endl;
            if( p != -1){
                count += i-p-1;
            }
        }
    }*/
    // Variable to store the count of pairs
    long long ans = 0;

    // Loop to iterate through the array
    for (int i = 0; i < n; ++i) {

        // Ignore if the value is negative
        if (a[i] <= 0)
            continue;

        // Finding the index using lower_bound
        int j = lower_bound(a, a + n, -a[i] + 1) - a;

        // Finding the number of pairs between
        // two indices i and j
        ans += i - j;
    }
    return ans;
    	//return count;
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
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends