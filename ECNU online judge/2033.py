while 1:
	try:
		a = input()
		i = len(a)-1
		while(i >= 0):
			print("{}".format(a[i]), end='')
			i = i-1
		print("")
	except:
		break
