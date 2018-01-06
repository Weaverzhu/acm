import math
while True:
	h = float(input())
	if h == 0:
		break
	h = h-1
	
	if h <= 2:
		h = h*5
	else:
		h = 5*2 + (h-2)*3
	h = h+1.75
	print("%.3f" % (math.sqrt(2*h/9.8)))
