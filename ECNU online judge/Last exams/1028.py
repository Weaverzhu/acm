
t = int(input())
for kk in range(t):
	a = [[]]
	b = [[]]
	n, m = map(int, input().split())
	for i in range(n):
		a.append([])
		a[i] = list(map(int, input().split()))
	for i in range(n):
		b.append([])
		b[i] = list(map(int, input().split()))
	for i in range(n):
		for j in range(m):
			a[i][j] = a[i][j] + b[i][j]
	for i in range(n):
		for j in range(m-1):
			print("{} ".format(a[i][j]), end="")
		print(a[i][m-1])

