def getkey(x):
	now = int(x)
	if now < 0:
		now = -now
	return now

while True:
	try:
		a = []
		n = int(input())
		a = list(map(int, input().split()))
		a.sort(key = getkey)
		sz = a.__len__()
		for i in range(sz-1):
			print("{} ".format(a[i]), end="")
		print(a[sz-1])
	except:
		break