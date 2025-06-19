#define COLOR_RESET   "\033[0m"
#define COLOR_VERDE    "\033[32m"
#define COLOR_AMARILLO  "\033[33m"
#define COLOR_CYAN       "\033[36m"



#include <stdio.h>
#include "tareas.h"

int main() {
    cargarTareasDesdeArchivo();

    int opcion;
    do {
        mostrarMenu();
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: agregarTarea(); break;
            case 2: listarTareas(); break;
            case 3: marcarTareaComoCompletada(); break;
            case 4: eliminarTarea(); break;
            case 5: guardarTareasEnArchivo(); break;
            case 6: editarDescripcionTarea(); break;
            case 7: ordenarTareasPorEstado(); break;
            case 8: buscarTareasPorPalabraClave(); break;
            case 0:
                guardarTareasEnArchivo();
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 0);

    return 0;
}
