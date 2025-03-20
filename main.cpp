#include <iostream>
#include <string>
#include <set>
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

std::set<int> dyv(const std::string& A, const std::string sub[3], int i, int d) {
    // caso base
    if ((d - i + 1) < 6) {
        return std::set<int>{};
    } else if ((d - i + 1) < A.length()) {
        std::set<int> soluciones;
        for (int h = i; h + 5 <= d; h++) {
            if (comprobar(A, sub, h, h + 5))
                soluciones.insert(h);
        }
        return soluciones;
    }
    // dividir
    std::set<int> soli = dyv(A, sub, 0, A.length()/2 - 1);
    std::set<int> sold = dyv(A, sub, A.length()/2, A.length()-1);
    std::set<int> solc = dyv(A, sub, A.length()/2 - 5, A.length()/2 + 4);
    // combinar
    std::set<int> sol;
    sol.insert(soli.begin(), soli.end());
    sol.insert(sold.begin(), sold.end());
    sol.insert(solc.begin(), solc.end());
   
    return sol;
}

int main() {
    // "abbcabcddacbdcaaac"
    std::string A;
    std::cin >> A;

    std::string sub[3] = {"acb", "aac", "dca"};
    
    const std::set<int>& sol = dyv(A, sub, 0, A.length() - 1);

    printf("sol: %d {", sol.size());
    for (int s : sol) 
        printf("%d, ", s + 1);
    printf("}\n");
}

