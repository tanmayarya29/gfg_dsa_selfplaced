"""
Given an array arr[] of N positive integers. The task is to find a subsequence with maximum sum such that there should be no adjacent elements from the array in the subsequence.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains size of array N. Next line contains N elements of the array space seperated.

Output:
For each testcase, print the maximum sum of the subsequence.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106

Example:
Input:
2
3
1 2 3
3
1 20 3

Output:
4
20

Explanation:
Testcase 1: Elements 1 and 3 form a subsequence with maximum sum and no elements in the subsequence are adjacent in the array.
Testcase 2: Element 20 from the array forms a subsequence with maximum sum.

"""

def withoutAdjacent(arr): 
    incl = 0
    excl = 0
     
    for i in arr: 
          
        # Current max excluding i (No ternary in  
        # Python) 
        new_excl = excl if excl>incl else incl 
         
        # Current max including i 
        incl = excl + int(i)
        excl = new_excl 
      
    # return max of incl and excl 
    return (excl if excl>incl else incl) 

if __name__ == '__main__':
    t = int(input())
    for c in range(t):
        N = int(input())
        arr = input().strip().split()
        print (withoutAdjacent(arr))