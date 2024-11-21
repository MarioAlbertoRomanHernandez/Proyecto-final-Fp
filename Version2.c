#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void mostrarSucursales();
void mostrarMenu();
void mostrarBebidasCalientes();
void mostrarBebidasFrias();
void mostrarSnacks();
void agregarAlCarrito(char *producto, float precio, int calorias);
void mostrarCarrito();
void aplicarDescuento(float *total);
void pagar();

char *sucursales[] = {"Sucursal 1", "Sucursal 2", "Sucursal 3"};
char *direcciones[] = {"Cerca de CU, Direccion 1", "Cerca de CU, Direccion 2", "Cerca de CU, Direccion 3"};

char *bebidasCalientes[] = {"Cafe Americano", "Latte", "Capuchino", "Te Verde Matcha Latte", "Infusion de Hierbas del dia (manzanilla, menta o jengibre)"};
float preciosBebidasCalientes[] = {30.0, 40.0, 45.0, 50.0, 25.0};
int caloriasBebidasCalientes[] = {5, 150, 120, 100, 0};

char *bebidasFrias[] = {"Americano helado", "Frappe de Chocolate", "Frappe de Matcha", "Frappe de Cafe Clasico"};
float preciosBebidasFrias[] = {45.0, 55.0, 60.0, 50.0};
int caloriasBebidasFrias[] = {15, 300, 250, 200};

char *snacks[] = {"Yogurt con Granola y Fruta", "Ensalada", "Wrap Integral", "Barrita de Avena y Frutos Secos", "Fruta Fresca"};
float preciosSnacks[] = {50.0, 60.0, 75.0, 15.0, 45.0};
int caloriasSnacks[] = {310, 130, 250, 220, 50};

char *carritoProductos[50];
float carritoPrecios[50];
int carritoCalorias[50];
int carritoCantidad=0, i;
char usuarioAdmin[20];
char contrasenaAdmin[12];
char usuarioCliente[20];
char contrasenaCliente[20];

int main() {
    int opcion, sucursalSeleccionada, productoSeleccionado;
    mostrarSucursales();
    scanf("%d", &sucursalSeleccionada);
    printf("Bienvenido a la %s\n", sucursales[sucursalSeleccionada - 1]);

    do {
        printf("\t\tCode and Coffe\n \t\t Cafesync\n");
        printf("\t Menu Principal\n");
        printf(" 1. Administrador\n 2. Comprar\n 3. Contactar programadores \n 4. Salir");
    case 1:
        printf("Acceso al modo Admin\n");
        printf("Ingrese nombre de usuario: ");
        scanf("%s", &usuarioAdmin);
        printf("Ingrese contrasena: ");
        scanf("%s", &contrasenaAdmin);
        break;
    case 2:
        mostrarMenu();
        break;
    case 3:
        printf("Programa creado por The Pixies Company\n");
        printf("Contactar servicio:\n");
        printf("CEO: [Por agregar]\n");
        printf("Atención al cliente: [Por agregar]\n");
        break;
    case 4:
        printf("Gracias por visitar nuestra cafeteria. Hasta luego! :D\n");
        break;
    default:
        printf("Opcion no valida. Intente de nuevo.\n");
    }
}
while (opcion != 4);

return 0;
}

void mostrarSucursales() {
    printf("Seleccione una sucursal:\n");
    for(i=0; i<3; i++) {
        printf("%d. %s - %s\n", i + 1, sucursales[i], direcciones[i]);
    }
}

void mostrarMenu() {
    printf("Bienvenidx, que deseas comprar?\n 1. Bebida(s) caliente(s)\n 2. Bebida(s) fria(s)\n 3. Snacks\n 4. Ver carrito\n 5. Salir\n");
    printf("Ingresé una opción: ");
    scanf("%d", &opcion);
    switch (opcion) {
    case 1:
        mostrarBebidasCalientes();
        printf("Seleccione una bebida caliente para agregar al carrito:\n");
        scanf("%d", &productoSeleccionado);
        if(productoSeleccionado>0 && productoSeleccionado<5) {
            agregarAlCarrito(bebidasCalientes[productoSeleccionado - 1], preciosBebidasCalientes[productoSeleccionado - 1], caloriasBebidasCalientes[productoSeleccionado - 1]);
        } else {
            printf("Opcion no valida\n");
        }
        break;
    case 2:
        mostrarBebidasFrias();
        printf("Seleccione una bebida fria para agregar al carrito:\n");
        scanf("%d", &productoSeleccionado);
        if(productoSeleccionado>0 && productoSeleccionado<3) {
            agregarAlCarrito(bebidasFrias[productoSeleccionado - 1], preciosBebidasFrias[productoSeleccionado - 1], caloriasBebidasFrias[productoSeleccionado - 1]);
        } else {
            printf("Opcion no valida\n");
        }
        break;
    case 3:
        mostrarSnacks();
        printf("Seleccione una snack para agregar al carrito:\n");
        scanf("%d", &productoSeleccionado);
        if(productoSeleccionado>0 && productoSeleccionado<5) {
            agregarAlCarrito(snacks[productoSeleccionado - 1], preciosSnacks[productoSeleccionado - 1], caloriasSnacks[productoSeleccionado - 1]);
        } else {
            printf("Opcion no valida\n");
        }
        break;
    case 4:
        mostrarCarrito();
        printf("¿Desea proceder al pago? (1: Si, 0: No): ");
        int proceder;
        scanf("%d", &proceder);
        if (proceder) {
            pagar();
        }
        break;
    case 5:
        printf("Regresando al menu principal...\n");
        break;
    default:
        printf("Ingrese una opcion valida\n");
    }
    while(opción!=5)
    }

void mostrarBebidasCalientes() {
    printf("Menu de Bebidas Calientes:\n");
    for (i=0; i<5; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, bebidasCalientes[i], preciosBebidasCalientes[i], caloriasBebidasCalientes[i]);
    }
}

void mostrarBebidasFrias() {
    printf("Menu de Bebidas Frias:\n");
    for (i=0; i<4; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, bebidasFrias[i], preciosBebidasFrias[i], caloriasBebidasFrias[i]);
    }
}

void mostrarSnacks() {
    printf("Menu de Snacks:\n");
    for (i=0; i<5; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, snacks[i], preciosSnacks[i], caloriasSnacks[i]);
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
    for (i=0; i<carritoCantidad; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, carritoProductos[i], carritoPrecios[i], carritoCalorias[i]);
        total += carritoPrecios[i];
        totalCalorias += carritoCalorias[i];
    }
    printf("Total: $%.2f\n", total);
    printf("Total de calorias: %d\n", totalCalorias);
}

void aplicarDescuento(float *total) {
    char numeroCuenta[10];
    printf("Ingrese su numero de cuenta de la UNAM (sin guiones): ");
    scanf("%s", numeroCuenta);
    if (strlen(numeroCuenta) == 9) {
        *total *= 0.9; // Aplica un 10% de descuento
        printf("Descuento aplicado. Nuevo total: $%.2f\n", *total);
    } else {
        printf("Numero de cuenta invalido. No se aplico el descuento\n");
    }
}

void pagar() {
    float total = 0.0;
    int opc;
    for (i=0; i<carritoCantidad; i++) {
        total += carritoPrecios[i];
    }
    printf("Total a pagar: $%.2f\n", total);
    printf("Desea aplicar el descuento UNAM?\n");
    printf("Ingrese 1 como afirmacion o cualquier otro numero para no aplicarlo: ");
    scanf("%d", &opc);
    if(opc==1) {
        aplicarDescuento(&total);
    }
    printf("Pago realizado. Gracias por su compra.\n");
    carritoCantidad = 0; // Vaciar el carrito después de pagar
}
