t = int(input())
for kk in range(t):
	a, b, h = map(int, input().split())
	print("%.2f" % (h/a*b))