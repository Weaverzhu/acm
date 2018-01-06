a, b, c = map(int, input().split())
print(a, b, c)
isl = 0
if (a % 400 == 0) isl = 1
if (a % 4 == 0 and a % 100 > 0) isl = 1
days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
s = [31]
len = days.__len__()
for i in range(1, len)
s.append(s[i-1]+days[i])
ans = s[a-1]
if a > 2:
	ans = ans + 1
ans = ans + c
print(ans)