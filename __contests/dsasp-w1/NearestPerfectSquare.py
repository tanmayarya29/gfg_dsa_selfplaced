import math

def fun(sqrA,sqrB,x):
    if abs(sqrA-x) == abs(sqrB-x):
        return max(sqrA,sqrB)
    else:
        lowr = min(abs(sqrA-x),abs(sqrB-x))
        if lowr == abs(sqrA-x):
            return sqrA
        else:
            return sqrB

def findPrfct(x):
    getSqr = math.sqrt(x)
    if str(getSqr).split('.')[1]=='0':
        p,q = int(getSqr)-1,int(getSqr)+1
        differenceP,differenceQ = abs(p**2 - x),abs(q**2 - x)
        if min(differenceP,differenceQ) == differenceP:
            return p**2
        else:
            return q**2
    a,b = math.floor(getSqr),math.ceil(getSqr)
    sqrA,sqrB = a**2,b**2
    return fun(sqrA,sqrB,x)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        x = int(input())
        print (findPrfct(x))