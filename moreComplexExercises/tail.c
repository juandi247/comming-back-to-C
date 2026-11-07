#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



off_t starting_byte_counting_lines(int fd, int requestedLines);
void printFileFromPosition(int fd, off_t startingPosition);



int main(int argc, char **argv){

	if (argc!=3){
		printf("insuficient args \n");
	}


	char *fin; 
	const char *linesArg = argv[2];
	long int requestedLines = strtol(linesArg, &fin, 10);

	if (requestedLines<=0){
		printf("invalid number of lines to print tail \n");
		return 0;
	}


	int fd= open(argv[1], O_RDONLY);
	if (fd<0){
		printf("fd failed");
		return 0;
	}


	off_t startByte = starting_byte_counting_lines(fd,requestedLines);

	if (startByte<0){
		printf("error on the count_lines \n");
	}


	printFileFromPosition(fd, startByte);



	close(fd);
	return 0;
}


/*
 * can be more efficient if i just use a buffer and fill the buffer. Avoids the read() function everytime, instead we just look at O(buffer_size), which is MUCH faster. (but trickier to implement. thi siwll be a todooooooo)
 * */

off_t starting_byte_counting_lines(int fd, int requestedLines){
	//this fails automacially, byut helps us to set the lseek to the end in the -2, because 
	//the read does a +1 everytiem, so we just avoid doing a new seek curr -1, everytime
	lseek(fd, 1, SEEK_END);

	char currByte;
	int bytesRead ;
	//False, just to check ONCE, the last value
	int checkedLastValue = 0;
	int lineCount = 0;

	off_t bytePosition; 
	int total_read = 0;

	while (lineCount < requestedLines && (bytePosition = lseek(fd, -2, SEEK_CUR))>=0) {
		bytesRead = read(fd, &currByte, 1);

		if (bytesRead!=1){
			printf("error reading byte \n");
			return -2;
		}
		total_read++;

		if (currByte == '\n' && checkedLastValue){
			// printf("<line>");
			lineCount++;
		}else{
			// printf("%c",currByte);
		}
		checkedLastValue = 1;
	}

	// printf("\n total Read %d \n", total_read);
	// printf("curr positoin: %ld\n", bytePosition);


	//restart back to the initial file
	lseek(fd, 0, SEEK_SET);


	if (requestedLines == lineCount){
		//because the position endet on a \n value, if we dont do a +1, the output will have at the beggining a \n jump
		return bytePosition+1;
	}


	if (bytePosition == -1){
		return 0;
	}

	//assertoin, because this is weird
	return -1;

}


void printFileFromPosition(int fd, off_t startingPosition){
	if (startingPosition < 0 ){
		printf("invalid position \n");
		return;
	}


	lseek(fd, startingPosition, SEEK_SET);

	int bytesRead;
	char currByte; 
	while ( (bytesRead = read(fd, &currByte, 1))>0){
		printf("%c", currByte);
	}

}


