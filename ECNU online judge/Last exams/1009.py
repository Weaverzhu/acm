n = int(input())
a = []
for i in range(n):
	tmp = int(input())
	a.append(tmp)
a.sort()
q = int(input())
for i in range(q):
	tmp = int(input())
	print(a[tmp-1])