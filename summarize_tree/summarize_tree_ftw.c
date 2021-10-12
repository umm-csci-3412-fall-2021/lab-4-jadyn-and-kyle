#include <stdio.h>
#include <ftw.h>

int file_counter;
int dir_counter;
static int callback(const char *fpath, const struct stat *sb, int typeflag){
    if(typeflag == FTW_F){
      file_counter++;
    }

    if(typeflag == FTW_D){
      dir_counter++;
    }
    return 0;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
    // Check arguments and set things up

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results
    printf("There were %d directories.\n", dir_counter);
    printf("There were %d regular files.\n", file_counter);
    return 0;
}


