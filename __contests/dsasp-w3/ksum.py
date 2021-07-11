def getKsum(ar,x):
    ar = sorted(ar)
    return sum(ar[:x])
    
if __name__ == '__main__':
    inp = int(input())
    for i in range(inp):
        a,b = list(map(int,input().strip().split()))
        ar = list(map(int,input().strip().split()))
        print (getKsum(ar,b))