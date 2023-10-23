#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: always success.
 */

int main(int argc, char **argv)
{
	run(argc, argv);

	return (0);
}

