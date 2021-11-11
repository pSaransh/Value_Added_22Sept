def calVal(top,top1,op):
    if op == '+':
        return top + top1
    elif op == '-':
        return top1 - top
    elif op == '*':
        return top * top1
    elif op == '/':
        return top1 // top
    elif op == '^':
        return top1**top
    else:
        return "Error"
tc = int(input())
while tc>0:
    pf = input()
    pf = pf.split()
    pfLs = []
    for i in pf:
        try:
            pfLs.append(int(i))
        except:
            pfLs.append(i)
    newLs = []
    for i in pfLs:
        if type(i)==int:
            newLs.append(i)
        else:
            res = calVal(newLs[-1],newLs[-2],i)
            newLs.pop()
            newLs.pop()
            newLs.append(res)
    print(newLs[0])
    tc-=1
