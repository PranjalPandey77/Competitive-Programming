T=int(input())
while T > 0 :
    N=int(input())
    ing=list()
    Hash={}
    for i in range(N):
        ing.append(input())
        for j in range(len(ing[i])):
            Hash[ing[i][j]]++
