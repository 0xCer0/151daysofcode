// Geek wants to make a special space for candies on his bookshelf. Currently, it has N books of different heights and unit width. Help him select 2 books such that he can store maximum candies between them by removing all the other books from between the selected books. The task is to find out the area between 2 books that can hold the maximum candies without changing the original position of selected books. 

// Example :

// Input: N = 3, height[] = {1, 3, 4}
// Output: 1
// Explanation:
// 1. Area between book of height 1 and book of 
// height 3 is 0 as there is no space between 
// them.
// 2. Area between book of height 1 and book of 
// height 4 is 1 by removing book of height 3.
// 3. Area between book of height 3 and book of 
// height 4 is 0 as there is no space between the



class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // Your code goes here
    }   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
