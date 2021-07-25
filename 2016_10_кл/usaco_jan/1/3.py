fin = open('angry.in', 'r')
fout = open('angry.out', 'w')
n = int(fin.readline())
arr = []
for i in range(n):
    arr.append(int(fin.readline()))
arr.sort()
razn = []
for i in range(n - 1):
    razn.append(arr[i + 1] - arr[i])
start = [1000000000 for i in range(n - 1)]
finish = start[::]
start[0] = razn[0]
finish[n - 2] = razn[n - 2]
for i in range(1, n - 1):
    start[i] = max(razn[i], start[i - 1] + 1)
for i in range(n - 3, -1, -1):
    finish[i] = max(razn[i], finish[i + 1] + 1)
minn = 1000000000
mi = 10000000000
for i in range(n - 1):
    if start[i] == finish[i]:
        if start[i] <= minn:
            if i == 0:
                mi = min(mi, start[i + 1] + 1, finish[i + 1] + 1)
            elif i == n - 2:
                mi = min(mi, start[i - 1] + 1, finish[i - 1] + 1)
            else:
                mi = min(mi, max(min(start[i - 1], finish[i - 1]), min(start[i + 1], finish[i + 1])) + 1)
            minn = start[i]
print(round(float(mi), 1), file=fout)
fout.close()
