#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declaracion de funciones
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
void actualizarUsuario(char *usuario);
void cambiarMenu(int numeroCambio);
int usuarioDisponible(char usuarioVerificar[]);
int verificarUsuario(char *usuario, char *contrasena);
int verificarCuentaUNAM(char *cuenta);
int verificarAdmin(char *usuario, char *contrasena);
void modificarPromociones();

// Variables globales
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
int carritoCantidad = 0;
float total=0.0, dinero;
float dineroInicial=250.00;
char usuario[20];
int i, j;

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
        printf("5. Salir\n");
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
                printf("Saliendo al menu principal...\n");
                break;
            default:
                printf("Ingrese una opcion valida\n");
        }
    } while(opcion != 5);
}

void mostrarBebidasCalientes() {
    printf("Menu de Bebidas Calientes:\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f - %d calorias\n", i + 1, bebidasCalientes[i], preciosBebidasCalientes[i], caloriasBebidasCalientes[i]);
    }
}

void personalizarBebidaCaliente(int seleccion) {
    if (seleccion > 0 && seleccion <= 5) {
        printf("Tipo de leche \n1: Entera \n2: Deslactosada \n3: Almendra \n4: Coco\n Seleccione uno: ");
        int tipoLeche;
        scanf("%d", &tipoLeche);
        printf("Desea agregar azucar? (1: Si, 0: No): ");
        int azucar;
        scanf("%d", &azucar);
        printf("Desea agregar crema? (1: Si, 0: No): ");
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
    for (i = 0; i < 5; i++) {
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

    // Descuento adicional para estudiantes de la UNAM
    char cuentaUNAM[10];
    int descuento;
    printf("Forma parte de la comunidad UNAM?\n");
    printf("Digite 1 si la respuesta es afirmativa\n");
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
    // Verificar que la cuenta tenga exactamente 9 digitos
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
            return 0; // Usuario ya existe
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
            dinero = saldoArchivo; // Asignar el saldo a la variable global
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
        // Actualizar datos del usuario en el archivo
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
    FILE *archivo = fopen("admins.txt", "a+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de administradores.\n");
        return;
    }
    fprintf(archivo, "%s %s\n", "Mario", "Marioh17$");
    fprintf(archivo, "%s %s\n", "Guadalupe", "N0l0s3");
    fclose(archivo);
}

int verificarAdmin(char* usuario, char* contrasena) {
    FILE *archivo = fopen("usuarios.txt", "r");
    char usuarioArchivo[20], contrasenaArchivo[20];

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de usuarios\n");
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
        printf("3. Modificar Promociones\n");
        printf("4. Salir\n");
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
                modificarPromociones();
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Ingrese una opcion valida\n");
                break;
        }
    } while (opcion != 4);
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
                    while (getchar() != '\n'); // Limpiar el buffer de entrada
                    fgets(nuevoProducto, sizeof(nuevoProducto), stdin);
                    nuevoProducto[strcspn(nuevoProducto, "\n")] = 0; // Eliminar el salto de linea
                    printf("Ingrese el costo de la nueva bebida: ");
                    scanf("%f", &nuevoPrecio);
                    printf("Ingrese las calorias de la nueva bebida: ");
                    scanf("%d", &nuevasCalorias);
                    // Actualizar los valores en los arrays
                    strcpy(bebidasCalientes[productoSeleccionado - 1], nuevoProducto);
                    preciosBebidasCalientes[productoSeleccionado - 1] = nuevoPrecio;
                    caloriasBebidasCalientes[productoSeleccionado - 1] = nuevasCalorias;
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
                    printf("Ingrese el costo de la nueva bebida: ");
                    scanf("%f", &nuevoPrecio);
                    printf("Ingrese las calorias de la nueva bebida: ");
                    scanf("%d", &nuevasCalorias);
                    // Actualizar los valores en los arrays
                    strcpy(bebidasFrias[productoSeleccionado - 1], nuevoProducto);
                    preciosBebidasFrias[productoSeleccionado - 1] = nuevoPrecio;
                    caloriasBebidasFrias[productoSeleccionado - 1] = nuevasCalorias;
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
                    printf("Ingrese el costo del nuevo snack: ");
                    scanf("%f", &nuevoPrecio);
                    printf("Ingrese las calorias del nuevo snack: ");
                    scanf("%d", &nuevasCalorias);
                    // Actualizar los valores en los arrays
                    strcpy(snacks[productoSeleccionado - 1], nuevoProducto);
                    preciosSnacks[productoSeleccionado - 1] = nuevoPrecio;
                    caloriasSnacks[productoSeleccionado - 1] = nuevasCalorias;
                } else {
                    printf("Opcion no valida\n");
                }
                break;
            case 4:
                printf("Regresando...\n");
                break;
            default:
                printf("Ingrese una opcion valida\n");
        }
    } while (opcionCambio != 4);
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

void modificarPromociones() {
    printf("Modificar Promociones:\n");
    printf("1. Descuento por semana de examenes\n");
    printf("2. Descuento por ser de la UNAM\n");
    printf("3. Descuento por combo desayuno\n");
    printf("4. Salir\n");
    int opcion;
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            printf("Ingrese el nuevo porcentaje de descuento por semana de examenes: ");
            float descuentoExamenes;
            scanf("%f", &descuentoExamenes);
            // Aqui puedes guardar el nuevo descuento en una variable global o archivo
            printf("Descuento por semana de examenes actualizado a %.2f%%\n", descuentoExamenes);
            break;
        case 2:
            printf("Ingrese el nuevo porcentaje de descuento por ser de la UNAM: ");
            float descuentoUNAM;
            scanf("%f", &descuentoUNAM);
            // Aqui puedes guardar el nuevo descuento en una variable global o archivo
            printf("Descuento por ser de la UNAM actualizado a %.2f%%\n", descuentoUNAM);
            break;
        case 3:
            printf("Ingrese el nuevo porcentaje de descuento por combo desayuno: ");
            float descuentoDesayuno;
            scanf("%f", &descuentoDesayuno);
            // Aqui puedes guardar el nuevo descuento en una variable global o archivo
            printf("Descuento por combo desayuno actualizado a %.2f%%\n", descuentoDesayuno);
            break;
        case 4:
            printf("Regresando...\n");
            break;
        default:
            printf("Ingrese una opcion valida\n");
    }
}