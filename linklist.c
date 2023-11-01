#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo de la lista enlazada
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Función para agregar un nodo al final de la lista
void agregarNodo(struct Nodo** cabeza, int valor) {
    // Crear un nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
        *cabeza = nuevoNodo;
    } else {
        // Si la lista no está vacía, se recorre hasta el final y se agrega el nodo allí
        struct Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Función para eliminar un nodo por valor
void eliminarNodo(struct Nodo** cabeza, int valor) {
    if (*cabeza == NULL) {
        // Si la lista está vacía, no se hace nada
        return;
    }

    if ((*cabeza)->dato == valor) {
        // Si el valor a eliminar está en la cabeza, se elimina la cabeza
        struct Nodo* temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(temp);
        return;
    }

    // Si el valor a eliminar no está en la cabeza, se busca en la lista
    struct Nodo* actual = *cabeza;
    while (actual->siguiente != NULL && actual->siguiente->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual->siguiente != NULL) {
        // Si se encuentra el valor, se elimina el nodo
        struct Nodo* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        free(temp);
    }
}

// Función para agregar un nodo al inicio de la lista
void agregarNodoInicio(struct Nodo** cabeza, int valor) {
    // Crear un nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *cabeza;

    // El nuevo nodo se convierte en la nueva cabeza
    *cabeza = nuevoNodo;
}

// Función para buscar un nodo por valor e imprimir si existe o no
void buscarNodo(struct Nodo* cabeza, int valor) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        if (actual->dato == valor) {
            printf("El valor %d existe en la lista.\n", valor);
            return;
        }
        actual = actual->siguiente;
    }
    printf("El valor %d no existe en la lista.\n", valor);
}

// Función para imprimir la lista
void imprimirLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Función para obtener el elemento enésimo e imprimirlo
void obtenerElementoNesimo(struct Nodo* cabeza, int indice) {
    struct Nodo* actual = cabeza;
    int contador = 0;

    while (actual != NULL && contador < indice) {
        actual = actual->siguiente;
        contador++;
    }

    if (actual != NULL) {
        printf("Elemento en el índice %d: %d\n", indice, actual->dato);
    } else {
        printf("No existe un elemento en el índice %d.\n", indice);
    }
}

// Función para liberar la memoria de la lista
void liberarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        struct Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

int main() {
    struct Nodo* cabeza = NULL;

    // Agregar nodos
    agregarNodo(&cabeza, 10);
    agregarNodo(&cabeza, 20);
    agregarNodo(&cabeza, 30);

    // Imprimir la lista
    printf("Lista original: ");
    imprimirLista(cabeza);

    // Agregar un nodo al inicio
    agregarNodoInicio(&cabeza, 5);
    printf("Lista después de agregar un nodo al inicio: ");
    imprimirLista(cabeza);

    // Buscar un nodo por valor
    buscarNodo(cabeza, 20);

    // Eliminar un nodo por valor
    eliminarNodo(&cabeza, 20);
    printf("Lista después de eliminar un nodo por valor: ");
    imprimirLista(cabeza);

    // Obtener el elemento enésimo
    obtenerElementoNesimo(cabeza, 2);

    // Liberar la memoria de la lista
    liberarLista(cabeza);

    return 0;
}
