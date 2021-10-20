def result(n, mice):
    for i in range(len(mice)):
        mice[i]=int(mice[i])
    mice.sort()
    cat = 0
    saved = 0
    for i in range(len(mice)-1, -1, -1):
        if(mice[i]<=cat):
            return saved
        cat+=n-mice[i]
        saved+=1

for c in range(int(input())):
    print(result( int(str(input()).split()[0]), str(input()).split()))

