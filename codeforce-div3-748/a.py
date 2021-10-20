def test(a, b, c):
    if a > max(b,c):
        return 0
    elif a == max(b,c):
        return 1
    else:
        return (max(b,c))-a+1

cases = int(input())

for c in range(cases):
    a, b, c = str(input()).split()
    a, b, c = int(a), int(b), int(c)
    print(test(a,b,c), test(b,a,c), test(c,b,a), )

