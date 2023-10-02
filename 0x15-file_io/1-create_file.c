#include "main.h"

/**
 * create_file - Creates a file.
 * @new_filename: A pointer to the name of the file to create.
 * @file_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *new_filename, char *file_content)
{
	int file_descriptor, bytes_written, len = 0;

	if (new_filename == NULL)
		return (-1);

	if (file_content != NULL)
	{
		for (len = 0; file_content[len];)
			len++;
	}

	file_descriptor = open(new_filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	bytes_written = write(file_descriptor, file_content, len);

	if (file_descriptor == -1 || bytes_written == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
