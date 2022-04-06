#include "main.h"
/**
 *ContTokens - Function that prints the amount of Tokens
 *@cadena1: Parameter given by the user
 *Return: Cont
 **/

int ContTokens(char *cadena1)
{
	int cont = 0;
	char *token1;

	token1 = strtok(cadena1, " ");
	while (token1 != NULL)
	{
		token1 = strtok(NULL, " ");
		cont++;
	}
	return (cont);
}

/**
 *find_PATH - Finds the PATH in the enviroment command
 *@env: environ command
 *Return: Ruta, which is the PATH
 **/
char *find_PATH(char **env)
{
	char *ruta = NULL;
	char *token;
	char *copy;
	const char *name = "PATH";
	int iter = 0;

	for (iter = 0; env[iter] != NULL; iter++)
	{
		copy = strdup(env[iter]);
		token = strtok(copy, "=");
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			ruta = token;
		}
	}
	return (ruta);
}

/**
 *add_node_end - printea
 *@token: puntero
 *@str: texto
 *Return: size
 **/
list_token *add_node_end(list_token **token, const char *str)
{
	list_token *new_node;
	list_token *aux = *token;

	new_node = malloc(sizeof(list_token));
	if (new_node == NULL)
		return (NULL);
	
	new_node->token = strcat(strdup(str),"/");
	new_node->next = NULL;

	if (*token == NULL)
	{
		*token = new_node;
		return (new_node);
	}

		while (aux->next != NULL)
		{
		aux = aux->next;
		}
		aux->next = new_node;
		return (new_node);

}
/**
 *cargar - Function that returns the array to execute
 *@cadena: string given by the user
 *@array: array of strings given by the user
 *Return: Array
 **/
char **cargar(char *cadena, char **array)
{
	int iter = 0;
	char *copycadena = NULL;
	int tokens = 0;
	char *token = NULL;

	copycadena = strdup(cadena);
	cadena = strtok(cadena, "\n");
	tokens = ContTokens(copycadena);
	array = calloc(tokens + 1, sizeof(char *));
	token = strtok(cadena, " ");

	while (token != NULL && iter < tokens) /*Lleno el array*/
	{
		array[iter] = token;
		iter++;
		token = strtok(NULL, " ");
	}
	
	array[tokens] = NULL;
	free(copycadena);
	return (array);
}

list_token *llenar_lista(char *path, list_token *lista)
{
	char *token = NULL;

	token =	strtok(path, ":");
	while(token != NULL)	
	{
		add_node_end(&lista, token);
		token = strtok(NULL, ":");
	}
	return (lista);		
}
