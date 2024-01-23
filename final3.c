#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};

// Función para limpiar el búfer de entrada (stdin)
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Función para ingresar datos de un alumno
void ingresarDatos(struct alumno *alumno) {
    printf("Ingrese la matricula: ");
    scanf("%d", &alumno->matricula);

    limpiarBuffer(); // Limpia el búfer para evitar problemas con fgets

    printf("Ingrese el nombre: ");
    fgets(alumno->nombre, sizeof(alumno->nombre), stdin);
    alumno->nombre[strcspn(alumno->nombre, "\n")] = '\0'; 

    printf("Ingrese la direccion: ");
    fgets(alumno->direccion, sizeof(alumno->direccion), stdin);
    alumno->direccion[strcspn(alumno->direccion, "\n")] = '\0'; 
    printf("Ingrese la carrera: ");
    fgets(alumno->carrera, sizeof(alumno->carrera), stdin);
    alumno->carrera[strcspn(alumno->carrera, "\n")] = '\0'; 
    printf("Ingrese el promedio: ");
    scanf("%f", &alumno->promedio);
}
//funcion para uaadar los datos 

void guardarDatos(struct alumno *alumno, FILE *archivo)
{
    {
    fprintf(archivo, "%d, %s, %s, %s, %.2f\n", alumno->matricula, alumno->nombre, alumno->direccion, alumno->carrera, alumno->promedio);
}
}



// Función para mostrar los datos de un alumno
void mostrarDatos(struct alumno *alumno) {
    printf("\nMatricula: %d\n", alumno->matricula);
    printf("Nombre: ");
    puts(alumno->nombre); 
    printf("Direccion: ");
    puts(alumno->direccion); 
    printf("Carrera: ");
    puts(alumno->carrera); 
    printf("Promedio: %.2f\n", alumno->promedio);
}




int main() {
    int n;

    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &n);

    struct alumno *alumnos = (struct alumno *)malloc(n * sizeof(struct alumno));

    if (alumnos == NULL) {
        printf("Error de asignacion de memoria.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nIngreso de datos para el alumno %d:\n", i + 1);
        ingresarDatos(&alumnos[i]);
    }
    printf("\nMenu:\n");
    printf("1. Mostrar datos\n");
    printf("2. Guardar datos en archivo\n");//se agrego la opcio de imprimir los archivos
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
    int opcion;
    scanf("%d", &opcion);
    if (opcion == 1)
    {
        printf("\nDatos ingresados para los alumnos:\n");
        for (int i = 0; i < n; i++)
        {
            mostrarDatos(&alumnos[i]);
        }
    }
    else if (opcion == 2)
    {
        FILE *archivo;
        archivo = fopen("Infosave.txt", "w");
        if (archivo == NULL)
        {
            printf("Error al abrir el archivo.\n");
        }
        else
        {
            printf("\nImrpiendo dato en ell archivo \n");
            for (int i = 0; i < n; i++)
            {
                guardarDatos(&alumnos[i], archivo);
            }
            fclose(archivo);
            printf("Proceso completado.\n");
        }
    }
    else
    {
        printf("Saliendo del programa.\n");
    }

    free(alumnos);
    return 0;
}