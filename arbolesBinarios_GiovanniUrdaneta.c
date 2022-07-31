#include<stdio.h>
#include<stdlib.h>

typedef struct nodo 
{
    struct nodo *padre;
    struct nodo *izquierda;
    struct nodo *derecha;
    int valor;
} nodo; 

// prototipos de funciones
nodo *crearNodo(nodo *padre, int valor);
void agregarValor(nodo *arbol, int valor);

int main()
{
    nodo *arbol;
    arbol = crearNodo(NULL, 40); // se asigna como nodo padre NULL porque se trata 
    // del inicio del arbol

    // se recorre el arbol y se agregan los valores
    agregarValor(arbol, 10); // 10 a la izquierda de 40 
    agregarValor(arbol, 50); // 50 a la derecha de 40
    agregarValor(arbol, 30); // 30 a la izquierda de 40
    agregarValor(arbol, 1); 
    agregarValor(arbol, 100);
    return 0;
}

// estructura de funciones
nodo *crearNodo(nodo *padre, int valor)
{
    nodo *n = calloc(sizeof(nodo), 1);
    n->padre = padre;
    n->valor = valor;
    return n;
}

// el funcionamiento del arbol de numeros enteros consiste en que 
// los menores van ubicados en la izquierda y los mayores a la derecha
void agregarValor(nodo *arbol, int valor)
{
    nodo *temp, *pivote;
    int derecha = 0;

    if(arbol) // si el arbol esta inicializado
    {
        temp = arbol;
        
        while(temp!=NULL) // el ciclo va a recorrer el arbol hasta que encuentre
                           // un nodo hoja  
        {
            pivote = temp;

            if(valor > temp->valor)
            {
                temp = temp->derecha;
                derecha = 1;
            }
            else
            {
                temp = temp->izquierda;
                derecha = 0;
            }
        }

        temp = crearNodo(pivote, valor);
        
        if(derecha == 1)
        {
            printf("%d a la derecha de %d\n", valor, pivote->valor);
            pivote->derecha = temp; // permitimos que el arbol recorra sus elementos
        }                           // y se creen subarboles
        else if (derecha == 0)
        {
            printf("%d a la izquierda de %d\n", valor, pivote->valor);
            pivote->izquierda = temp; // permitimos que el arbol recorra sus elementos
        }                             // y se creen subarboles
    }
    else // si el arbol no esta inicializado
    {
        printf("Error");
    }
}