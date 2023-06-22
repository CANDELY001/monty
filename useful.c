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
	ssize_t read_bytes = getline(line, line_length, file);

	if (read_bytes == -1)
	{
		if (feof(file))
			clearerr(file);
		else
			perror("Error: getline failed");
	}

	return read_bytes;
}
/**
 * _isdigit - function that checks for a digit
 * @c: parameter
 * Return: 1 (Success)
 */
/* BY CHARIFA MASBAHI*/
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

