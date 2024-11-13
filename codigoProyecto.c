#include <stdio.h>
#include <string.h>

void mostrarSucursales();
void mostrarMenu();
void mostrarBebidasCalientes();
void mostrarBebidasFrias();
void mostrarComidas();
void agregarAlCarrito(char *producto, float precio, int calorias);
void mostrarCarrito();
void aplicarDescuento(float *total);
void pagar();

char *sucursales[] = {"Sucursal 1", "Sucursal 2", "Sucursal 3"};
char *direcciones[] = {"Cerca de CU, Dirección 1", "Cerca de CU, Dirección 2", "Cerca de CU, Dirección 3"};

char *bebidasCalientes[] = {"Café Americano", "Latte", "Capuchino", "Té Verde Matcha Latte", "Infusión de Hierbas (manzanilla, menta, jengibre)"};
float preciosBebidasCalientes[] = {30.0, 40.0, 45.0, 50.0, 25.0};
int caloriasBebidasCalientes[] = {5, 150, 120, 100, 0};

char *bebidasFrias[] = {"Frappé de Chocolate", "Frappé de Matcha", "Frappé de Café Clásico"};
float preciosBebidasFrias[] = {55.0, 60.0, 50.0};
int caloriasBebidasFrias[] = {300, 250, 200};

char *comidas[] = {"Sandwich", "Ensalada", "Panini"};
float preciosComidas[] = {50.0, 45.0, 55.0};
int caloriasComidas[] = {300, 200, 350};

char *carritoProductos[50];
float carritoPrecios[50];
int carritoCalorias[50];
int carritoCantidad = 0;

int main() {
    int opcion, sucursalSeleccionada, productoSeleccionado;
    mostrarSucursales();
    scanf("%d", &sucursalSeleccionada);
    printf("Bienvenido a la %s\n", sucursales[sucursalSeleccionada - 1]);

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                mostrarBebidasCalientes();
                printf("Seleccione una bebida caliente para agregar al carrito:\n");
                scanf("%d", &productoSeleccionado);
                agregarAlCarrito(bebidasCalientes[productoSeleccionado - 1], preciosBebidasCalientes[productoSeleccionado - 1], caloriasBebidasCalientes[productoSeleccionado - 1]);
                break;
            case 2:
                mostrarBebidasFrias();
                printf("Seleccione una bebida fría para agregar al carrito:\n");
                scanf("%d", &productoSeleccionado);
                agregarAlCarrito(bebidasFrias[productoSeleccionado - 1], preciosBebidasFrias[productoSeleccionado - 1], caloriasBebidasFrias[productoSeleccionado - 1]);
                break;
            case 3:
                mostrarComidas();
                printf("Seleccione una comida para agregar al carrito:\n");
                scanf("%d", &productoSeleccionado);
                agregarAlCarrito(comidas[productoSeleccionado - 1], preciosComidas[productoSeleccionado - 1], caloriasComidas[productoSeleccionado - 1]);
                break;
            case 4:
                mostrarCarrito();
                printf("¿Desea proceder al pago? (1: Sí, 0: No): ");
                int proceder;
                scanf("%d", &proceder);
                if (proceder) {
                    pagar();
                }
                break;
            case 5:
                printf("Contactar servicio:\n");
                printf("CEO: [Por agregar]\n");
                printf("Atención al cliente: [Por agregar]\n");
                break;
            case 6:
                printf("Gracias por visitar nuestra cafetería. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}

void mostrarSucursales() {
    printf("Seleccione una sucursal:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - %s\n", i + 1, sucursales[i], direcciones[i]);
    }
}

void mostrarMenu() {
    printf("Menú:\n");
    printf("1. Bebidas Calientes\n");
    printf("2. Bebidas Frías\n");
    printf("3. Comidas\n");
    printf("4. Ver carrito\n");
    printf("5. Contactar servicio\n");
    printf("6. Salir\n");
}

void mostrarBebidasCalientes() {
    printf("Menú de Bebidas Calientes:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f - %d calorías\n", i + 1, bebidasCalientes[i], preciosBebidasCalientes[i], caloriasBebidasCalientes[i]);
    }
}

void mostrarBebidasFrias() {
    printf("Menú de Bebidas Frías:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - $%.2f - %d calorías\n", i + 1, bebidasFrias[i], preciosBebidasFrias[i], caloriasBebidasFrias[i]);
    }
}

void mostrarComidas() {
    printf("Menú de Comidas:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - $%.2f - %d calorías\n", i + 1, comidas[i], preciosComidas[i], caloriasComidas[i]);
    }
}

void agregarAlCarrito(char *producto, float precio, int calorias) {
    carritoProductos[carritoCantidad] = producto;
    carritoPrecios[carritoCantidad] = precio;
    carritoCalorias[carritoCantidad] = calorias;
    carritoCantidad++;
}

void mostrarCarrito() {
    printf("Carrito de Compras:\n");
    float total = 0;
    int totalCalorias = 0;
    for (int i = 0; i < carritoCantidad; i++) {
        printf("%d. %s - $%.2f - %d calorías\n", i + 1, carritoProductos[i], carritoPrecios[i], carritoCalorias[i]);
        total += carritoPrecios[i];
        totalCalorias += carritoCalorias[i];
    }
    printf("Total: $%.2f\n", total);
    printf("Total de calorías: %d\n", totalCalorias);
}

void aplicarDescuento(float *total) {
    char numeroCuenta[10];
    printf("Ingrese su número de cuenta de la UNAM (9 dígitos): ");
    scanf("%s", numeroCuenta);
    if (strlen(numeroCuenta) == 9) {
        *total *= 0.9; // Aplica un 10% de descuento
        printf("Descuento aplicado. Nuevo total: $%.2f\n", *total);
    } else {
        printf("Número de cuenta inválido. No se aplicó el descuento.\n");
    }
}

void pagar() {
    float total = 0;
    for (int i = 0; i < carritoCantidad; i++) {
        total += carritoPrecios[i];
    }
    printf("Total a pagar: $%.2f\n", total);
    aplicarDescuento(&total);
    printf("Pago realizado. Gracias por su compra.\n");
    carritoCantidad = 0; // Vaciar el carrito después de pagar
}
