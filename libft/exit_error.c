#include "libft.h"

/* Function to output an error message and exit the program */
void	exit_error(char *error_message)
{
	ft_putstr_fd(F_RED, STDERR_FILENO);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(F_RESET, STDERR_FILENO);
	ft_putendl_fd(error_message, STDERR_FILENO);
	exit(1);
}
