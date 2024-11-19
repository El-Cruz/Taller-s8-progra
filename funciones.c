#include <stdio.h>
#include "funciones.h"


void line(){
    printf("\n-----------------------------------------------------------------------------\n");
}
void menu(){
    printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular producción\n");
        printf("5. Mostrar productos\n");
        printf("6. Salir\n");
        printf("Elija una opción: ");
}

void agregar();
