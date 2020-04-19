T = int(input())

def f(x, y):
	if x == 0 and y == 0: return ""
	if x == 1 and y == 0: return "E"
	if x == 0 and y == 1: return "N"
	if x == 0 and y == -1: return "S"
	if x == -1 and y == 0: return "W"
	mx, my = x % 2, y % 2
	if mx == my: return None
	if mx == 1:
		y2 = y // 2
		mmy = y2 % 2
		x2, d = ((x+1) // 2, "W") if ((x+1) // 2)%2 != mmy else ((x-1) // 2, "E")
	else:
		x2 = x // 2
		mmx = x2 % 2
		y2, d = ((y+1) // 2, "S") if ((y+1) // 2)%2 != mmx else ((y-1) // 2, "N")
	res = f(x2, y2)
	if res == None: return None
	return d + res

for t in range(1, T+1):
	X, Y = map(int, input().split())
	res = f(X, Y)
	if res == None: res = "IMPOSSIBLE"
	print("Case #{}: {}".format(t, res))