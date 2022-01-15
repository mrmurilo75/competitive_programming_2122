DBG = False

sa, sN = input().split()
a = int(sa)
N = int(sN)
x = 1
visited = {}

def operationA(x):
    return x*a

def operationB(x):
    s = str(x)
    s = s[0]+s[:len(s) -1]
    return int(s)

def main():
    if(x == N):
        return 0

    q = []
    qc = []
    q.append(x)
    qc.append(1)
    c=1
    while(len(q) > 0):

        cur = q.pop(0)
        cur_c = qc.pop(0)

        if(cur in visited):
            continue

        visited += {cur}

        if(DBG):
            print(cur, cur_c)

        if(cur <= 10):
            cur_res = operationA(cur)
            if(cur_res == N):
                return cur_c
            if(cur_res < N):
                q.append(cur_res)
                qc.append(cur_c +1)

            continue

        cur_resA = operationA(cur)
        cur_resB = operationB(cur)

        if(cur_resA == N or cur_resB == N):
            return cur_c

        if(cur_res < N):
            q.append(cur_resA)
            qc.append(cur_c +1)

            q.append(cur_resB)
            qc.append(cur_c +1)

    return -1

print(main())
