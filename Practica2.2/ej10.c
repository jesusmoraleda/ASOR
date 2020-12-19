$cat /porc/locks;


/*1. - El identificador del bloqueo.

2. - Tipo de bloqueo(POSIX si el bloqueo se hizo con fcntl y FLOCK si se creó con flock.)

3. - Modo de bloqueo(ADVISORY o MANDATORY)

		- Advisory: El acceso a los datos está permitido y evita otros bloqueos.

		- Mandatory : El acceso a los datos está denegado mientras esté bloqueado.

4. - Tipo de bloqueo(WRITE o READ), correspondiente a bloqueos compartidos o exclusivos.

		- Write(Exclusivo) : El proceso está escribiendo por lo que no se puede leer ni escribir en el área bloqueada.

		- Read(Compartido) : El proceso está leyendo por lo que el área no puede ser modificada.

5. - PID del proceso que tiene el bloqueo sobre el fichero.

6. - Tres números separados por : , que identifican el fichero bloqueado.

7. - Byte donde comienza el bloqueo en el fichero.

8. - Byte donde acaba el bloqueo del fichero.*/