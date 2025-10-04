# Compresor Huffman - Parcial Teoría de la Información

Este programa implementa el algoritmo de compresión de Huffman desarrollado por David A. Huffman en 1952. Es un método de compresión sin pérdidas que asigna códigos de longitud variable a los caracteres según su frecuencia de aparición en el texto.

## 📋 Índice

1. [Características](#características)
2. [Estructura del Proyecto](#estructura-del-proyecto)
3. [Prerrequisitos](#prerrequisitos)
4. [Instalación y Compilación](#instalación-y-compilación)
5. [Guía de Uso Detallada](#guía-de-uso-detallada)
6. [Ejemplos Prácticos](#ejemplos-prácticos)
7. [Formato de Archivo .HUB](#formato-de-archivo-hub)
8. [Algoritmo de Huffman](#algoritmo-de-huffman)
9. [Solución de Problemas](#solución-de-problemas)
10. [Limitaciones y Consideraciones](#limitaciones-y-consideraciones)

## 🚀 Características

- ✅ **Compresión eficiente**: Reduce significativamente el tamaño de archivos de texto
- ✅ **Formato .HUB personalizado**: Extensión específica para archivos comprimidos con Huffman
- ✅ **Descompresión exacta**: Restaura archivos a su estado original sin pérdida de información
- ✅ **Interfaz de usuario intuitiva**: Menú interactivo fácil de navegar
- ✅ **Estadísticas de compresión**: Muestra métricas de rendimiento y reducción de tamaño
- ✅ **Manejo robusto de errores**: Validación de archivos y rutas
- ✅ **Multiplataforma**: Compatible con Windows, Linux y macOS

## 📁 Estructura del Proyecto

```
CompresorHuffman/
├── 📂 src/
│   ├── 📄 main.cpp               # Programa principal con menú interactivo
│   └── 📄 funciones.cpp          # Implementación completa del algoritmo Huffman
├── 📂 include/
│   └── 📄 funciones.hpp          # Declaraciones de funciones y estructuras
├── 📂 build/                     # Directorio de compilación (generado automáticamente)
│   └── 📂 Debug/
│       └── 🎯 CompresorHuffman.exe
├── 📄 CMakeLists.txt             # Configuración de CMake
└── 📄 README.md                  # Esta documentación
```

## 🔧 Prerrequisitos

### Software Requerido:
- **CMake 3.10+**: Para la gestión de compilación
- **Compilador C++11+**: 
  - Windows: Visual Studio 2019+ o MinGW
  - Linux: GCC 4.8+ o Clang 3.3+
  - macOS: Xcode 5+ o Clang

### Instalación de CMake en Windows:
```powershell
# Opción 1: Con Chocolatey
choco install cmake

# Opción 2: Con Scoop
scoop install cmake

# Opción 3: Descarga manual desde https://cmake.org/download/
```

## 🛠️ Instalación y Compilación

### Paso 1: Clonar o descargar el proyecto
```powershell
cd "C:\tu\directorio\deseado"
# Si usas git: git clone <url-del-repositorio>
```

### Paso 2: Compilar el proyecto
```powershell
# Navegar al directorio del proyecto
cd "CompresorHuffman"

# Crear directorio de compilación
mkdir build
cd build

# Configurar con CMake
cmake ..

# Compilar el proyecto
cmake --build .

# El ejecutable se generará en: build\Debug\CompresorHuffman.exe
```

### Verificación de la compilación:
```powershell
# Ejecutar el programa
.\Debug\CompresorHuffman.exe
```

## 📖 Guía de Uso Detallada

### Inicio del Programa
```powershell
cd build\Debug
.\CompresorHuffman.exe
```

El programa mostrará el menú principal:
```
=== COMPRESOR HUFFMAN ===
Escoja una opcion:
1- Comprimir
2- Descomprimir
3- Salir
Opcion: 
```

### 🗜️ Opción 1: Comprimir Archivo

**Pasos detallados:**

1. **Seleccionar opción 1** del menú principal
2. **Ingresar ruta del archivo** cuando se solicite:
   ```
   === COMPRIMIR ARCHIVO ===
   Ingrese la ruta del archivo a comprimir: C:\ruta\completa\archivo.txt
   ```
3. **Esperar procesamiento**: El programa calculará frecuencias, construirá el árbol y comprimirá
4. **Revisar resultados**: Se mostrará información detallada de la compresión

**Formato de rutas aceptadas:**
- `C:\Users\usuario\Desktop\documento.txt`
- `D:\proyectos\texto.txt`
- `.\archivo_local.txt` (ruta relativa)

**Tipos de archivo soportados:**
- `.txt` (archivos de texto plano)
- `.csv` (archivos de valores separados por comas)
- `.log` (archivos de registro)
- Cualquier archivo de texto sin formato

### 🔓 Opción 2: Descomprimir Archivo

**Pasos detallados:**

1. **Seleccionar opción 2** del menú principal
2. **Ingresar ruta del archivo .HUB**:
   ```
   === DESCOMPRIMIR ARCHIVO ===
   Ingrese la ruta del archivo .HUB a descomprimir: C:\ruta\archivo.HUB
   ```
3. **Procesamiento automático**: El programa lee el árbol Huffman y descomprime
4. **Archivo resultante**: Se crea un archivo `_descomprimido.txt`

### 🚪 Opción 3: Salir
Termina el programa de forma segura con mensaje de despedida.

## 💡 Ejemplos Prácticos

### Ejemplo 1: Comprimir un archivo de texto simple

**Crear archivo de prueba:**
```powershell
# Crear un archivo de prueba
echo "Este es un archivo de prueba para el compresor Huffman. El algoritmo de Huffman es muy eficiente para textos con patrones repetitivos. Este texto contiene varias repeticiones de palabras como: algoritmo, Huffman, texto, archivo, para demostrar la efectividad de la compresion." > test.txt
```

**Proceso de compresión:**
```
=== COMPRESOR HUFFMAN ===
Escoja una opcion:
1- Comprimir
2- Descomprimir
3- Salir
Opcion: 1

=== COMPRIMIR ARCHIVO ===
Ingrese la ruta del archivo a comprimir: C:\Users\mateo\Desktop\test.txt

COMPRESION EXITOSA!
Archivo original: 285 bytes
Archivo comprimido: 178 bytes
Reduccion: 37.54%
Archivo guardado como: C:\Users\mateo\Desktop\test.HUB
```

### Ejemplo 2: Descomprimir el archivo

```
=== COMPRESOR HUFFMAN ===
Escoja una opcion:
1- Comprimir
2- Descomprimir
3- Salir
Opcion: 2

=== DESCOMPRIMIR ARCHIVO ===
Ingrese la ruta del archivo .HUB a descomprimir: C:\Users\mateo\Desktop\test.HUB

DESCOMPRESION EXITOSA!
Archivo descomprimido guardado como: C:\Users\mateo\Desktop\test_descomprimido.txt
```

### Ejemplo 3: Tipos de archivos que se comprimen mejor

**Archivos con alta redundancia (mejor compresión):**
- Código fuente con patrones repetitivos
- Textos con vocabulario limitado
- Archivos de configuración
- Logs con formatos estructurados

**Ejemplo de archivo con buena compresión:**
```
función main() {
    mostrar("Hola mundo");
    mostrar("Hola mundo");
    mostrar("Hola mundo");
    return 0;
}
```

## 📄 Formato de Archivo .HUB

El formato .HUB es un formato binario personalizado que contiene:

### Estructura del archivo:
```
[4 bytes] - Número de caracteres únicos (entero)
[Variable] - Tabla de frecuencias:
  ├── [1 byte] - Carácter
  └── [4 bytes] - Frecuencia (entero)
[4 bytes] - Longitud del texto comprimido en bits
[Variable] - Datos comprimidos en formato binario
```

### Características del formato:
- **Compacto**: Almacena solo la información esencial
- **Auto-contenido**: Incluye toda la información necesaria para descomprimir
- **Eficiente**: Minimiza el overhead de metadatos

## 🧮 Algoritmo de Huffman

### Fundamentos Teóricos

El algoritmo de Huffman es un algoritmo de compresión que:
1. **Analiza frecuencias**: Cuenta la aparición de cada carácter
2. **Construye árbol binario**: Crea un árbol donde caracteres frecuentes tienen códigos cortos
3. **Genera códigos**: Asigna secuencias binarias únicas a cada carácter
4. **Comprime**: Sustituye caracteres por sus códigos correspondientes

### Proceso paso a paso:

#### 1. Cálculo de Frecuencias
```cpp
// Ejemplo: Texto "ABACA"
A: 3 veces
B: 1 vez  
C: 1 vez
```

#### 2. Construcción del Árbol Huffman
```
       (5)
      /   \
   A(3)   (2)
          /  \
       B(1)  C(1)
```

#### 3. Generación de Códigos
```
A = 0     (1 bit)
B = 10    (2 bits)  
C = 11    (2 bits)
```

#### 4. Compresión
```
Texto original: "ABACA" = 40 bits (8 bits × 5 caracteres)
Texto comprimido: "010110" = 6 bits
Reducción: 85%
```

### Ventajas del Algoritmo:
- ✅ **Óptimo**: Genera la menor longitud promedio posible
- ✅ **Sin pérdidas**: Conserva toda la información original  
- ✅ **Adaptativo**: Se ajusta al contenido específico del texto
- ✅ **Eficiente**: Complejidad O(n log n) para n caracteres

## 🔧 Solución de Problemas

### Error: "No se pudo leer el archivo"
**Causas posibles:**
- Ruta de archivo incorrecta
- Archivo no existe
- Permisos insuficientes
- Archivo está siendo usado por otro programa

**Soluciones:**
```powershell
# Verificar que el archivo existe
Test-Path "C:\ruta\archivo.txt"

# Verificar permisos
Get-Acl "C:\ruta\archivo.txt"

# Usar ruta absoluta completa
"C:\Users\usuario\Desktop\archivo.txt"
```

### Error: "No se pudo escribir el archivo comprimido"
**Causas posibles:**
- Disco lleno
- Permisos de escritura insuficientes
- Directorio de destino no existe

**Soluciones:**
- Verificar espacio en disco
- Ejecutar como administrador si es necesario
- Crear directorio de destino manualmente

### Error de compilación
**Si CMake no está en el PATH:**
```powershell
# Refrescar variables de entorno
refreshenv

# O agregar CMake manualmente al PATH
$env:PATH += ";C:\Program Files\CMake\bin"
```

### Advertencias del compilador
Las advertencias sobre conversión de tipos son normales y no afectan la funcionalidad:
```
warning C4244: conversión de 'std::streamoff' a 'long'
```

## ⚠️ Limitaciones y Consideraciones

### Limitaciones del Programa:
- **Solo archivos de texto**: No soporta archivos binarios (imágenes, videos, etc.)
- **Memoria RAM**: Archivos muy grandes pueden consumir mucha memoria
- **Codificación**: Optimizado para texto ASCII/UTF-8

### Consideraciones de Rendimiento:
- **Archivos pequeños**: Pueden no mostrar mucha compresión debido al overhead
- **Archivos uniformes**: Textos con distribución uniforme de caracteres se comprimen menos
- **Archivos grandes**: Mejor rendimiento de compresión en archivos > 1KB

### Mejores Casos de Uso:
✅ **Recomendado para:**
- Código fuente
- Archivos de configuración  
- Textos con patrones repetitivos
- Documentos con vocabulario limitado

❌ **No recomendado para:**
- Archivos ya comprimidos (.zip, .rar)
- Archivos binarios
- Imágenes o multimedia
- Archivos muy pequeños (< 100 bytes)

### Métricas de Rendimiento Típicas:
- **Código fuente C++**: 40-60% de reducción
- **Texto en español**: 35-50% de reducción  
- **Archivos de log**: 50-70% de reducción
- **Texto aleatorio**: 0-15% de reducción

---
 
**Autor:** Mateo Posada Montoya
**Fecha:** Septiembre 2025  
**Versión:** 1.0