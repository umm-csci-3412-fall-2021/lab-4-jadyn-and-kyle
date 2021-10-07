#include <stdio.h>
#include <stdbool.h>

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
     	if(!isVowel(in_buf[i])) {
		out_buf[x] = in_buf[i];
		x++;
	}
     }
     return out_buf;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
     int inlen = strlen(str);
     int outlen=0;
     for(int i=0; i<inlen; i++) {
	     if(!isVowel(str[i])) {
	     	outlen++;
	     }
     }
     char* output = (char*) calloc(outlen + 1, sizeof(char));
     int outpos = 0;
     for(int i=0; outpos < outlen; i++){
	     if(!isVowel(str[i])){
		     output[outpos++]=str[i];
	     }
     }
     output[outlen] = '\0';

     return output;
}

int main(int argc, char *argv[]) {
    // This sets these to `stdin` and `stdout` by default.
    // You then need to set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile = stdin;
    FILE *outputFile = stdout;

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);

    return 0;
}
