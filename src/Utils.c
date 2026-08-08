#include "Utils.h"

Bool finDeLinea(char caracter) {
    return (caracter == '\0' || caracter == '\n' || caracter == '\r') ? TRUE : FALSE;
}

void copiarTexto(char* destino, const char* origen) {
    int indice = 0;

    while (!finDeLinea(origen[indice])) {
        destino[indice] = origen[indice];
        indice++;
    }
    destino[indice] = '\0';
}

Bool sonIguales(const char* texto1, const char* texto2) {
    int indice = 0;

    while (!finDeLinea(texto1[indice]) && !finDeLinea(texto2[indice])) {
        if (texto1[indice] != texto2[indice]) {
            return FALSE;
        }
        indice++;
    }

    return texto1[indice] == texto2[indice] ? TRUE : FALSE;
}

int contarCaracteres(const char* cadena) {
    int longitud = 0;

    while (!finDeLinea(cadena[longitud])) {
        longitud++;
    }

    return longitud;
}

void agregarTextoAlFinal(char* destino, const char* origen) {
    int indiceDestino = contarCaracteres(destino);
    int indiceOrigen = 0;

    while (!finDeLinea(origen[indiceOrigen])) {
        destino[indiceDestino] = origen[indiceOrigen];
        indiceDestino++;
        indiceOrigen++;
    }
    destino[indiceDestino] = '\0';
}

/**
 * @brief Escribe los digitos decimales de un numero no negativo en destino, en orden invertido
 * @param valorAbsoluto Valor no negativo a convertir
 * @param destino Cadena de salida, debe tener espacio suficiente
 * @return Cantidad de digitos escritos
 *
 * Uso interno de `convertirIntACadena()`. Al escribir en orden invertido evita tener que calcular la cantidad de digitos por adelantado.
 * Complejidad: O(cantidad de digitos de valorAbsoluto)
 */
static int escribirDigitosInvertidos(int valorAbsoluto, char* destino) {
    int cantidadDigitos = 0;

    if (valorAbsoluto == 0) {
        destino[cantidadDigitos] = '0';
        return cantidadDigitos + 1;
    }

    while (valorAbsoluto > 0) {
        destino[cantidadDigitos] = (char)('0' + (valorAbsoluto % 10));
        valorAbsoluto /= 10;
        cantidadDigitos++;
    }

    return cantidadDigitos;
}

/**
 * @brief Invierte los primeros `cantidad` caracteres de cadena
 * @param cadena Cadena a invertir
 * @param cantidad Cantidad de caracteres a invertir desde el inicio de cadena
 * @return void
 *
 * Uso interno de convertirIntACadena(), para corregir el orden dejado por `escribirDigitosInvertidos()`
 * Complejidad: O(cantidad)
 */
static void invertirCaracteres(char* cadena, int cantidad) {
    int inicio = 0;
    int fin = cantidad - 1;

    while (inicio < fin) {
        char temporal = cadena[inicio];
        cadena[inicio] = cadena[fin];
        cadena[fin] = temporal;
        inicio++;
        fin--;
    }
}

void convertirIntACadena(int valor, char* destino) {
    int indiceDestino = 0;
    int cantidadDigitos;
    int valorAbsoluto;

    if (valor < 0) {
        destino[indiceDestino] = '-';
        indiceDestino++;
    }

    valorAbsoluto = valor < 0 ? -valor : valor;
    cantidadDigitos = escribirDigitosInvertidos(valorAbsoluto, destino + indiceDestino);
    invertirCaracteres(destino + indiceDestino, cantidadDigitos);
    destino[indiceDestino + cantidadDigitos] = '\0';
}

void convertirFloatACadena(float valor, int decimales, char* destino) {
    int indiceDestino = 0;
    int parteEntera;
    float parteDecimal;
    float factorDecimal = 1.0f;
    int indiceDecimal;

    if (valor < 0) {
        destino[indiceDestino] = '-';
        indiceDestino++;
        valor = -valor;
    }

    parteEntera = (int)valor;
    parteDecimal = valor - (float)parteEntera;

    convertirIntACadena(parteEntera, destino + indiceDestino);
    indiceDestino += contarCaracteres(destino + indiceDestino);

    if (decimales <= 0) {
        return;
    }

    destino[indiceDestino] = '.';
    indiceDestino++;

    for (indiceDecimal = 0; indiceDecimal < decimales; indiceDecimal++) {
        factorDecimal *= 10.0f;
    }

    parteDecimal = parteDecimal * factorDecimal + 0.5f;
    convertirIntACadena((int)parteDecimal, destino + indiceDestino);
}
