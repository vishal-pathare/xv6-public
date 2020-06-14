#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {

    char *file_name = argv[1];

    int offset = atoi(argv[2]);

    int len = atoi(argv[3]);

    char *string = argv[4];

    int fd = open(file_name, O_RDWR);

    if (fd != -1) 

        printf(1, "File opened successfully\n");

    else {

        printf(1, "File could not be opened\n");

        exit();

    }        

    if (lseek(fd, offset, SEEK_SET) == -1) {

        printf(1, "Lseek failed\n");

    }

    char content[100];

    int ret_read = read(fd, content, len);

    content[ret_read] = '\0';

    printf(1, "The expected string is : %s\n", string);

    printf(1, "The string got by read is : %s\n", content);

    if (!strcmp(string, content)) {

        printf(1, "Content verified\n");

    }

    else {

        printf(1, "Content unable to be verified\n");

    }

    close(fd);

    exit();

}