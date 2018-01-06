while 1:
	try:
		n = int(input())
		for i in range(n):
			t = n-i
			for j in range(t):
				print(" ", end="")
			for j in range(2*i+1):
				print("*", end="")
			for j in range(t):
				print(" ", end="")
			print("")
		for i in range(2*n+1):
			print("*", end="")
		print("")
		for i in range(n):
			for j in range(i+1):
				print(" ", end="")
			for j in range(2 * (n-i-1) + 1):
				print("*", end="")
			for j in range(i+1):
				print(" ", end="")
			print("")
	except:
		break