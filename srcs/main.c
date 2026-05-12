#include "../inc/woody.h"

int	check_ELF64(char *str)
{
	if (str[0] == 0x7f && str[1] == 'E' && str[2] == 'L' && str[3] == 'F' && str[4] == 0x02)
	{
		printf("ELF64: _%s_\n", str);
		return (1);
	}
	return (0);
}

//void *mmap(void addr[.length], size_t length, int prot, int flags, int fd, off_t offset);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int		fd = open(argv[1], O_RDWR);
	char	ELF64_verification[64];
	if (fd < 0)
		return (2);
	read(fd, ELF64_verification, 64);
	if (!check_ELF64(ELF64_verification))
		return (3);
	printf("This is an ELF64\n");

	size_t file_size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	unsigned char *ptr = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (ptr == MAP_FAILED)
	{
		perror("mmap");
		exit(1);
	}
	printf("ptr = _%s_\n", ptr);

	Elf64_Ehdr *ehdr = (Elf64_Ehdr *)ptr;
	Elf64_Phdr *phdr = (Elf64_Phdr *)(ptr + ehdr->e_phoff);

	close(fd);
	return (0);
}
