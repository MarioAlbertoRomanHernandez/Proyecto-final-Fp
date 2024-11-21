#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mostrarSucursales();
void mostrarMenu();
void mostrarBebidasCalientes();
void personalizarBebidaCaliente(int seleccion);
void mostrarBebidasFrias();
void mostrarSnacks();
void personalizarSnack(int seleccion);
void agregarAlCarrito(char *producto, float precio, int calorias);
void mostrarCarrito();
void aplicarDescuento(float *total);
void pagar();
void iniciarSesion();
void registrarUsuario();
int verificarUsuario(char *usuario, char *contrasena);
int verificarCuentaUNAM(char *cuenta);

char *sucursales[] = {"Facultad de Ingenieria", "Facultad de Medicina"};
char *direcciones[] = {"Cerca de CU, Facultad de Ingenieria", "Cerca de CU, Facultad de Medicina"};
char *bebidasCalientes[] = {"Americano", "Latte", "Capuchino", "Te Verde", "Infusion de hierbas (manzanilla, limon)"};
float preciosBebidasCalientes[] = {30.0, 40.0, 45.0, 50.0, 25.0};
int caloriasBebidasCalientes[] = {5, 150, 120, 100, 0};
char *bebidasFrias[] = {"Americano Frio", "Frappe de Chocolate", "Frappe de Matcha", "Frappe de Cafe Clasico", "Frappe de Moka"};
float preciosBebidasFrias[] = {45.0, 55.0, 60.0, 50.0, 65.0};
int caloriasBebidasFrias[] = {15, 300, 250, 200, 280};
char *snacks[] = {"Yogurt con Fruta y Granola", "Ensalada", "Wrap Integral", "Barrita de Avena y Frutos Secos", "Fruta"};
float preciosSnacks[] = {50.0, 60.0, 75.0, 15.0, 45.0};
int caloriasSnacks[] = {310, 130, 250, 220, 50};
char *carritoProductos[50];
float carritoPrecios[50];
int carritoCalorias[50];
int carritoCantidad = 0, i;

int main() {
    int opcion, sucursalSeleccionada, productoSeleccionado;
    printf("Bienvenido a la Cafeteria Cafesyinc\n");
    iniciarSesion();
    mostrarSucursales();
    scanf("%d", &sucursalSeleccionada);
    printf("Bienvenido a la %s\n", sucursales[sucursalSeleccionada - 1]);
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                mostrarBebidasCalientes();
                printf("Seleccione una bebida caliente para personalizar:\n");
                scanf("%d", &productoSeleccionado);
                personalizarBebidaCaliente(productoSeleccionado);
                break;
            case 2:
                mostrarBebidasFrias();
                printf("Seleccione una bebida fria para agregar al carrito:\n");
                scanf("%d", &productoSeleccionado);
                if(productoSeleccionado > 0 && productoSeleccionado <= 5){
                    agregarAlCarrito(bebidasFrias[productoSeleccionado - 1], preciosBebidasFrias[productoSeleccionado - 1], caloriasBebidasFrias[productoSeleccionado - 1]);
                } else {
                    printf("Opcion no valida\n");
                }
                break;
            case 3:
                mostrarSnacks();
                printf("Seleccione un snack para personalizar:\n");
                scanf("%d", &productoSeleccionado);
                if(productoSeleccionado > 0 && productoSeleccionado <= 5){
                    personalizarSnack(productoSeleccionado);
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
                printf("Contactar servicio:\n");
                printf("Sucursal F. Ingenieria: +52 55 1234 5678\n");
                printf("Sucursal F. Medicina: +52 55 8765 4321\n");
                printf("Atencion al cliente: soporte@cafesync.com\n");
                break;
            case 6:
                printf("Gracias por visitar nuestra cafeteria. ¡Hasta luego! :D\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 6);
    return 0;
}

void mostrarSucursales() {
    printf("Seleccione una sucursal:\n");
    for(i = 0; i < 2; i++) {
        printf("%d. %s - %s\n", i + 1, sucursales[i], direcciones[i]);
    }
}

void mostrarMenu() {
    printf("Menu:\n");
    printf("1. Bebidas Calientes\n");
    printf("2. Bebidas Frias\n");
    printf("3. Snacks\n");
    printf("4. Ver carrito\n");
    printf("5. Contactar servicio\n");
    printf("6. Salir\n");
}

void mostrarBebidasCalientes() {
    printf("Menu de Bebidas Calientes:\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, bebidasCalientes[i], preciosBebidasCalientes[i], caloriasBebidasCalientes[i]);
    }
}

void personalizarBebidaCaliente(int seleccion) {
    if (seleccion > 0 && seleccion <= 5) {
        printf("Seleccione el tipo de leche (1: Entera, 2: Deslactosada, 3: Almendra, 4: Coco): ");
        int tipoLeche;
        scanf("%d", &tipoLeche);
        printf("¿Desea agregar azucar? (1: Si, 0: No): ");
        int azucar;
        scanf("%d", &azucar);
        printf("¿Desea agregar crema? (1: Si, 0: No): ");
        int crema;
        scanf("%d", &crema);
        printf("Bebida personalizada agregada al carrito.\n");
        agregarAlCarrito(bebidasCalientes[seleccion - 1], preciosBebidasCalientes[seleccion - 1], caloriasBebidasCalientes[seleccion - 1]);
    } else {
        printf("Opcion no valida\n");
    }
}

void mostrarBebidasFrias() {
    printf("Menu de Bebidas Frias:\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, bebidasFrias[i], preciosBebidasFrias[i], caloriasBebidasFrias[i]);
    }
}

void mostrarSnacks() {
    printf("Menu de Snacks:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, snacks[i], preciosSnacks[i], caloriasSnacks[i]);
    }
}

void personalizarSnack(int seleccion) {
    if (seleccion == 1) { // Yogurt con Fruta y Granola
        printf("Seleccione el tipo de yogurt (1: Natural, 2: Fresa): ");
        int tipoYogurt;
        scanf("%d", &tipoYogurt);
        printf("Seleccione hasta 3 frutas (1: Mango, 2: Manzana, 3: Sandia, 4: Kiwi, 5: Naranja, 6: Jicama, 7: Melon, 8: Platano): ");
        int frutas[3];
        for (int j = 0; j < 3; j++) {
            scanf("%d", &frutas[j]);
        }
        printf("¿Desea agregar granola? (1: Si, 0: No): ");
        int granola;
        scanf("%d", &granola);
        printf("Yogurt personalizado agregado al carrito.\n");
    } else if (seleccion == 5) { // Plato de frutas
        printf("Seleccione hasta 3 frutas (1: Mango, 2: Manzana, 3: Sandia, 4: Kiwi, 5: Naranja, 6: Jicama, 7: Melon, 8: Platano): ");
        int frutas[3];
        for (int j = 0; j < 3; j++) {
            scanf("%d", &frutas[j]);
        }
        printf("Plato de frutas personalizado agregado al carrito.\n");
    }
    agregarAlCarrito(snacks[seleccion - 1], preciosSnacks[seleccion - 1], caloriasSnacks[seleccion - 1]);
}

void agregarAlCarrito(const char* snack, float precio, int calorias) {
    // Lógica para agregar el snack al carrito
    printf("Agregado al carrito: %s - $%.2f - %d calorias\n", snack, precio, calorias);
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
    for (i = 0; i < carritoCantidad; i++) {
        printf("%s - $%.2f - %d calorias\n", carritoProductos[i], carritoPrecios[i], carritoCalorias[i]);
        total += carritoPrecios[i];
        totalCalorias += carritoCalorias[i];
    }
    printf("Total: $%.2f\n", total);
    printf("Total de Calorias: %d\n", totalCalorias);
    aplicarDescuento(&total);
    printf("Total con descuento: $%.2f\n", total);
}

void aplicarDescuento(float *total) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    if (tm.tm_mon == 10 || tm.tm_mon == 5) { // Noviembre o Junio
        printf("Descuento del 20%% aplicado por semana de examenes.\n");
        *total *= 0.80;
    } else {
        printf("Descuento del 15%% aplicado por ser de la UNAM.\n");
        *total *= 0.85;
    }
    if (tm.tm_hour < 10) { // Antes de las 10 AM
        printf("Descuento del 10%% adicional por combo desayuno.\n");
        *total *= 0.90;
    }

    // Descuento adicional para estudiantes de la UNAM
    char cuentaUNAM[10];
    printf("Ingrese su numero de cuenta de la UNAM (9 digitos) para un descuento adicional: ");
    scanf("%s", cuentaUNAM);
    if (verificarCuentaUNAM(cuentaUNAM)) {
        printf("Descuento del 15%% adicional aplicado por ser estudiante de la UNAM.\n");
        *total *= 0.85;
    } else {
        printf("Numero de cuenta no valido. No se aplicara el descuento adicional.\n");
    }
}

int verificarCuentaUNAM(char *cuenta) {
    // Verificar que la cuenta tenga exactamente 9 digitos
    if (strlen(cuenta) != 9) {
        return 0; // Cuenta no valida
    }
    for (int i = 0; i < 9; i++) {
        if (cuenta[i] < '0' || cuenta[i] > '9') {
            return 0; // No es un digito
        }
    }
    return 1; // Cuenta valida
}

void pagar() {
    printf("Pago realizado con exito. ¡Gracias por su compra!\n");
}

void iniciarSesion() {
    int opcion;
    printf("1. Iniciar Sesion\n");
    printf("2. Registrarse\n");
    scanf("%d", &opcion);
    if (opcion == 1) {
        char usuario[50], contrasena[50];
        printf("Usuario: ");
        scanf("%s", usuario);
        printf("Contrasena: ");
        scanf("%s", contrasena);
        if (verificarUsuario(usuario, contrasena)) {
            printf("Inicio de sesion exitoso.\n");
        } else {
            printf("Usuario o contrasena incorrectos. Intente de nuevo.\n");
            iniciarSesion();
        }
    } else if (opcion == 2) {
        registrarUsuario();
    } else {
        printf("Opcion no valida. Intente de nuevo.\n");
        iniciarSesion();
    }
}

void registrarUsuario() {
    char usuario[50], contrasena[50];
    printf("Usuario: ");
    scanf("%s", usuario);
    printf("Contrasena: ");
    scanf("%s", contrasena);

    FILE *archivo = fopen("usuarios.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        return;
    }

    fprintf(archivo, "%s %s\n", usuario, contrasena);
    fclose(archivo);

    printf("Usuario registrado con exito.\n");
}

int verificarUsuario(char *usuario, char *contrasena) {
    char usuarioArchivo[50], contrasenaArchivo[50];
    FILE *archivo = fopen("usuarios.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        return 0;
    }

    while (fscanf(archivo, "%s %s", usuarioArchivo, contrasenaArchivo) != EOF) {
        if (strcmp(usuario, usuarioArchivo) == 0 && strcmp(contrasena, contrasenaArchivo) == 0) {
            fclose(archivo);
            return 1;
        }
    }

    fclose(archivo);
    return 0;
}
