import math
def main():
	input = open('input.txt')
	line = input.readline()
	total = 0
	while(line):
		mass = int(line)
		fuel = math.floor(mass / 3) - 2
		while(fuel > 0):
			total += fuel
			fuel = math.floor(fuel / 3) - 2
		line = input.readline()
	print("Total = " + str(int(total)))
if __name__ == "__main__":
	main()
