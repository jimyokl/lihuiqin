#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main() {
    if (access("nonexistent_file.txt", F_OK) == -1) 
    {
        printf("Error: %s\n", strerror(errno));  // errno 会被设置为 ENOENT
        // Error: No such file or directory
    }
    return 0;
}

//an abbreviation of Error NO ENTry (or Error NO ENTity), 
// and can actually be used for more than files/directories.

//It's abbreviated because C compilers at the dawn of time didn't support more than 8 characters in symbols.