#include <iostream>
#include "funciones.hpp"

int main() {
    int opcion;
    
    do {
        mostrarMenuPrincipal();
        std::cin >> opcion;
        
        switch (opcion) {
            case 1:
                menuComprimir();
                break;
            case 2:
                menuDescomprimir();
                break;
            case 3:
                std::cout << "\nGracias por usar el compresor Huffman. Hasta luego" << std::endl;
                break;
            default:
                std::cout << "\nOpcion invalida. Por favor, seleccione 1, 2 o 3." << std::endl;
        }
        
        if (opcion != 3) {
            std::cout << "\nPresione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
        
    } while (opcion != 3);
    
    return 0;
}