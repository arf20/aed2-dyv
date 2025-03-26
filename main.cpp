#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

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
    std::set<int>& sol)
{
    //longitud de cadena
    int len = (d - i + 1);
    // caso base
    if (len < 6) {
    // caso base
    } else if (len == 6) {
         if (comprobar(A, sub, i, d))
            sol.insert(i);
    } else {
        // dividir
        dyv(A, sub, i, i + ((len/2) - 1), sol); // mitad izq
        dyv(A, sub, i + (len/2), d, sol); // mitad dcha
        // combinar
        for (int h = std::max(i + ((len/2) - 5), i); h + 5 <= std::min(i + ((len/2) + 4), d); h++)
            if (comprobar(A, sub, h, h + 5))
                sol.insert(h);
    }
}


int main(int argc, char **argv) {
    //Cadena principal
    std::string A;
    std::cin >> A;
    //Subcadenas
    std::string sub[3] = {"acb", "aac", "dca"};
    //Solución
    std::set<int> sol;

   
        dyv(A, sub, 0, A.length() - 1, sol);

    printf("sol: %ld {", sol.size());
    for (int s : sol)
        printf("%d, ", s + 1);
    printf("}\n");
}

