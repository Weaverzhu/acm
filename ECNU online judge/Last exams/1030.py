t = int(input())
for kk in range(t):
	s = input()
	nc = 0
	nn = 0
	for i in s:
		x = int(ord(i))
		if (x >= 48 and x <= 57):
			nn = nn+1
		elif (x >= ord('a') and x <= ord('z')) or (x >= ord('A') and x <= ord('Z')):
			nc = nc+1
	no = s.__len__() - nc - nn
	print("character:{}".format(nc))
	print("number:{}".format(nn))
	print("others:{}".format(no))
