#include <stdio.h>
#define QUEUESIZE 5

int queue[QUEUESIZE];
int front = 0;
int rear = 0;
int numCurrentElements = 0;

// Verificar si la cola está vacía
int isEmpty() {
    if (numCurrentElements == 0)
        return 1;
    else
        return 0;
}

// Insertar elemento (enqueue)
void enqueue(int val) {
    queue[rear] = val;           
    numCurrentElements++;        
    rear++;                      
    if (rear == QUEUESIZE)       
        rear = 0;
}

// Eliminar elemento (dequeue)
int dequeue() {
    int val;
    val = queue[front];          
    numCurrentElements--;        
    front++;                     
    if (front == QUEUESIZE)      
        front = 0;
    return val;
}

// Mostrar el contenido de la cola
void printQueue() {
    printf("\nQueue:");
    if (rear <= front) {
        for (int i = front; i < QUEUESIZE; i++)
            printf(" %d", queue[i]);
        for (int i = 0; i < rear; i++)
            printf(" %d", queue[i]);
    } else {
        for (int i = front; i < rear; i++)
            printf(" %d", queue[i]);
    }
    printf("\n");
}

int main() {
    int opcion, valor;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Enqueue (insertar)\n");
        printf("2. Dequeue (eliminar)\n");
        printf("3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (numCurrentElements < QUEUESIZE) {
                    printf("Ingresa el valor a insertar: ");
                    scanf("%d", &valor);
                    enqueue(valor);
                } else {
                    printf("La cola esta llena.\n");
                }
                printQueue();
                break;

            case 2:
                if (!isEmpty()) {
                    valor = dequeue();
                    printf("Elemento eliminado: %d\n", valor);
                } else {
                    printf("La cola esta vacia.\n");
                }
                printQueue();
                break;

            case 3:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }

    } while (opcion != 3);

    return 0;
}

