#include "mundo.h"

#define ATTR_SET(flags, attr)   (flags) |= (1 << (attr))
#define ATTR_IS_SET(flags, attr)   ((flags) & (1 << (attr)))

// Estructura del mundo
struct mundo {
    int *tablero;           // Tablero/Mapa del mundo
    int numCelVivas;        // Número de células vivas
    int numCelMuertas;      // Número de células muertas

    int flags;              // Comprueba atributos
};

// Enumerado para tratar el flag
enum mundo_attr {
    TABLERO,
    CELMUERTAS,
    CELVIVAS
};

/* Constructor/Destructor */
// Reserva el mundo
struct mundo *mundo_alloc(){
    struct mundo *m;

    // Reserva memoria para el objeto mundo e inicializa su flag
    m = (struct mundo *) malloc(sizeof(struct mundo));
    m->flags = 0;

    return m;
}

// Libera el mundo
void mundo_free(struct mundo *m) {
    free(m);                // Libera la reserva del objeto
}

// Reserva el tablero
int mundo_alloc_tablero(struct mundo *m, int tam){
    m->tablero = (int*) calloc(tam*tam,sizeof(int));

    if(m->tablero == NULL)
        return -1;

    ATTR_SET(m->flags, TABLERO);

    return 0;
}

// Libera el tablero
void mundo_free_tablero(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, TABLERO))
        free(m->tablero);   // Si se ha reservado memoria para el tablero, la libera
}

/* Métodos */
    /* Setters */
// Establece el número de células vivas
int mundo_set_vivas(struct mundo *m, int num) {
    if (num < 0)
        return -1;

    // Guarda el valor y lo registra en el flag
    m->numCelVivas = num;
    ATTR_SET(m->flags, CELVIVAS);

    return 0;
}

// Establece el número de células muertas
int mundo_set_muertas(struct mundo *m, int num) {
    if (num < 0)
        return -1;

    // Guarda el valor y lo registra en el flag
    m->numCelMuertas = num;
    ATTR_SET(m->flags, CELMUERTAS);

    return 0;
}

    /* Getters */
// Obtiene el tablero
int *mundo_get_tablero(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, TABLERO))
        return m->tablero;
    else
        return NULL;
}

// Devuelve el número de células vivas
int mundo_get_vivas(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, CELVIVAS))
        return m->numCelVivas;
    else
        return -1;
}

// Devuelve el número de células muertas
int mundo_get_muertas(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, CELMUERTAS))
        return m->numCelMuertas;
    else
        return -1;
}

    /* Métodos extra */
/* Actualiza el mundo para la siguiente iteracción. Copia la memoria del
mundo futuro anterior, que será el actual en la siguiente */
struct mundo *mundo_clone(struct mundo *actual, struct mundo *futuro) {
    memcpy(actual, futuro, sizeof(struct mundo));

    return actual;
}