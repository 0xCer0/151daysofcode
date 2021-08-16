// gallery with plants is divided into n parts, numbered : 0,1,2,3...n-1. There are provisions for attaching water sprinklers at every partition. A sprinkler with range x at partition i can water all partitions from i-x to i+x.
// Given an array gallery[ ] consisting of n integers, where gallery[i] is the range of sprinkler at partition i (power==-1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the complete gallery.
// If there is no possible way to water the full length using the given sprinklers, print -1.

// Example :
// Input:
// n = 6
// gallery[ ] = {-1, 2, 2, -1, 0, 0}
// Output:
// 2
// Explanation: Sprinklers at index 2 and 5
// can water thefull gallery, span of
// sprinkler at index 2 = [0,4] and span
// â€‹of sprinkler at index 5 = [5,5].
