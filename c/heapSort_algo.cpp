// Q. WAP to implement themax-heap and min-heap to sort to follwing nos. using heapsort:
// 22, 88, 45, 9, 1 -9, 2, 56, 14.
// Also find the time for different input size entries.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int left, right, largest;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

   
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;

    
    if (largest != i) {
        swap(&arr[i], &arr[largest]); 
        heapify(arr, n, largest); 
    }
}

void heap_sort(int arr[], int n)
{
    int i;
    for (i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0); 
    }
}

int main()
{
    int arr[] = { 22, 88, 45, 9, 1 -9, 2, 56, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t t;
    t= clock();
    double cpu_time_used;

    printf("original Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    heap_sort(arr, n);

    printf("\nAfter performing Heap Sort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
   
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nThis algo took %f seconds to execute \n", time_taken);
    return 0;
}
