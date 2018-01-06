while True:
	n = int(input())
	if (n == -1):
		break
	a = int(n/3600)
	n = n - a*3600
	b = int(n/60)
	n = n-60*b
	c = n
	if (a < 10):
		print(0, end="")
	print(a, end=":")
	if (b < 10):
		print(0, end="")
	print(b, end=":")
	if (c < 10):
		print(0, end="")
	print(c)
