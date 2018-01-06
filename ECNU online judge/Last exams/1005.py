t = int(input())
for kk in range(t):
	a = int(input())
	c0 = 0
	c1 = 0
	while a > 0:
		if a % 2 == 1:
			c1 = c1+1
		else:
			c0 = c0+1
		a = int(a/2)
	print("{} {}".format(c0, c1))