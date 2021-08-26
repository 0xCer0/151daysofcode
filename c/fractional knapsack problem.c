// WAP to implement the fractional knapsack problem as discussed in class. Take the input from the illustrative example discussed
#include<stdio.h>
#include<stdlib.h>

void  fractionalKnapsack(int n, float weight[], float profit[], float capacity)
{
int i, j, u;
float x[20];
int tp = 0;
u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++)
   {
      if (weight[i] > u)
         break;
         else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }
   
   if (i < n)
      x[i] = u / weight[i];

   tp = tp + (x[i] * profit[i]);
   printf("\nThe Maximum profit will be : %d \n", tp);

}

int main() {

   float weight[100], profit[100], capacity;
   int num, i, j;
   float ratio[100], temp;

   printf("\nEnter the total number of objects : ");
   scanf("%d", &num);

   printf("\nEnter the weight of each object : \n");
   for (i = 0; i < num; i++) {
      scanf("%f", &weight[i]);
   }
   
   printf("\nEnter the profit of each object : \n");
   for (i = 0; i < num; i++) {
      scanf("%f", &profit[i]);
   }

   printf("\nEnter the capacityacity of knapsack :");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   for (i = 0; i < num; i++)
   {
      for (j = i + 1; j < num; j++)
      {
         if (ratio[i] < ratio[j])
         {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   fractionalKnapsack(num, weight, profit, capacity);
   return(0);
}

