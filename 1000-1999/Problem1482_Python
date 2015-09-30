an,am = [int(x) for x in input().split()]
A = [[int(x) for x in input().split()] for i in range(an)]

bn,bm = [int(x) for x in input().split()]
B = [[int(x) for x in input().split()] for i in range(bn)]

if am == bn:
    C = [[str(sum(A[i][g]*B[g][j] for g in range(am))) for j in range(bm)] for i in range(an)]
    print(an, bm)
    for line in C:
        print(" ".join(line))
else:
    print(-1)
