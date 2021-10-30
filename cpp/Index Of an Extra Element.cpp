// Given two sorted arrays of distinct elements. There is only 1 difference between the arrays. First array has one element extra added in between. Find the index of the extra element.

// Example 1:

// Input:
// N = 7
// A[] = {2,4,6,8,9,10,12}
// B[] = {2,4,6,8,10,12}
// Output: 4
// Explanation: In the second array, 9 is
// missing and it's index in the first array
// is 4.

int findExtra(int a[], int b[], int n) {
    int i = 0, j = n - 1;

    while(i <= j){
        int m = (i + j) / 2;
        if(m == n)
            return m;
        else if(a[m] == b[m])
            i = m + 1;
        else if(a[m] != b[m])
            j = m - 1;
    }
    return i;
}