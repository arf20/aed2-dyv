#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    for (int i = 0; i < atoi(argv[1]); i++) {
        std::cout << "abcd"[rand() % 4];
    }
    std::cout << std::endl;

    return 0;
}

