#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Generar cadena para mejor caso (n = 6 * 2^k)
std::string generarMejorCaso(int n) {
    std::string subcadenas[3] = {"acb", "aac", "dca"};
    std::string resultado;
    for (int i = 0; i < n / 6; i++) {
        resultado += subcadenas[i % 3] + subcadenas[(i + 1) % 3];
    }
    return resultado;
}

// Generar cadena para peor caso (combinaciones costosas)
std::string generarPeorCaso(int n) {
    std::string resultado;
    for (int i = 0; i < n; i++) {
        resultado += (char)('a' + (rand() % 26)); // Letras aleatorias
    }
    return resultado;
}

// Generar cadena para caso promedio
std::string generarCasoPromedio(int n) {
    std::string subcadenas[3] = {"acb", "aac", "dca"};
    std::string resultado;
    for (int i = 0; i < n / 6; i++) {
        resultado += subcadenas[rand() % 3] + subcadenas[rand() % 3];
    }
    return resultado;
}

int main(int argc, char* argv[]) {
    // Verificar argumentos
    if (argc != 3) {
        return 1;
    }

    std::string metodo = argv[1];
    int n = std::stoi(argv[2]);
    
    srand(time(0));

    std::string cadena;

    if (metodo == "mejor") {
        cadena = generarMejorCaso(n);
    } else if (metodo == "peor") {
        cadena = generarPeorCaso(n);
    } else if (metodo == "promedio") {
        cadena = generarCasoPromedio(n);
    } else {
        std::cerr << "Metodo no reconocido";
        return 1;
    }

    // Imprimir la cadena en stdout para que pueda ser redirigida
    std::cout << cadena << std::endl;

    return 0;
}
