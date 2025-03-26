#include <iostream>
#include <string>
#include <set>

bool comprobar(const std::string& a, const std::string sub[3], int i, int d) {
    // construir subcadena para comprobar
    std::string suba = a.substr(i, d - i + 1);
    // comprobar subcadena con permutaciones de las dos subcadenas del patron
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
        // caso sub-base
    } else if (len == 6) {
        // caso base
        if (comprobar(A, sub, i, d))
           sol.insert(i);
    } else {
        // dividir
        dyv(A, sub, i, i + ((len/2) - 1), sol); // mitad izq
        dyv(A, sub, i + (len/2), d, sol); // mitad dcha
        // combinar 
        for (int h = std::max(i + ((len/2) - 5), 0); 
                h + 5 <= std::min(i + ((len/2) + 4), d); h++)
            if (comprobar(A, sub, h, h + 5))
                sol.insert(h);
    }
}

int main() {
    // leer cadena
    std::string A;
    std::cin >> A;

    // subcadenas a 2-permutar para patron
    std::string sub[3] = {"acb", "aac", "dca"};
    
    // conjunto de soluciones
    std::set<int> sol;

    // iniciar divide y venceras
    dyv(A, sub, 0, A.length() - 1, sol);

    // imprimir soluciones
    for (int s : sol) 
        printf("%d, ", s + 1);
    // imprimir numero de soluciones
    printf("\nsol: %ld\n", sol.size());
}

