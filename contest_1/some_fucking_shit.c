#include <stdio.h>
static int process_file(const unsigned char *path);

int main(int argc, char **argv) {
    if (argc == 1) return 0;

    printf("SHIT : %d", process_file(argv[1]));
}
