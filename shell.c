#include "shell.h"

/**
 *command_in_path - Buscar comando (input) en PATH
 *Return: ruta del comando encontrado
 *@command: comando ingresado por el usuario
 */

char *command_in_path(char *command, char *environ[])
{
	char *dir = NULL, *path = NULL, *path_aux = NULL;
	static char path_env[1024];
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5; /*Ignorar el "PATH=" (+5)*/
			break;
		}
		i++;
	}

	path_aux = strdup(path); /*duplico para modificar*/
	dir = strtok(path_aux, ":");

	while (dir != NULL)
	{
		/*Concateno dir con el nombre del comando, todo en path_env*/
		snprintf(path_env, sizeof(path_env), "%s/%s", dir, command);

		if (access(path_env, X_OK) == 0) /*Me fijo si es ejecutable, true = 0*/
		{
			free(path_aux);
			return (path_env);	
		}
		dir = strtok(NULL, ":"); /*continuo con los demas comandos*/
	}

	free(path_aux);	
	return (NULL);
}

int main(int argc, char *argv[], char *env[])
{
	char *linea, *command;
	size_t len; /*Getline recibe un size_t*/
	ssize_t read;
	char *argu[100]; /*Array para almacenar el comando y argumentos*/
	pid_t pid;
	int status, i, error, count = 0;

	(void)argc;
	len = 0;
	linea = NULL;

	while (1) /*Se sale del bucle con exit*/
	{
		count++;
		if (isatty(STDIN_FILENO))
			printf("CashelljeroFino$ "); /*mostrar prompt*/

		read = getline(&linea, &len, stdin); /*leer input*/
	
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		/*Borrar el salto de linea*/
		linea[strcspn(linea, "\n")] = 0;

		/*Separar la linea de comando y argumentos usando strtok*/
		i = 0;
		argu[i] = strtok(linea, " ");

		while (argu[i] != NULL)
		{
			i++;
			argu[i] = strtok(NULL, " ");
		}

		if (argu[0] == NULL)
			continue; /*Si la linea estaba vacia, mostrar el prompt de nuevo*/

		if (strcmp(argu[0], "exit") == 0)
		{
			break;
		}

		command = argu[0];

		if (access(command, X_OK) != 0)
		{
			command = command_in_path(argu[0], env);

			if (command == NULL)
			{
				fprintf(stderr, "%s: %d: %s: not found\n", argv[0], count, argu[0]);
				status = 127;
				printf("%d", status);
				continue;	
			}
		}

		pid = fork();

		if (pid == 0)
		{
			/*Proceso hijo*/
			if (execve(command, argu, env) == -1)
			{
				printf("%s: %d: %s: %s:", argv[0], count, argu[0], strerror(errno));
				exit(127);
			}
		}

		else if (pid > 0)
		{
			/*Proceso padre*/
			waitpid(pid, &status, 0);

			if (WIFEXITED(status))
			{
				error = WEXITSTATUS(status);
				
				if (error != 0)
				{
					fprintf(stderr, "%s: %d: %s: status %d\n", argv[0], count, argu[0], error);
					status = error;
					printf("%d", status);
				}
			}
		}

		else
		{
			/*Error en fork*/
			perror("fork");
		}
	}

	free(linea);
	return 0;
}
