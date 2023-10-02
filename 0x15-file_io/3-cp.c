#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *output_file);
void close_descriptor(int file_descriptor);

/**
 * allocate_buffer - Allocates 1024 bytes for a buffer.
 * @output_file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *output_file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
	dprintf(STDERR_FILENO,
		"Error: Can't write to %s\n", output_file);
	exit(99);
	}

	return (buffer);
}

/**
 * close_descriptor - Closes file descriptors.
 * @file_desc: The file descriptor to be closed.
 */
void close_descriptor(int file_desc)
{
	int close_status;

	close_status = close(file_desc);

	if (close_status == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_desc);
	exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int source, destination, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	source = open(argv[1], O_RDONLY);
	read_bytes = read(source, buffer, 1024);
	destination = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
	if (source == -1 || read_bytes == -1)
	{
		dprintf(STDERR_FILENO,
		"Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	write_bytes = write(destination, buffer, read_bytes);
	if (destination == -1 || write_bytes == -1)
	{
		dprintf(STDERR_FILENO,
		"Error: Can't write to %s\n", argv[2]);
		free(buffer);
		exit(99);
	}

	read_bytes = read(source, buffer, 1024);
	destination = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(buffer);
	close_descriptor(source);
	close_descriptor(destination);

	return (0);
}
