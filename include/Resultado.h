#ifndef RESULTADO_H
#define RESULTADO_H

/**
 * @brief Codigo de estado de una operacion que puede fallar de mas de una forma distinta  
 */
typedef enum {
    EXITO = 0,
    ARCHIVO_NO_ENCONTRADO = -1,
    MEMORIA_INSUFICIENTE = -2,
    NO_ENCONTRADO = -3
} CodigoResultado;

#endif
