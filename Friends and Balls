boxes = int(input())

days = int(input())

work = []

count=[]

queries = []

newBoxes = list(map(int,(0,)*boxes))

for i in range(days):

    add = list(map(int,input().split()))

    work.append(add)

q = int(input())

for i in range(q):

    qDet = int(input())

    queries.append(qDet)

for i in range(days):

    start = work[i][0]

    end = work[i][1]

    for i in range(start-1,end):

        newBoxes[i]+=1

for i in queries:

    countNew=0

    for j in newBoxes:

        if(i<=j):

            countNew+=1

    count.append(countNew)

for i in count:

    print(i)

