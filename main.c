#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {


    int opc, cant_recursos, tiempo_max = 160;
    char nombres[5][20];
    int tiempos[5];
    int recursos[5];
    int cantidades[5];
    int t_entrega[5];
    int cantidadActual = 0;

    line();
    printf("\n\tOptimizator\n");
    printf("\nPara poder comenzar primero ");
    printf("\nIngrese la cantidad de recursos de la empresa: ");
    scanf("%d", &cant_recursos);
    line();
    do{
        menu();
        scanf("%d", &opc);
        line();

        switch (opc){
        case 1:
            agregarProducto(nombres, tiempos, recursos, cantidades, &cantidadActual);
            break;
        case 2:
            editarProducto(nombres, tiempos, recursos, cantidades, cantidadActual);
            break;
        case 3:
            eliminarProducto(nombres, tiempos, recursos, cantidades, &cantidadActual);
            break;
        case 4:
            calcularProduccion(tiempos, recursos, cantidades, cantidadActual, t_entrega, cant_recursos);
            break;
        case 5:
            mostrarProductos(nombres, tiempos, recursos, cantidades, cantidadActual);
            break;
        case 6:
            printf("Saliendo del programa.\n");
            break;
        
        default:
            printf("Opción no válida. Por favor, ingrese una opción válida.\n");
            break;
        }

    }while(opc != 6);

    return 0;
}