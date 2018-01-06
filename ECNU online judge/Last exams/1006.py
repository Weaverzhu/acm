t = int(input())
for kk in range(t):
	m, k = map(int, input().split())
	sum = 0
	a = list(map(int, input().split()))
	Sum = 0
	for i in range(k):
		Sum = Sum + a[i]
	print(Sum)

