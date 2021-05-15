T = int(input())
for t in range(1, T+1):
	Y0 = input()
	ans = "1"*20
	for Y in [Y0, '1'+'0'*len(Y0)]:
		for l0 in range(1, len(Y)//2+1):
			x0 = int(Y[:l0])
			lx = [x0, x0+1]
			for i in range(1, 20):
				x = 10**l0 - i
				if x > 0: lx.append(x)
			for x in lx:
				s = ""
				while len(s) < len(Y):
					s += str(x)
					x += 1
				if len(s) > len(Y) or s > Y:
					if len(s) < len(ans) or (len(s) == len(ans) and s < ans):
						ans = s
	print("Case #{}: {}".format(t, ans))