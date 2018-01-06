while True:
	try:
		a = int(input())
		if a == 0:
			print("1")
			continue
		elif a==1:
			print("0")
			continue
		else:
			if a % 2 == 1:
				print("4", end="")
			for i in range(int(a/2)):
				print("8", end="")
			print("")

	except:
		break;