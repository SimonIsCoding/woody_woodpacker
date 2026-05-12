#include "../inc/woody.h"

int	check_ELF64(char *str)
{
	if (str[0] == 0x7f && str[1] == 'E' && str[2] == 'L' && str[3] == 'F' && str[4] == 0x02)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int		fd = open(argv[1], O_RDONLY);
	char	ELF64_verification[64];
	if (fd < 0)
		return (2);
	read(fd, ELF64_verification, 5);
	if (!check_ELF64(ELF64_verification))
		return (3);
	printf("This is an ELF64\n");
	return (0);
}
