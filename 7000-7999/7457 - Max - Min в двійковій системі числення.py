n = int(input())
s1 = ''.join(sorted(bin(n)[2:]))
s2 = s1[::-1]
print(int(s2,2) - int(s1,2))
