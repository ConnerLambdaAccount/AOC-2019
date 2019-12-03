#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 12
int main(void) {
	FILE* file = fopen("input.txt", "r");
	if(!file)
		return -1;
	int opcodes[2048];
	int cnt = 0;
	char buf[SIZE];
	memset(buf, 0, SIZE);
	char byte;
	
	// Translate all strings from input.txt into an integer array
	for(int i=0;(byte = fgetc(file)) != EOF;i++) {
		if(byte != ',') {
			buf[i] = byte;
		} else {
			opcodes[cnt] = atoi(buf); cnt++;
			memset(buf, 0, SIZE);
			i=-1;
		}
	}
	opcodes[cnt++] = atoi(buf);
	
	// Set input to 120ut to 1202 program alarm state
    opcodes[1] = 12;
	opcodes[2] = 2;
	
	// Run opcode operations
	for(int i=0;i<cnt;i+=4) {
		int operation = opcodes[i];
		int pos1 = opcodes[i+1];
		int pos2 = opcodes[i+2];
		int rpos = opcodes[i+3];
		switch(operation) {
			case 1:
				opcodes[rpos] = opcodes[pos1] + opcodes[pos2];
				break;
			case 2:
				opcodes[rpos] = opcodes[pos1] * opcodes[pos2];
				break;
			case 99:
				printf("Result: %i\n", opcodes[0]);
				exit(0);
		}
	}
}
