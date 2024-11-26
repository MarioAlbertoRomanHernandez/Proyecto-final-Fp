#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mostrarSucursales();
void menuOriginal();
void mostrarMenu();
void mostrarBebidasCalientes();
void personalizarBebidaCaliente(int seleccion);
void mostrarBebidasFrias();
void mostrarSnacks();
void personalizarSnack(int seleccion);
void agregarAlCarrito(char *producto, float precio, int calorias);
void mostrarCarrito();
void aplicarDescuento(float *total);
void iniciarSesion();
void registrarUsuario();
void actualizarUsuario(char *usuario);
void administradores();
void menuAdmin();
void mostrarUsuarios();
void eliminarUsuario();
void pagar();
void aumentarDinero(float cantidad);
void cambiarMenu(int numeroCambio);
int usuarioDisponible(char usuarioVerificar[]);
int verificarUsuario(char *usuario, char *contrasena);
int verificarCuentaUNAM(char *cuenta);
int verificarAdmin(char *usuario, char *contrasena);
void leerMenuBebidasCalientes();
void leerMenuBebidasFrias();
void leerMenuSnacks();
void escribirMenuBebidasCalientes();
void escribirMenuBebidasFrias();
void escribirMenuSnacks();
void contactar();

//variables globales
char bebidasCalientes[5][50];
float preciosBebidasCalientes[5];
int caloriasBebidasCalientes[5];
char bebidasFrias[5][50];
float preciosBebidasFrias[5];
int caloriasBebidasFrias[5];
char snacks[5][50];
float preciosSnacks[5];
int caloriasSnacks[5];
char *carritoProductos[50];
float carritoPrecios[50];
int carritoCalorias[50];
int carritoCantidad = 0;
float total=0.0, dinero;
float dineroInicial=250.00;
char usuario[20];
int i, j;

//Variables de sucursal y direccion
char sucursales[2][50] = {"Facultad de ingenieria", "facultad de Medicina"};
char direcciones[2][100] = {"CU anexo de ingenieria ", "CU entrando por la calle de medicina"};

int main() {
    int opc;
    printf("Bienvenido a la Cafeteria Cafesyinc\n");
    printf("Eres:\n 1. Administrador\n 2. Usuario\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opc);
    if (opc == 1) {
        administradores();
        char usuarioAdmin[20], contrasenaAdmin[20];
        printf("Acceso al modo Administrador\n");
        printf("Ingrese nombre de usuario: ");
        scanf("%s", usuarioAdmin);
        printf("Ingrese contrasena: ");
        scanf("%s", contrasenaAdmin);
        if (verificarAdmin(usuarioAdmin, contrasenaAdmin)) {
            printf("Acceso concedido. Bienvenido al Menu Administrador.\n");
            menuAdmin();
        } else {
            printf("Acceso denegado. Usuario o contrasena incorrectos.\n");
        }
    } else if (opc == 2) {
        mostrarSucursales();
        int sucursalSeleccionada;
        scanf("%d", &sucursalSeleccionada);
        printf("Bienvenido a la %s\n", sucursales[sucursalSeleccionada - 1]);
        iniciarSesion();
        mostrarMenu();
    } else {
        printf("Opcion no valida. Intente de nuevo.\n");
    }
    return 0;
}

void mostrarSucursales() {
    printf("Seleccione una sucursal:\n");
    for(i = 0; i < 2; i++) {
        printf("%d. %s - %s\n", i + 1, sucursales[i], direcciones[i]);
    }
}

void mostrarMenu() {
    int opcion, productoSeleccionado, personalizar;
    do {
        printf("Menu:\n");
        printf("1. Bebidas Calientes\n");
        printf("2. Bebidas Frias\n");
        printf("3. Snacks\n");
        printf("4. Ver carrito\n");
        printf("5. Contactar\n");
        printf("6. Salir\n");
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
                printf("Seleccione un snack: ");
                scanf("%d", &productoSeleccionado);
                if(productoSeleccionado > 0 && productoSeleccionado <= 5){
                    if(productoSeleccionado == 1 || productoSeleccionado == 5){
                        personalizarSnack(productoSeleccionado);    
                    } else {
                        agregarAlCarrito(snacks[productoSeleccionado - 1], preciosSnacks[productoSeleccionado - 1], caloriasSnacks[productoSeleccionado - 1]);
                    }
                } else {
                    printf("Opcion no valida\n");
                }
                break;
            case 4:
                mostrarCarrito();
                printf("Desea proceder al pago? (1: Si, 0: No): ");
                int proceder;
                scanf("%d", &proceder);
                if (proceder) {
                    pagar();
                }
                break;
            case 5:
                contactar();
                break;
            case 6:
                printf("Saliendo al menu principal...\n");
                break;
            default:
                printf("Ingrese una opcion valida\n");
        }
    } while(opcion != 6);
}

void personalizarSnack(int seleccion);{
(seleccion == 1) { // Yogurt con fruta y granola
        printf("Seleccione el tipo de yogurt (1: Natural, 2: Fresa): ");
        int tipoYogurt;
        scanf("%d", &tipoYogurt);
        printf("Seleccione hasta 3 frutas (1: Mango, 2: Manzana, 3: Sandia, 4: Kiwi, 5: Naranja, 6: Jicama, 7: Melon, 8: Platano): ");
        int fvoid mostrarBebidasCalientes() {
    leerMenuBebidasCalientes();
    printf("Menu de Bebidas Calientes:\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, bebidasCalientes[i], preciosBebidasCalientes[i], caloriasBebidasCalientes[i]);
    }
}
}

void mostrarBebidasFrias() {
    leerMenuBebidasFrias();
    printf("Menu de Bebidas Frias:\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, bebidasFrias[i], preciosBebidasFrias[i], caloriasBebidasFrias[i]);
    }
}

void mostrarSnacks() {
    leerMenuSnacks();
    printf("Menu de Snacks:\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, snacks[i], preciosSnacks[i], caloriasSnacks[i]);
    }
}

void personalizarBebidaCaliente(int seleccion) {
    if (seleccion > 0 && seleccion <= 5) {
        printf("Tipo de leche \n1: Entera \n2: Deslactosada \n3: Almendra \n4: Coco\n Seleccione uno: ");
        int tipoLeche;
        scanf("%d", &tipoLeche);

        int azucar;
        do {
            printf("Desea agregar azucar? (1: Si, 0: No): ");
            scanf("%d", &azucar);
            if (azucar != 1 && azucar != 0) {
                printf("Opcion no valida. Por favor, ingrese 1 para Si o 0 para No.\n");
            }
        } while (azucar != 1 && azucar != 0);

        int crema;
        do {
            printf("Desea agregar crema? (1: Si, 0: No): ");
            scanf("%d", &crema);
            if (crema != 1 && crema != 0) {
                printf("Opcion no valida. Por favor, ingrese 1 para Si o 0 para No.\n");
            }
        } while (crema != 1 && crema != 0);

        printf("Bebida personalizada agregada al carrito.\n");
        agregarAlCarrito(bebidasCalientes[seleccion - 1], preciosBebidasCalientes[seleccion - 1], caloriasBebidasCalientes[seleccion - 1]);
    } else {
        printf("Opcion no valida\n");
    }
}

void personalizarSnack(int seleccion) {

       if (selrutas[3];
        for (j = 0; j < 3; j++) {
            scanf("%d", &frutas[j]);
        }
        printf("Desea agregar granola? (1: Si, 0: No): ");
        int granola;
        scanf("%d", &granola);
        printf("Yogurt personalizado agregado al carrito.\n");
    } else if (seleccion == 5) { // Plato de frutas
        printf("Seleccione hasta 3 frutas (1: Mango, 2: Manzana, 3: Sandia, 4: Kiwi, 5: Naranja, 6: Jicama, 7: Melon, 8: Platano): ");
        int frutas[3];
        for (j = 0; j < 3; j++) {
            scanf("%d", &frutas[j]);
        }
        printf("Plato de frutas personalizado agregado al carrito.\n");
    }
    agregarAlCarrito(snacks[seleccion - 1], preciosSnacks[seleccion - 1], caloriasSnacks[seleccion - 1]);
}

void agregarAlCarrito(char *producto, float precio, int calorias) {
    if (carritoCantidad < 10) {
        carritoProductos[carritoCantidad] = producto;
        carritoPrecios[carritoCantidad] = precio;
        carritoCalorias[carritoCantidad] = calorias;
        carritoCantidad++;
    } else {
        printf("Su carrito esta lleno, no puede hacer un pedido de mas de 10 productos\n");
    }
}

void mostrarCarrito() {
    printf("Carrito de Compras:\n");
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

    // Descuento para alumnos de la UNAM
    char cuentaUNAM[10];
    int descuento;
    printf("Forma parte de la comunidad UNAM?\n");
    printf("Digite 1 si la respuesta es afirmativa, si no es asi digite cualquier otro numero \n");
    scanf("%d", &descuento);
    if (descuento == 1) {
        printf("Ingrese su numero de cuenta de la UNAM (9 digitos) para un descuento adicional: ");
        scanf("%s", cuentaUNAM);
        if (verificarCuentaUNAM(cuentaUNAM)) {
            printf("Descuento del 15%% adicional aplicado por ser estudiante de la UNAM.\n");
            *total *= 0.85;
        } else {
            printf("Numero de cuenta no valido. No se aplicara el descuento adicional.\n");
        }
    }
}

int verificarCuentaUNAM(char *cuenta) {
    // Verificar que la cuenta es de 9 digitos
    if (strlen(cuenta) != 9) {
        return 0; // Cuenta no valida
    }
    for (i = 0; i < 9; i++) {
        if (cuenta[i] < '0' || cuenta[i] > '9') {
            return 0; // No es un digito
        }
    }
    return 1; // Cuenta valida
}

void iniciarSesion() {
    char contrasena[20];
    int opcion;
    printf("1. Iniciar Sesion\n");
    printf("2. Registrarse\n");
    scanf("%d", &opcion);
    if (opcion == 1) {
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
    char contrasena[20];
    int disponible;

    printf("Usuario: ");
    scanf("%s", usuario);
    printf("Contrasena: ");
    scanf("%s", contrasena);

    FILE *archivo = fopen("usuarios.txt", "a+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        return;
    }

    disponible = usuarioDisponible(usuario);
    if (disponible == 1) {
        fprintf(archivo, "%s %s %.2f\n", usuario, contrasena, dineroInicial);
        printf("Usuario registrado con exito.\n");
        dinero = dineroInicial;
    } else {
        printf("El nombre de usuario ya ha sido registrado o ha ocurrido un error\n");
        registrarUsuario();
    }

    fclose(archivo);
}

int usuarioDisponible(char usuarioVerificar[20]) {
    FILE *archivo = fopen("usuarios.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de usuarios\n");
        return 0;
    }

    char usuarioArchivo[20], contrasenaArchivo[20];
    float saldoArchivo;

    while (fscanf(archivo, "%s %s %f", usuarioArchivo, contrasenaArchivo, &saldoArchivo) != EOF) { // Verificar si el usuario ya existe
        if (strcmp(usuarioArchivo, usuarioVerificar) == 0) {
            fclose(archivo);
            return 0; // Usuario no existe
        }
    }
    fclose(archivo);
    return 1; // Usuario disponible
}

int verificarUsuario(char *usuario, char *contrasena) {
    char usuarioArchivo[20], contrasenaArchivo[20];
    float saldoArchivo;
    FILE *archivo = fopen("usuarios.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de usuarios\n");
        return 0;
    }

    while (fscanf(archivo, "%s %s %f", usuarioArchivo, contrasenaArchivo, &saldoArchivo) != EOF) {
        if (strcmp(usuario, usuarioArchivo) == 0 && strcmp(contrasena, contrasenaArchivo) == 0) {
            dinero = saldoArchivo; // Asignar el saldo
            fclose(archivo);
            return 1;
        }
    }
    fclose(archivo);
    return 0;
}

void pagar() {
    int cantidadIngresada;
    if (dinero >= total) {
        dinero -= total;
        printf("Pago realizado con exito. Gracias por su compra!\n");
        printf("Usted cuenta con $%.2f\n", dinero);
        // Actualizar datos del archivo
        actualizarUsuario(usuario);
    } else {
        printf("Necesita pagar $%.2f\n", total - dinero);
        printf("Desea ingresar dinero a su cuenta? (1: Si, 0: No): ");
        int afirmacion;
        scanf("%d", &afirmacion);
        if (afirmacion == 1) {
            printf("Ingrese el monto a agregar a su saldo: ");
            scanf("%d", &cantidadIngresada);
            aumentarDinero(cantidadIngresada);
        } else {
            printf("No se puede realizar la compra\n");
        }
    }
}

void aumentarDinero(float cantidad) {
    dinero += cantidad;
    printf("Se han agregado $%.2f a su saldo. Nuevo saldo: $%.2f\n", cantidad, dinero);
    actualizarUsuario(usuario); // Actualizar el archivo despues de aumentar el dinero
}

void actualizarUsuario(char *usuario) {
    char usuarioArchivo[20], contrasenaArchivo[20];
    float saldoArchivo;
    FILE *archivo = fopen("usuarios.txt", "r");
    FILE *temporal = fopen("temp.txt", "w+");
    if (archivo == NULL || temporal == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    while (fscanf(archivo, "%s %s %f", usuarioArchivo, contrasenaArchivo, &saldoArchivo) != EOF) {
        if (strcmp(usuarioArchivo, usuario) == 0) {
            saldoArchivo = dinero; // Actualizar el saldo
        }
        fprintf(temporal, "%s %s %.2f\n", usuarioArchivo, contrasenaArchivo, saldoArchivo);
    }

    fclose(archivo);
    fclose(temporal);
    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");
}
void administradores() {
    FILE *archivo = fopen("admins.txt", "w"); // Cambiado a "w" para sobrescribir el archivo
    if (archivo == NULL) {
        printf("Error al abrir el archivo de administradores.\n");
        return;
    }
    fprintf(archivo, "%s %s\n", "Mario", "Marioh17$");
    fprintf(archivo, "%s %s\n", "Guadalupe", "N0l0s3");
    fclose(archivo);
}

int verificarAdmin(char* usuario, char* contrasena) {
    FILE *archivo = fopen("admins.txt", "r");
    char usuarioArchivo[20], contrasenaArchivo[20];

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de administradores\n");
        return 0; // Error al abrir el archivo
    }

    while (fscanf(archivo, "%s %s", usuarioArchivo, contrasenaArchivo) != EOF) {
        if (strcmp(usuarioArchivo, usuario) == 0 && strcmp(contrasenaArchivo, contrasena) == 0) {
            fclose(archivo);
            return 1; // Credenciales correctas
        }
    }
    fclose(archivo);
    return 0; // Credenciales incorrectas
}

void menuAdmin() {
    int opcion, cambio;
    do {
        printf("\n     Menu Administrador   \n");
        printf("1. Cambiar Menu\n");
        printf("2. Eliminar usuario\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Cambiar Menu\n 1. Bebidas Calientes\n 2. Bebidas Frias\n 3. Snacks\n 4. Salir\n");
                printf("Que desea cambiar?: ");
                scanf("%d", &cambio);
                cambiarMenu(cambio);
                break;
            case 2:
                mostrarUsuarios();
                printf("Desea realizar cambios?\n");
                printf("Digite 1 para afirmar: ");
                scanf("%d", &cambio);
                if (cambio == 1) {
                    eliminarUsuario();
                } else {
                    return;
                }
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Ingrese una opcion valida\n");
        }
    } while (opcion != 3);
}

void mostrarUsuarios() {
    char usuario[20], contrasena[20];
    float saldo;
    int indice = 0;

    FILE *archivo = fopen("usuarios.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de usuarios\n");
        return;
    }
    printf("Usuarios registrados:\n");
    while (fscanf(archivo, "%s %s %f", usuario, contrasena, &saldo) != EOF) {
        printf("%d. Usuario: %s, Dinero: %.2f\n", indice, usuario, saldo);
        indice++;
    }

    fclose(archivo);
}

void cambiarMenu(int opcionCambio) {
    int productoSeleccionado;
    char nuevoProducto[50];
    float nuevoPrecio;
    int nuevasCalorias;
    do {
        switch (opcionCambio) {
            case 1:
                mostrarBebidasCalientes();
                printf("Ingrese el numero de la Bebida a cambiar: ");
                scanf("%d", &productoSeleccionado);
                if (productoSeleccionado > 0 && productoSeleccionado <= 5) {
                    printf("Ingrese el nombre de la nueva bebida: ");
                    while (getchar() != '\n'); // Limpiar el buffer
                    fgets(nuevoProducto, sizeof(nuevoProducto), stdin);
                    nuevoProducto[strcspn(nuevoProducto, "\n")] = 0; // Eliminar salto de linea
                    printf("Nombre de la nueva bebida: %s\n", nuevoProducto); // Mensaje de depuracion
                    printf("Ingrese el costo de la nueva bebida: ");
                    scanf("%f", &nuevoPrecio);
                    printf("Costo de la nueva bebida: %.2f\n", nuevoPrecio); // Mensaje de depuración
                    printf("Ingrese las calorias de la nueva bebida: ");
                    scanf("%d", &nuevasCalorias);
                    printf("Calorias de la nueva bebida: %d\n", nuevasCalorias); // Mensaje de depuracion
                    // Actualizar los valores en los arrays
                    strcpy(bebidasCalientes[productoSeleccionado - 1], nuevoProducto);
                    preciosBebidasCalientes[productoSeleccionado - 1] = nuevoPrecio;
                    caloriasBebidasCalientes[productoSeleccionado - 1] = nuevasCalorias;
                    escribirMenuBebidasCalientes(); // Guardar cambios en el archivo
                } else {
                    printf("Opcion no valida\n");
                }
                break;
            case 2:
                mostrarBebidasFrias();
                printf("Ingrese el numero de la Bebida a cambiar: ");
                scanf("%d", &productoSeleccionado);
                if (productoSeleccionado > 0 && productoSeleccionado <= 5) {
                    printf("Ingrese el nombre de la nueva bebida: ");
                    while (getchar() != '\n'); // Limpiar el buffer de entrada
                    fgets(nuevoProducto, sizeof(nuevoProducto), stdin);
                    nuevoProducto[strcspn(nuevoProducto, "\n")] = 0; // Eliminar el salto de linea
                    printf("Nombre de la nueva bebida: %s\n", nuevoProducto); // Mensaje de depuración
                    printf("Ingrese el costo de la nueva bebida: ");
                    scanf("%f", &nuevoPrecio);
                    printf("Costo de la nueva bebida: %.2f\n", nuevoPrecio); // Mensaje de depuración
                    printf("Ingrese las calorias de la nueva bebida: ");
                    scanf("%d", &nuevasCalorias);
                    printf("Calorias de la nueva bebida: %d\n", nuevasCalorias); // Mensaje de depuración
                    // Actualizar los valores en los arrays
                    strcpy(bebidasFrias[productoSeleccionado - 1], nuevoProducto);
                    preciosBebidasFrias[productoSeleccionado - 1] = nuevoPrecio;
                    caloriasBebidasFrias[productoSeleccionado - 1] = nuevasCalorias;
                    escribirMenuBebidasFrias(); // Guardar cambios en el archivo
                } else {
                    printf("Opcion no valida\n");
                }
                break;
            case 3:
                mostrarSnacks();
                printf("Ingrese el numero del snack a cambiar: ");
                scanf("%d", &productoSeleccionado);
                if (productoSeleccionado > 0 && productoSeleccionado <= 5) {
                    printf("Ingrese el nombre del nuevo snack: ");
                    while (getchar() != '\n'); // Limpiar el buffer de entrada
                    fgets(nuevoProducto, sizeof(nuevoProducto), stdin);
                    nuevoProducto[strcspn(nuevoProducto, "\n")] = 0; // Eliminar el salto de linea
                    printf("Nombre del nuevo snack: %s\n", nuevoProducto); // Mensaje de depuración
                    printf("Ingrese el costo del nuevo snack: ");
                    scanf("%f", &nuevoPrecio);
                    printf("Costo del nuevo snack: %.2f\n", nuevoPrecio); // Mensaje de depuración
                    printf("Ingrese las calorias del nuevo snack: ");
                    scanf("%d", &nuevasCalorias);
                    printf("Calorias del nuevo snack: %d\n", nuevasCalorias); // Mensaje de depuración
                    // Actualizar los valores en los arreglos
                    strcpy(snacks[productoSeleccionado - 1], nuevoProducto);
                    preciosSnacks[productoSeleccionado - 1] = nuevoPrecio;
                    caloriasSnacks[productoSeleccionado - 1] = nuevasCalorias;
                    escribirMenuSnacks(); // Guardar cambios en el archivo
                } else {
                    printf("Opcion no valida\n");
                }
                break;
            case 4:
                printf("Regresando...\n");
                return; // Salir del bucle y de la función
            default:
                printf("Ingrese una opcion valida\n");
        }
        printf("Que desea cambiar?: ");
        scanf("%d", &opcionCambio); // Leer la siguiente opción
    } while (opcionCambio != 4);
}

void escribirMenuBebidasCalientes() {
    FILE *archivo = fopen("menu_bebidas_calientes.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de bebidas calientes.\n");
        return;
    }
    for (i = 0; i < 5; i++) {
        fprintf(archivo, "%s %.2f %d\n", bebidasCalientes[i], preciosBebidasCalientes[i], caloriasBebidasCalientes[i]);
    }
    fclose(archivo);
}

void escribirMenuBebidasFrias() {
    FILE *archivo = fopen("menu_bebidas_frias.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de bebidas frias.\n");
        return;
    }
    for (i = 0; i < 5; i++) {
        fprintf(archivo, "%s %.2f %d\n", bebidasFrias[i], preciosBebidasFrias[i], caloriasBebidasFrias[i]);
    }
    fclose(archivo);
}

void escribirMenuSnacks() {
    FILE *archivo = fopen("menu_snacks.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de snacks.\n");
        return;
    }
    for (i = 0; i < 5; i++) {
        fprintf(archivo, "%s %.2f %d\n", snacks[i], preciosSnacks[i], caloriasSnacks[i]);
    }
    fclose(archivo);
}

void eliminarUsuario() {
    FILE *archivo = fopen("usuarios.txt", "r");
    FILE *temporal = fopen("temp.txt", "w+");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    char usuario[20], contrasena[20];
    float saldo;
    printf("Ingrese el nombre de usuario a eliminar: ");
    scanf("%s", usuario);

    char usuarioArchivo[20], contrasenaArchivo[20];
    int usuarioEncontrado = 0;

    while (fscanf(archivo, "%s %s %f", usuarioArchivo, contrasenaArchivo, &saldo) != EOF) { // Copiar usuarios al nuevo archivo
        if (strcmp(usuarioArchivo, usuario) == 0) {
            usuarioEncontrado = 1;
            printf("Usuario %s eliminado con exito.\n", usuario);
            continue; // Omite al usuario
        }
        fprintf(temporal, "%s %s %.2f\n", usuarioArchivo, contrasenaArchivo, saldo);
    }
    if (!usuarioEncontrado) {
        printf("Usuario no encontrado\n");
    }

    fclose(archivo);
    fclose(temporal);
    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");
}

void leerMenuBebidasCalientes() {
    FILE *archivo = fopen("menu_bebidas_calientes.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de bebidas calientes.\n");
        return;
    }
    for (i = 0; i < 5; i++) {
        fscanf(archivo, "%s %f %d", bebidasCalientes[i], &preciosBebidasCalientes[i], &caloriasBebidasCalientes[i]);
    }
    fclose(archivo);
}

void leerMenuBebidasFrias() {
    FILE *archivo = fopen("menu_bebidas_frias.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de bebidas frias.\n");
        return;
    }
    for (i = 0; i < 5; i++) {
        fscanf(archivo, "%s %f %d", bebidasFrias[i], &preciosBebidasFrias[i], &caloriasBebidasFrias[i]);
    }
    fclose(archivo);
}

void leerMenuSnacks() {
    FILE *archivo = fopen("menu_snacks.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de snacks.\n");
        return;
    }
    for (i = 0; i < 5; i++) {
        fscanf(archivo, "%s %f %d", snacks[i], &preciosSnacks[i], &caloriasSnacks[i]);
    }
    fclose(archivo);
}

void contactar() {
    printf("Contactar:\n");
    printf("1. Programador Guadalupe (guadalupe01@gmail.com)\n");
    printf("2. Programador Mario (albertomario1708@gmail.com)\n");
    printf("3. Atencion al cliente (soporte@cafesync.com)\n");
    printf("4. Sucursal Facultad de Ingenieria (+52 55 1234 5678)\n");
    printf("5. Sucursal Facultad de Medicina (+52 55 8765 4321)\n");
}