import math
def main():
	input = open('input.txt')
	line = input.readline()
	total = 0
	while(line):
		num = int(math.floor((int(line) / 3)) - 2)
		total += num
		line = input.readline()
	print("Total = " + str(total))
if __name__ == "__main__":
	main()
