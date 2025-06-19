#ifndef TAREAS_H
#define TAREAS_H

#define MAX_TAREAS 100

typedef struct {
    int id;
    char descripcion[100];
    int completada;
} Tarea;

extern Tarea tareas[MAX_TAREAS];
extern int cantidadTareas;

void mostrarMenu();
void agregarTarea();
void listarTareas();
void marcarTareaComoCompletada();
void eliminarTarea();
void guardarTareasEnArchivo();
void cargarTareasDesdeArchivo();
void editarDescripcionTarea();
void ordenarTareasPorEstado();
void buscarTareasPorPalabraClave();

#endif
