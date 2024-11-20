#include <stdio.h>
#include <string.h>
#include "funciones.h"


char nombres[5][20];
int tiempos[5];
int recursos[5];
int cantidades[5];
int cantidadActual = 0;

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

void agregarProducto(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int *cantidadActual){
    if (*cantidadActual >= 5) {
        printf("No se pueden agregar más productos.\n");
        return;
    }
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nombres[*cantidadActual]);
    printf("Ingrese el tiempo de fabricación: ");
    scanf("%d", &tiempos[*cantidadActual]);
    printf("Ingrese la cantidad de recursos requeridos: ");
    scanf("%d", &recursos[*cantidadActual]);
    printf("Ingrese la cantidad demandada: ");
    scanf("%d", &cantidades[*cantidadActual]);

    (*cantidadActual)++;
    printf("Producto agregado correctamente.\n");
}

void editarProducto(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int cantidadActual) {
    if (cantidadActual == 0) {
        printf("No hay productos registrados para editar.\n");
        return;
    }

    char nombreBuscado[20];
    printf("Ingrese el nombre del producto que desea editar: ");
    fflush(stdin);
    fgets(nombreBuscado, 20, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = 0;
    

    for (int i = 0; i < cantidadActual; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("\nProducto encontrado: %s\n", nombres[i]);
            printf("Ingrese el nuevo tiempo de fabricación: ");
            scanf("%d", &tiempos[i]);
            printf("Ingrese la nueva cantidad de recursos requeridos: ");
            scanf("%d", &recursos[i]);
            printf("Ingrese la nueva cantidad demandada: ");
            scanf("%d", &cantidades[i]);
            printf("Producto actualizado correctamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int *cantidadActual) {
    if (*cantidadActual == 0) {
        printf("No hay productos registrados para eliminar.\n");
        return;
    }

    char nombreBuscado[20];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    fflush(stdin);
    fgets(nombreBuscado, 20, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = 0;

    for (int i = 0; i < *cantidadActual; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("Producto encontrado: %s. Eliminando...\n", nombres[i]);

            for (int j = i; j < *cantidadActual - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                tiempos[j] = tiempos[j + 1];
                recursos[j] = recursos[j + 1];
                cantidades[j] = cantidades[j + 1];
            }

            (*cantidadActual)--;  
            printf("Producto eliminado correctamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}


void mostrarProductos(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int cantidadActual) {
    if (cantidadActual == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < cantidadActual; i++) {
        printf("%d. %s | Tiempo: %d | Recursos: %d | Cantidad: %d\n", 
               i + 1, nombres[i], tiempos[i], recursos[i], cantidades[i]);
    }
}

void calcularProduccion(int tiempos[], int recursos[], int cantidades[], int cantidadActual, int tiempoMax, int cant_recursos) {
    int tiempoTotal = 0, recursosTotales = 0;

    for (int i = 0; i < cantidadActual; i++) {
        tiempoTotal += tiempos[i] * cantidades[i];
        recursosTotales += recursos[i] * cantidades[i];
    }

    printf("\nTiempo total requerido: %d\n", tiempoTotal);
    printf("Recursos totales requeridos: %d\n", recursosTotales);

    if (tiempoTotal > tiempoMax) {
        printf("No es posible cumplir con el tiempo disponible.\n");
    } else if (recursosTotales > cant_recursos) {
        printf("No es posible cumplir con los recursos disponibles.\n");
    } else {
        printf("Producción viable con los recursos y tiempos disponibles.\n");
    }
}

