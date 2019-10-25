number = int(input())
bits = []

power = 0
power_of_2 = 1
while True:
    if power_of_2 * 2 > number:
        break
    power_of_2 *= 2
    power += 1

for i in range(power + 1):
    bits.append(0)

while number != 0:
    number -= power_of_2
    bits[power] = 1
    while power_of_2 > number:
        power_of_2 = int(power_of_2 / 2)
        power -= 1

bits.reverse()
print(bits)