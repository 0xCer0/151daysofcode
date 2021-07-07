// In the game of Restricted Pacman, an infinite linear path is given. Pacman has to start at position 0 and eat as many candies as possible. In one move he can only jump a distance of either M or N.  If M and N are coprime numbers, find how many candies will be left on the board after the game is over.
// Note: The result is always finite as after a point X every index in the infinite path can be visited. 

// Example :

// Input: M = 2, N = 5
// Output: 2
// Explanation: From index 0, the indices that 
// can be visited are
// 0 + 2 = 2
// 0 + 2 + 2 = 4
// 0 + 5 = 5
// 0 + 2 + 2 + 2 = 6
// 0 + 2 + 5 = 7
// 0 + 2 + 2 + 2 + 2 = 8
// 0 + 2 + 2 + 5 = 9
// 0 + 5 + 5 = 10
// and so on.
// 1 and 3 are the only indices that cannot be 
// visited. Therefore the candies at these two 
// positions will be left on the board. 

//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std; 

class Solution{
    public:
    int candies(int m, int n) 
    { 
  
    	vector<long> eaten;
      int smallest, largest;
    	if (m < n){
        smallest = m;
        largest = n;
      } else {
        smallest = n;
        largest = m;
      }
    	int k = 1;
    	while(k * smallest < largest){
    	    eaten.push_back(smallest * k);
          k++;
    	}
      eaten.push_back(largest);
      long i = k-2, j = k-1;
      bool cont = true;
      while(cont){
        if (eaten[i] + smallest <= eaten[j] + largest){
          eaten.push_back(eaten[i] + smallest);
          i += 1;
        } else if (eaten.back() != eaten[j] + largest){
          eaten.push_back(eaten[j] + largest);
          j += 1;
        } else if (eaten.back() == eaten[j] + largest){
          j += 1;
        }
        if (i > (largest * largest)){
          cont = false;
        }

    }
};

