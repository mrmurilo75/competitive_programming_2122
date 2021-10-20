def result(b):
    a=b
    r = 0
    pos = int(a%100/10)
    r2=0
    while(a%25!=0):
        if(a%10 == 0):
            r1 = 0
            while(int(a%100/10)!=0 and int(a%100/10)!=5 and a>0):
                r1+=1
                a= (int(a/100) *10)
            if r!=0:
                r+=1
            return r+r1
        if a%10 == 5:
            while(int(a%100/10)!=7 and int(a%100/10)!=2 and a>10):
                r2+=1
                a= (int(a/100) *10) +5
            if(a<=10):
                while(int(b%10)!=0):
                    b = int(b/10)
                    r+=1
                a=b
                continue
            else:
                return r+r2
        r+=1
        a=int(a/10)
    return r

cases = int(input())

for c in range(cases):
    a = int(input())
    print(result(a))


