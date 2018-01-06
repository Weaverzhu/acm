t = int(input())
for kk in range(t):
	a, b = map(int, input().split())
	c = a+b
	s = str(c)
	print(s.__len__())