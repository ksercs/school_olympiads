fin = open('castle.in', 'r')
fout = open('castle.out', 'w')
n = int(fin.readline())
L = 1
R = n
while (R - L > 1):
    ##print(L, R)
    M = L + (R-L)//2
    zn = M*(M+1)//2
    if (zn == n):
        ans = M
        R = M
        L = M
    if (zn > n):
        R = M-1
    if (zn < n):
        L = M
zn = R*(R+1)//2
if (zn <= n):
    ans = R
else:
    ans = L

print(ans, file = fout)
fout.close()
