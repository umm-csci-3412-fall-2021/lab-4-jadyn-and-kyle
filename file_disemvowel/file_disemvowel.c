#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUF_SIZE 1024

bool is_vowel(char letter) {
    /*
     * Returns true if letter is a vowel (upper or lower case), and
     * false otherwise.
     */
     return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' ||letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U');
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
     int x = 0;
     for(int i=0; i<num_chars; i++) {
     	if(!is_vowel(in_buf[i])) {
		out_buf[x] = in_buf[i];
		x++;
	}
     }
     return x;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
     char* input_buffer;
     input_buffer = (char*) calloc(BUF_SIZE, sizeof(char));
     char* output_buffer;
     output_buffer = (char*) calloc(BUF_SIZE, sizeof(char));
     int num_chars = 1;
     int nonvowels;
     while(num_chars!=0) {
     	num_chars = fread(input_buffer, sizeof(char), BUF_SIZE, inputFile);
        nonvowels = copy_non_vowels(num_chars, input_buffer, output_buffer);
        fwrite(output_buffer, sizeof(char), nonvowels, outputFile);	
     }
     
     free(input_buffer);
     free(output_buffer);
}

int main(int argc, char *argv[]) {
    // This sets these to `stdin` and `stdout` by default.
    // You then need to set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile;
    FILE *outputFile;

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.
    if(argc==1){
      inputFile = stdin;
      outputFile = stdout;
    }
    else if(argc==2){
      inputFile = fopen(argv[1], "r");
      outputFile = stdout;
    }
    else if(argc==3){
      inputFile = fopen(argv[1], "r");
      outputFile = fopen(argv[2], "w+");
    }
    disemvowel(inputFile, outputFile);
    
    return 0;
}
