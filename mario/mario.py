from cs50 import get_int

while True:
    h = get_int("Height: ")
    if h >= 1 and h <= 8:
        break

for i in range(h):
    for j in range(h):
        if i + j > h - 1 or i + j == h - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print()
