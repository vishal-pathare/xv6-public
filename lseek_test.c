#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void) {

    int fd = open("./dummy.txt", O_RDWR);

    printf(1, "File opened successfully\n");

    write(fd, "The contents of a dummy file", 30);

    lseek(fd, 40, SEEK_END);

    /*char content[40];

    read(fd, content, 30);

    printf(1, content);

    printf(1, "\n");*/

    close(fd);
    exit();

}