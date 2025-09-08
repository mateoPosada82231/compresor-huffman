#include "funciones.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>

void mostrarMenuPrincipal() {
    std::cout << "\n=== COMPRESOR HUFFMAN ===" << std::endl;
    std::cout << "Escoja una opcion:" << std::endl;
    std::cout << "1- Comprimir" << std::endl;
    std::cout << "2- Descomprimir" << std::endl;
    std::cout << "3- Salir" << std::endl;
    std::cout << "Opcion: ";
}

void menuComprimir() {
    std::cout << "\n=== COMPRIMIR ARCHIVO ===" << std::endl;
    std::string rutaArchivo;
    std::cout << "Ingrese la ruta del archivo a comprimir: ";
    std::cin.ignore();
    std::getline(std::cin, rutaArchivo);
    
    // Leer el archivo
    std::string contenido;
    if (!leerArchivo(rutaArchivo, contenido)) {
        std::cout << "Error: No se pudo leer el archivo." << std::endl;
        return;
    }
    
    if (contenido.empty()) {
        std::cout << "Error: El archivo esta vacio." << std::endl;
        return;
    }
    
    // Calcular frecuencias
    std::map<char, int> frecuencias = calcularFrecuencias(contenido);
    
    // Construir árbol de Huffman
    NodoHuffman* raiz = construirArbolHuffman(frecuencias);
    
    // Generar códigos
    std::map<char, std::string> codigos;
    if (frecuencias.size() == 1) {
        // Caso especial: solo un carácter único
        codigos[frecuencias.begin()->first] = "0";
    } else {
        generarCodigos(raiz, "", codigos);
    }
    
    // Comprimir texto
    std::string textoComprimido = comprimirTexto(contenido, codigos);
    
    // Crear nombre del archivo comprimido
    std::string rutaComprimida = rutaArchivo.substr(0, rutaArchivo.find_last_of('.')) + ".HUB";
    
    // Escribir archivo comprimido
    if (escribirArchivoHUB(rutaComprimida, textoComprimido, frecuencias)) {
        // Mostrar estadísticas
        std::ifstream original(rutaArchivo, std::ios::binary | std::ios::ate);
        std::ifstream comprimido(rutaComprimida, std::ios::binary | std::ios::ate);
        
        if (original.is_open() && comprimido.is_open()) {
            long tamanoOriginal = original.tellg();
            long tamanoComprimido = comprimido.tellg();
            
            std::cout << "\nCOMPRESION EXITOSA!" << std::endl;
            std::cout << "Archivo original: " << tamanoOriginal << " bytes" << std::endl;
            std::cout << "Archivo comprimido: " << tamanoComprimido << " bytes" << std::endl;
            std::cout << "Reduccion: " << ((double)(tamanoOriginal - tamanoComprimido) / tamanoOriginal * 100) << "%" << std::endl;
            std::cout << "Archivo guardado como: " << rutaComprimida << std::endl;
        }
        
        original.close();
        comprimido.close();
    } else {
        std::cout << "Error: No se pudo escribir el archivo comprimido." << std::endl;
    }
}

void menuDescomprimir() {
    std::cout << "\n=== DESCOMPRIMIR ARCHIVO ===" << std::endl;
    std::string rutaArchivo;
    std::cout << "Ingrese la ruta del archivo .HUB a descomprimir: ";
    std::cin.ignore();
    std::getline(std::cin, rutaArchivo);
    
    // Leer archivo comprimido
    std::string textoComprimido;
    std::map<char, int> frecuencias;
    
    if (!leerArchivoHUB(rutaArchivo, textoComprimido, frecuencias)) {
        std::cout << "Error: No se pudo leer el archivo .HUB" << std::endl;
        return;
    }
    
    // Reconstruir árbol de Huffman
    NodoHuffman* raiz = construirArbolHuffman(frecuencias);
    
    // Descomprimir
    std::string textoDescomprimido = descomprimirTexto(textoComprimido, raiz);
    
    // Crear nombre del archivo descomprimido
    std::string rutaDescomprimida = rutaArchivo.substr(0, rutaArchivo.find_last_of('.')) + "_descomprimido.txt";
    
    // Escribir archivo descomprimido
    if (escribirArchivoTXT(rutaDescomprimida, textoDescomprimido)) {
        std::cout << "\nDESCOMPRESION EXITOSA!" << std::endl;
        std::cout << "Archivo descomprimido guardado como: " << rutaDescomprimida << std::endl;
    } else {
        std::cout << "Error: No se pudo escribir el archivo descomprimido." << std::endl;
    }
}

std::map<char, int> calcularFrecuencias(const std::string& texto) {
    std::map<char, int> frecuencias;
    for (char c : texto) {
        frecuencias[c]++;
    }
    return frecuencias;
}

NodoHuffman* construirArbolHuffman(const std::map<char, int>& frecuencias) {
    std::priority_queue<NodoHuffman*, std::vector<NodoHuffman*>, ComparadorNodos> cola;
    
    // Crear nodos hoja
    for (const auto& par : frecuencias) {
        cola.push(new NodoHuffman(par.first, par.second));
    }
    
    // Construir árbol
    while (cola.size() > 1) {
        NodoHuffman* derecho = cola.top(); cola.pop();
        NodoHuffman* izquierdo = cola.top(); cola.pop();
        
        NodoHuffman* padre = new NodoHuffman(izquierdo->frecuencia + derecho->frecuencia);
        padre->izquierdo = izquierdo;
        padre->derecho = derecho;
        
        cola.push(padre);
    }
    
    return cola.top();
}

void generarCodigos(NodoHuffman* raiz, const std::string& codigo, std::map<char, std::string>& codigos) {
    if (!raiz) return;
    
    // Si es una hoja
    if (!raiz->izquierdo && !raiz->derecho) {
        codigos[raiz->caracter] = codigo.empty() ? "0" : codigo;
        return;
    }
    
    generarCodigos(raiz->izquierdo, codigo + "0", codigos);
    generarCodigos(raiz->derecho, codigo + "1", codigos);
}

std::string comprimirTexto(const std::string& texto, const std::map<char, std::string>& codigos) {
    std::string resultado;
    for (char c : texto) {
        resultado += codigos.at(c);
    }
    return resultado;
}

std::string descomprimirTexto(const std::string& textComprimido, NodoHuffman* raiz) {
    std::string resultado;
    NodoHuffman* actual = raiz;
    
    for (char bit : textComprimido) {
        if (bit == '0') {
            actual = actual->izquierdo;
        } else {
            actual = actual->derecho;
        }
        
        // Si llegamos a una hoja
        if (!actual->izquierdo && !actual->derecho) {
            resultado += actual->caracter;
            actual = raiz;
        }
    }
    
    return resultado;
}

bool leerArchivo(const std::string& rutaArchivo, std::string& contenido) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        return false;
    }
    
    std::stringstream buffer;
    buffer << archivo.rdbuf();
    contenido = buffer.str();
    archivo.close();
    return true;
}

bool escribirArchivoHUB(const std::string& rutaArchivo, const std::string& textoComprimido, 
                        const std::map<char, int>& frecuencias) {
    std::ofstream archivo(rutaArchivo, std::ios::binary);
    if (!archivo.is_open()) {
        return false;
    }
    
    // Escribir número de caracteres únicos
    int numCaracteres = frecuencias.size();
    archivo.write(reinterpret_cast<const char*>(&numCaracteres), sizeof(numCaracteres));
    
    // Escribir tabla de frecuencias
    for (const auto& par : frecuencias) {
        archivo.write(&par.first, sizeof(char));
        archivo.write(reinterpret_cast<const char*>(&par.second), sizeof(int));
    }
    
    // Convertir string binario a bytes
    std::string bytesComprimidos;
    for (size_t i = 0; i < textoComprimido.length(); i += 8) {
        std::string byte = textoComprimido.substr(i, 8);
        // Rellenar con ceros si es necesario
        while (byte.length() < 8) {
            byte += "0";
        }
        bytesComprimidos += static_cast<char>(std::bitset<8>(byte).to_ulong());
    }
    
    // Escribir longitud del texto comprimido en bits
    int longitudBits = textoComprimido.length();
    archivo.write(reinterpret_cast<const char*>(&longitudBits), sizeof(longitudBits));
    
    // Escribir datos comprimidos
    archivo.write(bytesComprimidos.c_str(), bytesComprimidos.length());
    
    archivo.close();
    return true;
}

bool leerArchivoHUB(const std::string& rutaArchivo, std::string& textoComprimido, 
                    std::map<char, int>& frecuencias) {
    std::ifstream archivo(rutaArchivo, std::ios::binary);
    if (!archivo.is_open()) {
        return false;
    }
    
    // Leer número de caracteres únicos
    int numCaracteres;
    archivo.read(reinterpret_cast<char*>(&numCaracteres), sizeof(numCaracteres));
    
    // Leer tabla de frecuencias
    frecuencias.clear();
    for (int i = 0; i < numCaracteres; i++) {
        char caracter;
        int frecuencia;
        archivo.read(&caracter, sizeof(char));
        archivo.read(reinterpret_cast<char*>(&frecuencia), sizeof(int));
        frecuencias[caracter] = frecuencia;
    }
    
    // Leer longitud en bits
    int longitudBits;
    archivo.read(reinterpret_cast<char*>(&longitudBits), sizeof(longitudBits));
    
    // Leer datos comprimidos
    std::string bytesComprimidos;
    char byte;
    while (archivo.read(&byte, 1)) {
        bytesComprimidos += byte;
    }
    
    // Convertir bytes a string binario
    textoComprimido = "";
    for (char b : bytesComprimidos) {
        std::bitset<8> bits(static_cast<unsigned char>(b));
        textoComprimido += bits.to_string();
    }
    
    // Recortar al tamaño original
    textoComprimido = textoComprimido.substr(0, longitudBits);
    
    archivo.close();
    return true;
}

bool escribirArchivoTXT(const std::string& rutaArchivo, const std::string& contenido) {
    std::ofstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        return false;
    }
    
    archivo << contenido;
    archivo.close();
    return true;
}
