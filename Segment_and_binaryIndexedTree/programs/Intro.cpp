/*
 segment tree:
 1. Used for fixed size arrays and two operations:
    a. range query (sum, min, max, gcd, etc) time complexity O(logn)
    b. range update (add, set, etc) time complexity O(logn)
 2. Requires O(n) space

size of array for segment tree is 2*2^ceil(log2(n)) - 1
which is upper bounded by 4*n
explanation:
   1. If n is a power of 2, then size of array is 2*n - 1
   2. If n is not a power of 2, then size of array is 2*x - 1
      where x is the smallest power of 2 greater than n
      x = 2^ceil(log2(n))
      size of array is 2*x - 1 = 2*2^ceil(log2(n)) - 1
      which is upper bounded by 4*n
*/

#include <iostream>
using namespace std;

// 1. naive approach
int getSumN(int arr[], int qs, int qe)
{
   int sum = 0;

   for (int i = qs; i <= qe; i++)
      sum = sum + arr[i];

   return sum;
}

void updateN(int arr[], int i, int newVal)
{
   arr[i] = newVal;
}

// 2. prefix sum approach
int getSum(int pre_sum[], int qs, int qe)
{
   if (qs == 0)
      return pre_sum[qe];

   else
      return pre_sum[qe] - pre_sum[qs - 1];
}

void update(int pre_sum[], int arr[], int i, int newVal, int n)
{
   int diff = newVal - arr[i];

   for (int j = i; j < n; j++)
      pre_sum[j] += diff;
}

void initialize(int pre_sum[], int arr[], int n)
{
   pre_sum[0] = arr[0];

   for (int i = 1; i < n; i++)
   {
      pre_sum[i] = pre_sum[i - 1] + arr[i];
   }
}

int main()
{
   int arr[] = {10, 20, 30, 40, 50}, n = 5;

   cout << getSum(arr, 0, 2) << " ";
   cout << getSum(arr, 1, 3) << " ";
   updateN(arr, 1, 60);
   cout << getSum(arr, 0, 2) << " ";
   cout << getSum(arr, 1, 3) << " ";
   //
   int pre_sum[n];

   initialize(pre_sum, arr, n);

   cout << getSum(pre_sum, 0, 2) << " ";
   cout << getSum(pre_sum, 1, 3) << " ";

   update(pre_sum, arr, 1, 60, n);

   cout << getSum(pre_sum, 0, 2) << " ";
   cout << getSum(pre_sum, 1, 3) << " ";

   return 0;
}
