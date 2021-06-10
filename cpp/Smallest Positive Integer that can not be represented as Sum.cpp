// Given an array of size N, find the smallest positive integer value that cannot be represented as sum of some elements from the array.

// Example:
// Input: 
// N = 6
// array[] = {1, 10, 3, 11, 6, 15}
// Output: 
// 2
// Explanation:
// 2 is the smallest integer value that cannot 
// be represented as sum of elements from the array.


class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        long long target=1,res=0;
        sort(array.begin(),array.end());
        for(int i=0; i<n;++i)
        {
            if(array[i]<=target)
            {
                res+=array[i];
                target=res+1;
            }
            else 
            {
            return target;
            }
        }
        return target;
    } 
};
