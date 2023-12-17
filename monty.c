#include "monty.h"

int main(int ac, char **av);
/**
 * main - The beginning of monty program that replicates the stack
 * @ac: argument count
 * @av: argument vector for the file being searched
 * Return: success if properly executed
 */
int main(int ac, char **av)
{
	FILE *fd;
	int i, j, line_number;
	unsigned int value;
	char buffer[SIZE], *token = NULL, *copy_token[SIZE];
	stack_t *head = NULL;

	/**
	 * Check if the argument passed is less than
	 * or greater than 2
	 */
	if (ac != 2)
		failed_prog();
	/**
	 * Since the arguments is one then open the file using
	 * fopen() and check if it fails.
	 */
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	/* Reads content inside of the file using fgets*/
	while (fgets(buffer, SIZE, fd) != NULL)
	{
		/**
		 * tokenize the strings read inside of the file
		 */
		i = 0;
		/*copy_token[i] = NULL; */
		token = strtok(buffer, " \n\t");
		while (token != NULL)
		{
			copy_token[i] = malloc(strlen(token) + 1);
			if (copy_token[i] == NULL)
				malloc_failed();
			strcpy(copy_token[i], token);
			token = strtok(NULL, " \n\t");
			i++;
		}
		copy_token[i] = NULL;
		/**
		 * using a for loop to check if a word matches with the
		 * push or pull keyword but its not yet implementing.
		 */
		value = 0, line_number = 0;
		if (copy_token[0] == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(*copy_token);
			exit(EXIT_FAILURE);
		}
		for (j = 0, line_number = 1; copy_token[j] != NULL; j++)
		{
			value = 0;
			if (strcmp(copy_token[j], "push") == 0)
			{
				if (copy_token[j + 1] == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free(*copy_token);
					exit(EXIT_FAILURE);
				}
				value = atoi(copy_token[j + 1]);
				push(&head, value);
			}
			else if (strcmp(copy_token[j], "pall") == 0)
				pall(&head, value);
			else if (strcmp(copy_token[j], "pint") == 0)
				pint(&head, line_number);
			else if (strcmp(copy_token[j], "pop") == 0)
				pop(&head, line_number);
			else if (strcmp(copy_token[j], "add") == 0)
				add(&head, line_number);
			else if (strcmp(copy_token[j], "swap") == 0)
				swap(&head, line_number);
			else if (strcmp(copy_token[j], "nop") == 0)
				continue;
		}
	}
	/**
	 * Close the file when done to free the
	 * memory or close the file using fclose()
	 */
	fclose(fd);
	free_all(&head);
	free(*copy_token);
	return (0);
}
