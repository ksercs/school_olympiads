from collections import deque
n, p = map(int, input().split())
arr = list(map(int, input().split()))
qq = int(input())
for i in range(qq):
    l, r, x = map(int, input().split())
    l -= 1
    g = [set([arr[i + l] % p]) for i in range(r - l)]
    if x in arr[l:r]:
        print("YES")
    else:
        q = deque()
        q.append(0)
        fl = True
        while len(q) > 0 and fl:
            v = q.popleft()
            cset = g[v]
            for j in range(v):
                for k in cset:
                    g[j].add((k + arr[j + l]) % p)
                    q.append(j)
                if x in g[j]:
                    fl = False
                    break
            for j in range(v + 1, r - l):
                for k in cset:
                    g[j].add((k + arr[j + l]) % p)
                    q.append(j)
                if x in g[j]:
                    fl = False
                    break
        if not fl:
            print("YES")
        else:
            print("NO")