// Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

// Example 1:

// Input:
// N = 4
// X[] = 5,15,1,3
// Output:
// 5
// 10
// 5
// 4

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        if(maxHeap.size() == minHeap.size() + 2){
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        else if(minHeap.size() == maxHeap.size() + 2){
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
    }

    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return ((float)(maxHeap.top() + minHeap.top()) / 2);
        else if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else
            return minHeap.top();
    }
};