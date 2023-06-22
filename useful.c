#include "monty.h"
/**
 * _getline - a function google it
 * @line: parameter
 * @line_length: parameter
 * @file: file atrik l9anb
 * Return: WEEKWEEK wa bghit anghawt
 */
ssize_t _getline(char **line, size_t *line_length, FILE *file)
{
	ssize_t read_bytes = 0;
	size_t buffer_size = 0;
	char *new_buffer;
	int c;

	if (line == NULL || line_length == NULL)
		return (-1);
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
	while ((c = fgetc(file)) != EOF)
	{
		if (read_bytes + 1 >= (ssize_t) buffer_size)
		{
			buffer_size += 128;
			new_buffer = realloc(*line, buffer_size);
			if (new_buffer == NULL)
				return (-1);
			*line = new_buffer;
		}
		(*line)[read_bytes++] = c;
		if (c == '\n' || c == '\t' || c == '\r')
			break;
	}
	if (read_bytes + 1 >= (ssize_t) buffer_size)
	{
		buffer_size += 1;
		new_buffer = realloc(*line, buffer_size);
		if (new_buffer == NULL)
		{
			return (-1);
		}
		*line = new_buffer;
	}
	(*line)[read_bytes] = '\0';
	return ((read_bytes > 0) ? read_bytes : -1);
}
/**
 * _isdigit - function that checks for a digit
 * @c: parameter
 * Return: 1 (Success)
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

