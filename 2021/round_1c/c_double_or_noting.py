T = int(input())
for t in range(1, T+1):
	S, E = input().split()
	def conv(s):
		if s == '0': return []
		r = []
		i = 0
		while i < len(s):
			j = i+1
			while j < len(s) and s[i] == s[j]:
				j += 1
			r.append(j-i)
			i = j
		return r
	s = conv(S)
	if E == '0':
		print("Case #{}: {}".format(t, len(s)))
		continue
	ans = 0
	if s == []:
		s = [1]
		ans = 1
	e = conv(E)
	if (len(s)+1)//2 < (len(e)+1)//2:
		print("Case #{}: {}".format(t, "IMPOSSIBLE"))
		continue
	if len(s) <= len(e) and len(s)&1: s += [0]
	m = 0
	for i in range(1, len(e)+1):
		if s[-i:-1] == e[:i-1] and s[-1] <= e[i-1]:
			m = i
	if m > 0: ans += e[m-1] - s[-1]
	ans += sum(e[m:]) + len(s) - m
	print("Case #{}: {}".format(t, ans))