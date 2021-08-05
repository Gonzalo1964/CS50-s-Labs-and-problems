from cs50 import get_float

while True:
    k = get_float("Changed owed: ")
    if (k >= 0):
        break

c = round(k*100)

i = 0

while (c >= 25):
    c -= 25
    i += 1

while (c >= 10):
    c -= 10
    i += 1

while (c >= 5):
    c -= 5
    i += 1

while (c >= 1):
    c -= 1
    i += 1

print(f"Coins: {i}")