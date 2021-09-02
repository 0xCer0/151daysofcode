// For a array sort using the quick sort. You may use the Rand function to increase the input size andmeasure the time for different sizes.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}
 
int main()
{
    int list[100];
    int size, i;
    clock_t t;
    t= clock();
    double cpu_time_used;
 
    printf("Enter the total number of elements in the array : ");
    scanf("%d", &size);
   
    int randArray[size];
    for(i=0;i<size;i++)
    {
    list[i]=rand()%100;
    }
    printf("Array before sorting ");
    for(int i=0;i<size;i++)
    {
    printf(" %d \n", list[i]);
   }
    quicksort(list, 0, size - 1);
    printf("After applying quick sort \n");
    for (i = 0; i < size; i++)
    {
        printf(" %d ", list[i]);
    }
    printf("\n");
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("\nThis algo took %f seconds to execute \n", time_taken);
    return 0;
}