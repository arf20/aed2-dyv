#include <iostream>
#include <string>
#include <set>

bool comprobar(const std::string& a, const std::string sub[3], int i, int d) {
    std::string suba = a.substr(i, d - i + 1);
    return
        (suba == sub[0] + sub[1]) ||
        (suba == sub[0] + sub[2]) ||
        (suba == sub[1] + sub[0]) ||
        (suba == sub[1] + sub[2]) ||
        (suba == sub[2] + sub[0]) ||
        (suba == sub[2] + sub[1]);
}

void dyv(const std::string& A, const std::string sub[3], int i, int d,
    std::set<int>& sol
) {
    int len = (d - i + 1); // longitud de subcadena
    if (len < 6) {
    } else if (len == 6) {
        if (comprobar(A, sub, i, d))
           sol.insert(i);
    } else {
        dyv(A, sub, i, i + ((len/2) - 1), sol); // mitad izq
        dyv(A, sub, i + (len/2), d, sol); // mitad dcha
        for (int h = std::max(i + ((len/2) - 5), 0); 
                h + 5 <= std::min(i + ((len/2) + 4), d); h++)
            if (comprobar(A, sub, h, h + 5))
                sol.insert(h);
    }
}

int main(int argc, char **argv) {
    std::string A;
    std::cin >> A;

    std::string sub[3] = {"acb", "aac", "dca"};
    
    std::set<int> sol;

    if (argc == 2 && std::string(argv[1]) == "-dyv") {
        dyv(A, sub, 0, A.length() - 1, sol);
    } else if (argc == 2 && std::string(argv[1]) == "-dir") {
        for (int i = 0; i + 5 <= ((int)A.length() - 1); i++)
            if (comprobar(A, sub, i, i + 5))
                sol.insert(i);
    } else {
        dyv(A, sub, 0, A.length() - 1, sol);
    }

    for (int s : sol) 
        printf("%d, ", s + 1);
    printf("\nsol: %ld\n", sol.size());
}

