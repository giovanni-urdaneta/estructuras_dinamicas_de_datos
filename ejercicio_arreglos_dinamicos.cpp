// Giovanni Urdaneta
// CI: 28288477

/*  problema libre --> crear un programa que pida un array de 10 
    numeros enteros e imprima la cantidad de numeros impares que contiene*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int * crear_array_dinamico(int [], int);
int * rellenar_array(int [], int);
int numeros_impares(int array[], int tamanio);

int main(){
    int *numeros;

    numeros = crear_array_dinamico(numeros, 10); // reservando memoria
    numeros = rellenar_array(numeros, 10);
    
    printf("\nnumeros impares en el array: %d\n", numeros_impares(numeros, 10));

    free(numeros); // liberando memoria
    
    return 0;
}

int * crear_array_dinamico(int array[], int tamanio){
    array = (int *)malloc(tamanio*sizeof(int));
    return array;
}

int * rellenar_array(int array[], int tamanio){
    printf("\ningrese los valores que conformaran el array: ");
    for(int i=0; i<tamanio; i++){
        printf("\n[%d]: ", i+1);
        scanf("%d", &array[i]);
    }
    return array;
}

int numeros_impares(int array[], int tamanio){
    int impares = 0;
    for(int i=0; i<tamanio; i++){
        if(array[i] != 0 && array[i] % 2 != 0){
            impares++;
        }
    }
    return impares; 
}