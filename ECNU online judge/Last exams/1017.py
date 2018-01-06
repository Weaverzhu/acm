n = int(input())
a = list(map(int, input().split()))
a.sort()
for i in range(a.__len__()-1):
	print("{} ".format(a[i]), end="")
print(a[a.__len__()-1])