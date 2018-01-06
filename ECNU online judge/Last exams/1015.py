n = int(input())
vis = [0]*30
for i in range(n):
	a = list(map(int, input().split()))
	for i in range(a.__len__()-1):
		vis[a[i]-1] = 1
suc = True
for i in range(30):
	if vis[i] == 0:
		suc = False
		break
if suc:
	print("yes")
else:
	print("no")