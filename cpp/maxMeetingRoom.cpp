// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?
// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Example 1:
// Input:
// N = 6
// start[] = {1,3,0,5,8,5}
// end[] =  {2,4,6,7,9,9}
// Output: 
// 4

#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &arr){
    int m;

    sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });
    cout << arr[0][2] << " ";
    m = arr[0][1];
    for(int i = 1; i < arr.size(); i++){
        if(m <= arr[i][0]){
            cout << arr[i][2] << " ";
            m = arr[i][1];
        }
    }
}

int main(){
	int t, n;

	cin >> t;
	while(t--){
        cin >> n;
	    int s[n], e[n];
	    vector<vector<int>> arr(n);

	    for(int i = 0; i < n; i++)
	        cin >> s[i];
	    for(int i = 0; i < n; i++)
	        cin >> e[i];
	    for(int i = 0; i < n; i++)
	        arr[i] = vector<int>({s[i], e[i], i + 1});
	    solve(arr);
	    cout << endl;
	}
	return 0;
}