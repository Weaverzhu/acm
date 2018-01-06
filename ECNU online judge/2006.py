
ia = [1] * 1002000
i = 1
while(i <= 1000000):
	tmp = i
	sum = 0
	while(tmp > 0):
		sum = sum + (tmp % 10)
		tmp = int(tmp/10)
		print(tmp)
	sum = int(sum)
	ia[i+sum] = 0
	i = i+1
i = 1
while(i <= 1000000):
	if ia[i] == 1:
		print(i)
	i = i+1
