//$umask 022 #Para dejar el valor por defecto.

//umask te devuelve el valor del octal en decimal.

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	mode_t prev = umask(027); // 027

	int file = open("ej6.txt", O_CREAT | O_RDONLY, 0777);

	return 0;
}
