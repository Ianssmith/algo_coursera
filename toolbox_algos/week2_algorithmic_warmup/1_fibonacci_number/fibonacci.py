# Uses python3
def calc_fib(n):
    if (n <= 1):
        return n

    return calc_fib(n - 1) + calc_fib(n - 2)

def fast_fib(n):
	if (n <= 1):
		return n
	vec = []
	for i in range(n+1):
		if i<2:
			vec.append(i)
		else:
			vec.append(vec[i-1]+vec[i-2])
	return vec[-1]

n = int(input())
print(fast_fib(n))
