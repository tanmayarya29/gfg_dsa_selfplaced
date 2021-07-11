"""
You are given a number N. You need to toggle the middle bit of N in binary form and print the result in decimal form.

If number of bits in binary form of N are odd then toggle the middle bit (Like 111 to 101).
If number of bits in binary form of N are even then toggle both the middle bits (Like 1111 to 1001)
Note: Toggling a bit means converting a 0 to 1 and vice versa.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single number N.

Output:
For each testcase, in a new line, print the decimal form after toggling the middle bit of N.

Constraints:
1 <= T <= 100
1 <= N <= 106

Examples:
Input:
5
1
2
3
4
5
Output:
0
1
0
6
7

Examples:
Testcase3: N=3. Binary is 11. Toggle the middle bits: 00. 00 in decimal is 0
Testcase5: N=5. Binary is 101. Toggle the middle bit: 111. 111 in decimal is 7

"""

def ToggleBits(n):
    a = bin(n)[2:]
    x = list(a)
    if len(a)%2 == 0:
        u = len(a)
        if x[(u//2)-1] == '1':
            x[(u//2)-1] = '0'
        elif x[(u//2)-1] == '0':
            x[(u//2)-1] = '1'
        if x[(u//2) + 1 - 1] == '1':
            x[(u//2) + 1 - 1] = '0'
        elif x[(u//2) + 1 - 1] == '0':
            x[(u//2) + 1 - 1] = '1'
    else:
        u = len(a)
        if x[((u+1)//2)-1] == '1':
            x[((u+1)//2)-1] = '0'
        elif x[((u+1)//2)-1] == '0':
            x[((u+1)//2)-1] = '1'
    y = "".join(x)
    return int(y,2)

if __name__ == '__main__':
    t = int(input())
    for c in range(t):
        n = int(input())
        print (ToggleBits(n))