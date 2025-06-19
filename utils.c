#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tareas.h"

void marcarTareaComoCompletada() {
    if (cantidadTareas == 0) {
        printf("No hay tareas para marcar.\n");
        return;
    }

    int id;
    printf("Ingresa el ID de la tarea a marcar como completada: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < cantidadTareas; i++) {
        if (tareas[i].id == id) {
            tareas[i].completada = 1;
            printf("Tarea marcada como completada.\n");
            return;
        }
    }

    printf("No se encontró una tarea con ese ID.\n");
}

void eliminarTarea() {
    if (cantidadTareas == 0) {
        printf("No hay tareas para eliminar.\n");
        return;
    }

    int id;
    printf("Ingresa el ID de la tarea a eliminar: ");
    scanf("%d", &id);
    getchar();

    int index = -1;
    for (int i = 0; i < cantidadTareas; i++) {
        if (tareas[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No se encontró una tarea con ese ID.\n");
        return;
    }

    for (int i = index; i < cantidadTareas - 1; i++) {
        tareas[i] = tareas[i + 1];
        tareas[i].id = i + 1;
    }

    cantidadTareas--;
    printf("Tarea eliminada con éxito.\n");
}

void guardarTareasEnArchivo() {
    FILE *archivo = fopen("tareas.txt", "w");
    if (!archivo) {
        printf("Error al abrir el archivo para guardar.\n");
        return;
    }

    for (int i = 0; i < cantidadTareas; i++) {
        fprintf(archivo, "%d|%s|%d\n", tareas[i].id, tareas[i].descripcion, tareas[i].completada);
    }

    fclose(archivo);
    printf("Tareas guardadas con éxito.\n");
}

void cargarTareasDesdeArchivo() {
    FILE *archivo = fopen("tareas.txt", "r");
    if (!archivo) return;

    cantidadTareas = 0;
    char linea[256];

    while (fgets(linea, sizeof(linea), archivo)) {
        char *token = strtok(linea, "|");
        if (!token) continue;
        tareas[cantidadTareas].id = atoi(token);

        token = strtok(NULL, "|");
        if (!token) continue;
        strncpy(tareas[cantidadTareas].descripcion, token, sizeof(tareas[cantidadTareas].descripcion));
        tareas[cantidadTareas].descripcion[strcspn(tareas[cantidadTareas].descripcion, "\n")] = '\0';

        token = strtok(NULL, "|");
        if (!token) continue;
        tareas[cantidadTareas].completada = atoi(token);

        cantidadTareas++;
        if (cantidadTareas >= MAX_TAREAS) break;
    }

    fclose(archivo);
    printf("Tareas cargadas desde archivo.\n");
}

void editarDescripcionTarea() {
    if (cantidadTareas == 0) {
        printf("No hay tareas para editar.\n");
        return;
    }

    int id;
    printf("Ingresa el ID de la tarea que deseas editar: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < cantidadTareas; i++) {
        if (tareas[i].id == id) {
            printf("Descripción actual: %s\n", tareas[i].descripcion);
            printf("Nueva descripción: ");
            fgets(tareas[i].descripcion, sizeof(tareas[i].descripcion), stdin);
            tareas[i].descripcion[strcspn(tareas[i].descripcion, "\n")] = '\0';
            printf("Descripción actualizada correctamente.\n");
            return;
        }
    }

    printf("No se encontró una tarea con ese ID.\n");
}

void ordenarTareasPorEstado() {
    if (cantidadTareas == 0) {
        printf("No hay tareas para ordenar.\n");
        return;
    }

    for (int i = 0; i < cantidadTareas - 1; i++) {
        for (int j = i + 1; j < cantidadTareas; j++) {
            if (tareas[i].completada > tareas[j].completada) {
                Tarea temp = tareas[i];
                tareas[i] = tareas[j];
                tareas[j] = temp;
            }
        }
    }

    for (int i = 0; i < cantidadTareas; i++) {
        tareas[i].id = i + 1;
    }

    printf("Tareas ordenadas por estado.\n");
}

void buscarTareasPorPalabraClave() {
    if (cantidadTareas == 0) {
        printf("No hay tareas para buscar.\n");
        return;
    }

    char palabraClave[100];
    printf("Ingresa la palabra clave: ");
    fgets(palabraClave, sizeof(palabraClave), stdin);
    palabraClave[strcspn(palabraClave, "\n")] = '\0';

    int encontradas = 0;
    for (int i = 0; i < cantidadTareas; i++) {
        if (strstr(tareas[i].descripcion, palabraClave)) {
            printf("%d. %s [%s]\n", tareas[i].id, tareas[i].descripcion,
                   tareas[i].completada ? "Completada" : "Pendiente");
            encontradas++;
        }
    }

    if (!encontradas) {
        printf("No se encontraron tareas que contengan \"%s\".\n", palabraClave);
    }
}
