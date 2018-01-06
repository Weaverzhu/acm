t = int(input())
for kk in range(t):
	n, m = map(int, input().split())
	x = int(n/m)
	ans = 0
	if (x%5 == 4):
		if (x == 4):
			print(5)
			continue
		else:
			ans = 3+x
			x = x - 9
			ans = ans + int(x/5)*2
	else:
		ans = x
		ans = ans + int(x/5)*2
		if (x%5 == 3):
			ans = ans + 1
	print(ans)