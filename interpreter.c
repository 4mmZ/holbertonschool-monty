#include "monty.h"

int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    // Definir la tabla de opcodes y funciones correspondientes
    instruction_t instructions[] = {
        {"push", push_func},
        {"pall", pall_func},
        {NULL, NULL}
    };

    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;

        // Eliminar el caracter '\n' de la línea
        line[strcspn(line, "\n")] = '\0';

        // Obtener el opcode y los argumentos de la línea
        char *opcode = strtok(line, " \n$");

        // Buscar el opcode en la tabla de opcodes y llamar a la función correspondiente
        int i;
        for (i = 0; instructions[i].opcode != NULL; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number);
                break;
            }
        }
        if (instructions[i].opcode == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    // Liberar la memoria utilizada
    fclose(file);
    if (line)
        free(line);
}
