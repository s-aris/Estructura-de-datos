#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    //definir un nodo
    struct Elemento {
        int dato;
        struct Elemento* siguiente;
    };
    typedef struct Elemento Nodo;

        // metodos
        Nodo* crearNodo(int dato);
        void insertarAlInicio(Nodo** cabeza, int dato);
        void insertarAlFinal(Nodo** cabeza, int dato);
        void enPosicionEspecifica(Nodo** cabeza, int dato, int pos);
        Nodo* busqueda(Nodo* cabeza, int dato);
        void eliminar(Nodo** cabeza, int entrada);
        bool estaVacia(Nodo* cabeza);
        int tamano(Nodo* cabeza);
        void mostrarLista(Nodo* cabeza);
        void limpiarLista(Nodo** cabeza);
        Nodo* obtenerCabeza(Nodo* cabeza);
        Nodo* obtenerCola(Nodo* cabeza);

        // implementacioon
        
        Nodo* crearNodo(int dato) {
            Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
            nuevo->dato = dato;
            nuevo->siguiente = nuevo; // circular
            return nuevo;
        }
        
        void insertarAlInicio(Nodo** cabeza, int dato) {
            Nodo* nuevo = crearNodo(dato);
            if (*cabeza == NULL) {
                *cabeza = nuevo;
            } else {
                Nodo* temp = *cabeza;
                while (temp->siguiente != *cabeza)
                    temp = temp->siguiente;
        
                temp->siguiente = nuevo;
                nuevo->siguiente = *cabeza;
                *cabeza = nuevo;
            }
        }
        
        void insertarAlFinal(Nodo** cabeza, int dato) {
            Nodo* nuevo = crearNodo(dato);
            if (*cabeza == NULL) {
                *cabeza = nuevo;
            } else {
                Nodo* ultimo = *cabeza;
                while (ultimo->siguiente != *cabeza)
                    ultimo = ultimo->siguiente;
        
                ultimo->siguiente = nuevo;
                nuevo->siguiente = *cabeza;
            }
        }
        
        void enPosicionEspecifica(Nodo** cabeza, int dato, int pos) {
            if (pos < 0) {
                printf("Posición inválida\n");
                return;
            }
        
            if (*cabeza == NULL && pos > 0) {
                printf("Lista vacía, no se puede insertar en esa posición\n");
                return;
            }
        
            if (pos == 0) { // insertar al inicio
                insertarAlInicio(cabeza, dato);
                return;
            }
        
            Nodo* nuevo = crearNodo(dato);
            Nodo* temp = *cabeza;
            int i = 0;
        
            while (i < pos - 1 && temp->siguiente != *cabeza) {
                temp = temp->siguiente;
                i++;
            }
        
            if (i != pos - 1) {
                printf("Posición fuera de rango.\n");
                free(nuevo);
                return;
            }
        
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
        }
        
        Nodo* busqueda(Nodo* cabeza, int dato) {
            if (cabeza == NULL) return NULL;
        
            Nodo* indice = cabeza;
            do {
                if (indice->dato == dato)
                    return indice;
                indice = indice->siguiente;
            } while (indice != cabeza);
        
            return NULL;
        }
        
        void eliminar(Nodo** cabeza, int entrada) {
            if (*cabeza == NULL) return;
        
            Nodo* actual = *cabeza, *anterior = NULL;
            do {
                if (actual->dato == entrada) {
                    if (anterior == NULL) { // eliminar cabeza
                        Nodo* cola = *cabeza;
                        while (cola->siguiente != *cabeza)
                            cola = cola->siguiente;
        
                        if (cola == *cabeza) { // solo un nodo
                            free(*cabeza);
                            *cabeza = NULL;
                        } else {
                            cola->siguiente = (*cabeza)->siguiente;
                            free(*cabeza);
                            *cabeza = cola->siguiente;
                        }
                    } else {
                        anterior->siguiente = actual->siguiente;
                        free(actual);
                    }
                    return;
                }
                anterior = actual;
                actual = actual->siguiente;
            } while (actual != *cabeza);
        }
        
        bool estaVacia(Nodo* cabeza) {
            return (cabeza == NULL);
        }
        
        int tamano(Nodo* cabeza) {
            if (cabeza == NULL) return 0;
        
            int count = 0;
            Nodo* temp = cabeza;
            do {
                count++;
                temp = temp->siguiente;
            } while (temp != cabeza);
        
            return count;
        }
        
        void mostrarLista(Nodo* cabeza) {
            if (cabeza == NULL) {
                printf("Lista vacía\n");
                return;
            }
        
            Nodo* temp = cabeza;
            printf("Lista: ");
            do {
                printf("%d ", temp->dato);
                temp = temp->siguiente;
            } while (temp != cabeza);
            printf("\n");
        }
        
        void limpiarLista(Nodo** cabeza) {
            if (*cabeza == NULL) return;
        
            Nodo* temp = *cabeza;
            Nodo* siguiente;
            do {
                siguiente = temp->siguiente;
                free(temp);
                temp = siguiente;
            } while (temp != *cabeza);
        
            *cabeza = NULL; // lista vacía
        }
        
        Nodo* obtenerCabeza(Nodo* cabeza) {
            return cabeza;
        }
        
        Nodo* obtenerCola(Nodo* cabeza) {
            if (cabeza == NULL) return NULL;
        
            Nodo* temp = cabeza;
            while (temp->siguiente != cabeza)
                temp = temp->siguiente;
            return temp;
        }
        
