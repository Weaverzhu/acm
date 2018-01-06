s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
t = int(input())
for kk in range(t):
	n, r = map(int, input().split())
	a = []
	if n < 0:
		print("-", end="")
		n = -n
	elif n == 0:
		print(0)
		continue
	while n > 0:
		now = int(n%r)
		if now >= 10:
			now = s[now-10]
		a.append(now)
		n = int(n/r)
	sz = a.__len__()-1
	while sz >= 0:
		print(a[sz], end="");
		sz = sz-1
	print("")