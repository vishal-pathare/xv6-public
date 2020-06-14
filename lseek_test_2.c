#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {

    int fd1 = open(argv[1], O_RDWR);

    int len = lseek(fd1, 0, SEEK_END);

    printf(1, "The length of the file is : %d\n", len);

    int len_of_part = len / 10;

    int fd2 = open("copy", O_CREATE | O_RDWR);

    int i = 1;

    char *string = (char *)malloc(sizeof(char) * (len_of_part + 1));

    for (int j = 0; j < 10; j++) {

        lseek(fd1, len_of_part * i, SEEK_SET);

        read(fd1, string, len_of_part);

        string[len_of_part] = '\0';

        lseek(fd2, len_of_part * i, SEEK_SET);

        write(fd2, string, len_of_part);

        if (i % 2 == 0) {

            i += 3;

        }

        else {

            i--;

        }

    }

    char *test_string_orig = (char *)malloc(sizeof(char) * (len_of_part + 1));

    char *test_string_new = (char *)malloc(sizeof(char) * (len_of_part + 1));    

    test_string_orig[len_of_part] = '\0';

    test_string_new[len_of_part] = '\0';

    if (!strcmp(test_string_orig, test_string_new)) {

        printf(1, "The files are identical\n");

    }

    else {

        printf(1, "The files are not identical\n");

    }

    close(fd1);

    close(fd2);

    exit();

}