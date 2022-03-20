def sol(arr):
    arr.sort()
    #min pair difference
    min_diff = arr[1] - arr[0]
    for i in range(len(arr)-1):
        diff = arr[i+1] - arr[i]
        if diff < min_diff:
            min_diff = diff
    #find pairs
    for i in range(len(arr)-1):
        diff = arr[i+1] - arr[i]
        if diff == min_diff:
            print(str(arr[i])+" "+str(arr[i+1]))

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    sol(arr)
