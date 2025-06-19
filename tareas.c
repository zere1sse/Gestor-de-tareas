#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tareas.h"
#include "colores.h"

Tarea tareas[MAX_TAREAS];
int cantidadTareas = 0;

void mostrarMenu() {
   printf(COLOR_CYAN "\n--- GESTOR DE TAREAS ---\n" COLOR_RESET);
    printf("1. Agregar tarea\n");
    printf("2. Listar tareas\n");
    printf("3. Marcar tarea como completada\n");
    printf("4. Eliminar tarea\n");
    printf("5. Guardar tareas en archivo\n");
    printf("6. Editar descripción de una tarea\n");
    printf("7. Ordenar tareas por estado (pendientes primero)\n");
    printf("8. Buscar tareas por palabra clave\n");
    printf("0. Salir\n");
}

void agregarTarea() {
    if (cantidadTareas >= MAX_TAREAS) {
        printf("No se puede agregar más tareas.\n");
        return;
    }

    printf("Descripción de la tarea: ");
    fgets(tareas[cantidadTareas].descripcion, 100, stdin);
    tareas[cantidadTareas].descripcion[strcspn(tareas[cantidadTareas].descripcion, "\n")] = '\0';

    tareas[cantidadTareas].id = cantidadTareas + 1;
    tareas[cantidadTareas].completada = 0;
    cantidadTareas++;

    printf("Tarea agregada con éxito.\n");
}
void listarTareas() {
    if (cantidadTareas == 0) {
        printf("No hay tareas registradas.\n");
        return;
    }

    printf("\n--- Lista de tareas ---\n");
    for (int i = 0; i < cantidadTareas; i++) {
        const char* color = tareas[i].completada ? COLOR_VERDE : COLOR_AMARILLO;
        printf("%s%d. %s [%s]%s\n", 
               color, 
               tareas[i].id, 
               tareas[i].descripcion,
               tareas[i].completada ? "Completada" : "Pendiente",
               COLOR_RESET);
    }
}

