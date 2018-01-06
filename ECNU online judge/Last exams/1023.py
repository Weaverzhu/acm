while 1:
	try:
		n = int(input())
		for i in range(2, int(n/2)+1):
			if (n % i == 0):
				print("{} {}".format(i, int(n/i)))
				break
	except:
		break