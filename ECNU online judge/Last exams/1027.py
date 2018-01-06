while 1:
	try:
		s = input()
		for i in range(s.__len__()):
			print(s[-i-1], end="")
		print("")
	except:
		break