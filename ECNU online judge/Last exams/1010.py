
t = int(input())
for kk in range(t):
	s = input()
	x1 = 0
	x2 = 0
	x3 = 0
	x4 = 0
	for i in range(0, 8):
		tmp = int(s[i])
		x1 = x1*2 + tmp
	for i in range(8, 16):
		tmp = int(s[i])
		x2 = x2*2 + tmp
	for i in range(16, 24):
		tmp = int(s[i])
		x3 = x3*2 + tmp
	for i in range(24, 32):
		tmp = int(s[i])
		x4 = x4*2 + tmp
	print("{}.{}.{}.{}".format(x1, x2, x3, x4))