c = [[0 for i in range(31)] for i in range(31)]
c[0][0] = 1
for i in range(1, 31):
	c[i][0] = 1
	c[i][i] = 1
	for j in range(1, i):
		c[i][j] = c[i-1][j-1] + c[i-1][j]
while True:
	n = int(input())
	if n == 0:
		break
	for i in range(0, n):
		for j in range(0, i):
			print("{} ".format(c[i][j]), end="")
		print(c[i][i])
	print("")
