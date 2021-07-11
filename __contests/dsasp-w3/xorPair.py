def getXorPair(ar,x,y):#main fucction
    ans = 0
    stt = set()
    for i in range(x):
        if (y ^ ar[i]) in stt:
            ans += 1
        stt.add(ar[i])
    if ans > 0:
        return "Yes"
    else:
        return "No"



#initialisation fucnton
if __name__ == '__main__':
    userInput = int(input())
    for i in range(userInput):
        a,b = list(map(int,input().strip().split()))
        ar = list(map(int,input().strip().split()))
        print (getXorPair(ar,a,b))