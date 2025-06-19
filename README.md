# Gestor de Tareas en C

Este proyecto es una aplicación de consola escrita en C para gestionar tareas. Permite agregar, listar, marcar como completadas, eliminar, buscar y ordenar tareas. Las tareas se guardan en un archivo para persistencia.

## Funcionalidades

- Agregar tareas con descripción.
- Listar todas las tareas, mostrando su estado (pendiente o completada).
- Marcar tareas como completadas.
- Editar la descripción de una tarea.
- Eliminar tareas.
- Guardar y cargar tareas desde un archivo.
- Ordenar tareas mostrando primero las pendientes.
- Buscar tareas por palabra clave.

## Cómo usar

1. Clona este repositorio:
   ```bash
   git clone https://github.com/tu_usuario/tu_repositorio.git


Compila el código (ejemplo con gcc):

gcc -o gestor tareas.c funcionalidades.c main.c

Ejecuta el programa:

./gestor

Requisitos
-Compilador de C (como GCC).

-Sistema operativo compatible con consola.

Estructura del proyecto: 
-main.c: Función principal y menú.

-tareas.h: Declaraciones y estructuras.

-funcionalidades.c: Implementación de las funciones para gestionar tareas.

-colores.h: Definición de colores para consola (opcional).

by: zere1sse (este proyecto es de principiante para aprender este lenguaje)
