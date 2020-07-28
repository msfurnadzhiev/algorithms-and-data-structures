# performs the Euclidean algorithm
# returns greatest common divisor of a and b
# time-complexity of algorithm: O(len(a)len(b))

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)



# performs the extended Euclidian algorithm
# returns gcd of a and b, and coefficient x and y (such that ax + by = gcd(a,b))
# time-complexity of algorithm: O(len(a)len(b))

def xgcd(a, b):

    if a == 0:
        return b, 0, 1

    gcd, old_x, old_y = xgcd(b%a, a)

    x = old_y - (b // a) * old_x
    y = old_x

    return gcd, x, y