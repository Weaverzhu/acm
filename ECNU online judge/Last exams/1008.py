while True:
	try:
		e, f, c = map(int, input().split())
		ans = 0
		e = e + f
		while True:
			now = int(e/c)
			ans = ans + now
			e = e - now*c
			e = e + now
			if int(e/c) == 0:
				break
		print(ans)
	except:
		break
