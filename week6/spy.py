tc = int(input())
while tc>0:
    relPos = list(map(int,input().split()))
    relPos = relPos[1:]
    relPos.sort()
    relLen = len(relPos)
    if(relLen%2!=0):
        print(relPos[relLen//2])
    else:
        print(relPos[(relLen//2)-1])
    tc-=1
