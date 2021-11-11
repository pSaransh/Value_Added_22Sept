tc=int(input())
while tc>0:
    f = input()
    f = f.split()
    f0 = int(f[0])
    f1 = int(f[1])
    count=0
    while f1!=0:
        diff = abs(f1-f0)
        f0=f1
        f1=diff
        count+=1
    print(count)
    tc-=1
