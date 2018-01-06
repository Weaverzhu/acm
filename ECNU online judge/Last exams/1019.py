n = int(input())
a = []
for i in range(n):
	tmp = int(input())
	a.append(tmp)
a.sort()
sz = a.__len__()
for i in range(sz):
	print(a[i])
