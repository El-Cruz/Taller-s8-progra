
void line();
void menu();
void agregarProducto(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int *cantidadActual, int t_entrega[]);
void mostrarProductos(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int cantidadActual);
void editarProducto(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int cantidadActual);
void eliminarProducto(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int *cantidadActual);
void calcularProduccion(int tiempos[], int recursos[], int cantidades[], int cantidadActual, int t_entrega[], int cant_recursos);