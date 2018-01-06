for i in range(1000, 10000):
	a = int(i/1000)
	b = int(i/100) % 10
	c = int(i/10) % 10
	d = i%10
	if (a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d) == i:
		print(i)