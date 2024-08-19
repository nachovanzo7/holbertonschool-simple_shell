#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *command_in_path - Buscar comando (input) en PATH
 *Return: ruta del comando encontrado
 *@command: comando ingresado por el usuario
 */

char *command_in_path(char *command)
{
	char *dir, *path, *path_aux;
	static char path_env[1024];

	path = getenv("PATH");
	path_aux = strdup(path); /*duplico para modificar*/
	dir = strtok(path_aux, ":");

	while (dir != NULL)
	{
		/*Concateno dir con el nombre del comando, todo en path_env*/
		snprintf(path_env, sizeof(pathenv), "%s/%s", dir, command);

		if (access(path_env, X_OK) == 0) /*Me fijo si es ejecutable, true = 0*/
		{
			free(path_aux);
			return (path_env);
		}
		dir = strtok(NULL, ";"); /*continuo con los demas comandos*/
	}

	free(path_aux);
	return (NULL);
}
