#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char **argv) {


	if (argc < 2) {
		 printf("ERROR: Se debe especeficar la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}

	struct stat buff;

	int statint = stat(argv[1], &buff);

	if (statint == -1) {
		printf("ERROR: No existe el directorio.\n");
		return -1;
	}

	//Major y Minor

	printf("MAJOR: %li\n", (long) minor(buff.st_dev));
	printf("MINOR: %li\n", (long) major(buff.st_dev));

	//I-Node
	printf("I-Node: %li\n",buff.st_ino);

	//Tipo de fichero
	printf("MODE: %i\n",buff.st_mode);

		mode_t mode = buff.st_mode;

	if (S_ISLNK(mode)){
		printf("%s es un enlace simbólico.\n", argv[1]);
	} else if (S_ISREG(mode)) {
		printf("%s es un archivo ordinario.\n", argv[1]);
	} else if (S_ISDIR(mode)) {
		printf("%s es un directorio.\n", argv[1]);
	}

	//Hora ficheros M
	time_t t2 = buff.st_mtime;

	struct tm *tm2= localtime(&t2);

	printf("Últime acceso (M): %d:%d\n", tm2->tm_hour, tm2->tm_min);

	//Hora ficheros C
	time_t t3 = buff.st_ctime;

	struct tm *tm3= localtime(&t3);

	printf("Últime acceso (C): %d:%d\n", tm3->tm_hour, tm3->tm_min);

	return 0;
}
//st_mtime: es la última modifciación dentro del archivo.

//st_ctime: es la última modificación ya sea de permisos, del archivo, de nombre...
