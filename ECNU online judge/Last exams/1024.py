vis = [0]*501
n = int(input())
for i in range(n):
	tmp = int(input())
	vis[tmp] = 1
m = int(input())
for i in range(m):
	tmp = int(input())
	if (vis[tmp] == 1):
		print("yes!")
	else:
		print("no!")
