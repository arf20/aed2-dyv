#include <iostream>
#include <sys/time.h>

int main(int argc, char **argv) {
    if (argc < 2)
        return 1;

    int len = atoi(argv[1]);
    std::string mode;
    if (argc > 2)
        mode = std::string(argv[2]);

    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_usec);

    std::string sub[3] = {"acb", "aac", "dca"};

    if (mode == "" || mode == "random")
        for (int i = 0; i < len; i++)
            std::cout << "abcd"[rand() % 4];
    else if (mode == "worst")
        for (int i = 0; i < len; i+=3)
            std::cout << sub[rand()%3];
    else if (mode == "best")
        for (int i = 0; i < len; i++)
            std::cout << 'x';

    std::cout << std::endl;

    return 0;
}

