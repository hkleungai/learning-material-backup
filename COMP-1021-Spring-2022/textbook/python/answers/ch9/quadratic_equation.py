import math

def quadratic_roots(a, b, c):
    d = b ** 2 - 4 * a * c
    if d < 0:
        return None, None

    d = math.sqrt(d)
    return (-b + d) / (2 * a), (-b - d) / (2 * a)

root1, root2 = quadratic_roots(2, 3, 1)

print("Root1 is", root1)
print("Root2 is", root2)
