fin = open('input.txt', 'r')
fout = open('output.txt', 'w')

n = int(fin.readline().strip())
#n, d = map(int, fin.readline().strip().split())
#num = ['']*(n+2)
#for i in range (1, n+1):
#   num[i] = fin.readline().strip()
el = []
ss = ''
u = [0]*12
ans = []
s = ''

def check():
    #print('CHECK\n')
    ch = 0
    s = ''
    for i in range (0, n):
        s += num[int(ss[i])]
    for i in range (0, len(s)):
        ch += int(s[i])*pow(10, len(s)-i-1)
    if (not(ch%d)): return True
    return False

def dfs_R(ind):
    global ss
    #print('DFS : ', ind)
    if (ind == n): #and check()):
        ans.append(ss)
    else:
        for i in range (1, n+1):
            if not(u[i]):
                u[i] = 1
                ss = ss[:ind]+str(i)+ss[ind+1:]
                dfs_R(ind+1)
                u[i] = 0
    
for i in range(1, n+1):
    el.append(i)
    ss += ' '
dfs_R(0)
#print(len(ans), file = fout)
ans.sort()
for i in ans:
    print(i)
fout.close()    
