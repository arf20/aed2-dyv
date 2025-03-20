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

bool comprobar_dyn(const std::string& a, const std::string sub[3], int i, int d) {
    static std::map<std::string, bool> cache;

    std::string suba = a.substr(i, d - i + 1);

    std::map<std::string, bool>::const_iterator it = cache.end();
    if ((it = cache.find(suba)) != cache.end()) {
        return it->second;
    } else {
        bool sol = 
            (suba == sub[0] + sub[1]) ||
            (suba == sub[0] + sub[2]) ||
            (suba == sub[1] + sub[0]) ||
            (suba == sub[1] + sub[2]) ||
            (suba == sub[2] + sub[0]) ||
            (suba == sub[2] + sub[1]);
        
        cache.insert({suba, sol});

        return sol;
    }
}

void dyv(const std::string& A, const std::string sub[3], int i, int d,
    std::set<int>& sol)
{
    int len = (d - i + 1);
    // caso base
    if (len < 6) {

    } else if (len == 6) {
         if (comprobar(A, sub, i, d))
            sol.insert(i);
    } else {
        // dividir
        dyv(A, sub, i, i + ((len/2) - 1), sol); // mitad izq
        dyv(A, sub, i + (len/2), d, sol); // mitad dcha
        // combinar 
        for (int h = std::max(i + ((len/2) - 5), 0); h + 5 <= std::min(i + ((len/2) + 4), d); h++)
            if (comprobar(A, sub, h, h + 5))
                sol.insert(h);
    }
}

void dyv_dyn(const std::string& A, const std::string sub[3], int i, int d,
    std::set<int>& sol)
{
    int len = (d - i + 1);
    // caso base
    if (len < 6) {

    } else if (len == 6) {
         if (comprobar_dyn(A, sub, i, d))
            sol.insert(i);
    } else {
        // dividir
        dyv(A, sub, i, i + ((len/2) - 1), sol); // mitad izq
        dyv(A, sub, i + (len/2), d, sol); // mitad dcha
        // combinar 
        for (int h = std::max(i + ((len/2) - 5), 0); h + 5 <= std::min(i + ((len/2) + 4), d); h++)
            if (comprobar_dyn(A, sub, h, h + 5))
                sol.insert(h);
    }
}


int main(int argc, char **argv) {
    // "abbcabcddacbdcaaac"
    std::string A;
    std::cin >> A;

    std::string sub[3] = {"acb", "aac", "dca"};
    
    std::set<int> sol;

    if (argc == 2) {
        std::string arg(argv[1]);
        if (arg == "-dyv")
            dyv(A, sub, 0, A.length() - 1, sol);
        else if (arg == "-normal") {
            for (size_t h = 0; h + 5 <= A.length(); h++)
                if (comprobar(A, sub, h, h + 5))
                    sol.insert(h);
        } else if (arg == "-dyvdyn") {
            dyv_dyn(A, sub, 0, A.length() - 1, sol);
        } else if (arg == "-dyn") {
            for (size_t h = 0; h + 5 <= A.length(); h++)
                if (comprobar_dyn(A, sub, h, h + 5))
                    sol.insert(h);
        } else
            return 1;

    } else 
        dyv(A, sub, 0, A.length() - 1, sol);

    printf("sol: %ld {", sol.size());
    for (int s : sol) 
        printf("%d, ", s + 1);
    printf("}\n");
}

