#include "monty.h"


void
free_stack(stack_t **stack)
{
	stack_t *aux = *stack;

	if (*stack == NULL)
	{
	return;
	}
	while (*stack)
	{
	aux = (*stack)->next;
	free(*stack);
	*stack = aux;
	}
}


int
is_int(char *s)
{
	int i = 0;

	if (s == NULL)
	return (0);

	if (s[0] == '-' || s[0] == '+')
	i = 1;

	for (; s[i] != '\0'; i++)
	{
	if (s[i] < '0' || s[i] > '9')
	return (0);
	}

	return (1);
}

char
*trim(char *str)
{
	char *end;

	/* Eliminar los espacios en blanco al principio */
	while (isspace((unsigned char)*str))
	str++;

	/* Si la cadena está vacía, devolver una cadena vacía */
	if (*str == 0)
	return (str);

	/* Eliminar los espacios en blanco al final */
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;

	/* Agregar el carácter nulo al final */
	*(end + 1) = 0;

	return (str);
}
