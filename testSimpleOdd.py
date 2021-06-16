#!/usr/bin/python3

def checkOddArray2(a):
    odd = 0
    for i in range(8):
        odd = (odd + a[i])  %  2
        print("odd=",odd)
    return odd

def sum(a):
    ret=0
    for element in a:
        ret+=element
    return ret

array = [17, 18, -17, -1, 0, -9, 17, -18]
print(checkOddArray2(array))
print(sum(array))