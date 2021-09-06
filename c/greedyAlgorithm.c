// WAP to implement the activity slecetion problem using Greedy algo

#include<stdio.h> 
#include<stdlib.h> 

void activitiesSelection(int a[],int s[], int f[], int n) 
{
    int i, j; 
    printf ( "Selected Activities are: \n"); 
    i = 0; 
    printf( "%d ",&a[i]); 
    for (j = 1; j < n; j++) 
    { 
        if (s[j] >= f[i]) 
        {
            printf ( "%d ",&a[j]); 
            i = j; 
        }
    }
}

            
int main() 
    {
         int s[100],f[100],a[100], n, c, d, swap,swap1,swap2; 
         printf("Enter number of elements\n"); 
         scanf( "%d",&n); 
         printf("Enter %d integers of Item Number\n", n); 
         for (c = 0; c < n; c++)
            scanf( "%d ", &a[c]); 
            printf("Enter %d integers of start time\n", n); 
            for (c = 0; c < n; c++) 
            scanf( "%d ", &s[c]); 
            printf("Enter %d integers of end time\n", n); 
            for (c = 0; c < n; c++) 
            scanf("%d ", &f[c]); 
for (c = 0; c < n-1; c++) 
{ 
    for (d = 0 ; d < n-c-1; d++) 
    { 
        if (f[d] > f[d+1]) s[d+1] = swap; 
        swap1 = f[d]; f[d]= f[d+1]; 
        f[d+1] = swap1; swap2 = a[d]; 
        a[d]= a[d+1]; a[d+1] = swap2; 
    }
}
        activities(a,s, f, n); 
        return 0;
}