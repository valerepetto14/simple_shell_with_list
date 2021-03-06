#include "main.h"
/**
 *ContTokens - Function that prints the amount of Tokens
 *@cadena1: Parameter given by the user
 *Return: Cont
 **/

int ContTokens(char *cadena1)
{
	int cont = 0;
	char *token1 = NULL;

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
	char *token = NULL;
	int iter = 0;

	while (env[iter])
	{
		token = strtok(env[iter], "=");
		if(strcmp("PATH", token) == 0)
			return (strtok(NULL, "="));
		iter++;
	}
	return (NULL);
}

/**
 *add_node_end - printea
 *@token: puntero
 *@str: texto
 *Return: size
 **/
list_token *add_node_end(list_token **token, char *str)
{
	list_token *new_node = NULL;
	list_token *aux = *token;

	new_node = calloc(1,sizeof(list_token));
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
	return (array);
}

list_token *llenar_lista(char *path, list_token *lista)
{
	char *token = NULL;
	char *path2 = strdup(path);

	token =	strtok(path2, ":");
	while(token != NULL)	
	{
		add_node_end(&lista, token);
		token = strtok(NULL, ":");
	}
	return (lista);		
}
