#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <string>
#include <map>
#include <queue>
#include <vector>

// Estructura para el nodo del árbol de Huffman
struct NodoHuffman {
    char caracter;
    int frecuencia;
    NodoHuffman* izquierdo;
    NodoHuffman* derecho;

    // Constructores
    NodoHuffman(char c, int f) : caracter(c), frecuencia(f), izquierdo(nullptr), derecho(nullptr) {}
    NodoHuffman(int f) : caracter('\0'), frecuencia(f), izquierdo(nullptr), derecho(nullptr) {}
};

// Comparador para la cola de prioridad
struct ComparadorNodos {
    bool operator()(NodoHuffman* a, NodoHuffman* b) {
        return a->frecuencia > b->frecuencia;
    }
};

// Funciones del menú
void mostrarMenuPrincipal();
void menuComprimir();
void menuDescomprimir();

// Funciones de Huffman
std::map<char, int> calcularFrecuencias(const std::string& texto);
NodoHuffman* construirArbolHuffman(const std::map<char, int>& frecuencias);
void generarCodigos(NodoHuffman* raiz, const std::string& codigo, std::map<char, std::string>& codigos);
std::string comprimirTexto(const std::string& texto, const std::map<char, std::string>& codigos);
std::string descomprimirTexto(const std::string& textComprimido, NodoHuffman* raiz);

// Funciones de archivo
bool leerArchivo(const std::string& rutaArchivo, std::string& contenido);
bool escribirArchivoHUB(const std::string& rutaArchivo, const std::string& textoComprimido, 
                        const std::map<char, int>& frecuencias);
bool leerArchivoHUB(const std::string& rutaArchivo, std::string& textoComprimido, 
                    std::map<char, int>& frecuencias);
bool escribirArchivoTXT(const std::string& rutaArchivo, const std::string& contenido);

#endif 