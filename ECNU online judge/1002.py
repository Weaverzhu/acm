 import math

n=int(input())
for i in range(n):
    s=input()
    for j in range(3):
        str=s[j*8:(j+1)*8]
        sum=0
        for k in range(len(str)):
            temp=int(str[k])
            sum+=int(temp*math.pow(2,7-k))
        print(sum,end='')
        print(".",end='')
    
    str=s[24:32]
    sum=0
    for k in range(len(str)):
        temp=int(str[k])
        sum+=int(temp*math.pow(2,7-k))
    print(sum,end='')
    print()
