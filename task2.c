#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int fd;
	char str[100];

	// Step 2: Open or create a file for read/write, create if not exists, and truncate if it exists.
	fd = open("file1", O_RDWR | O_CREAT | O_TRUNC, 0666);

	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}

	// Step 3: Read characters using getchar and store in the string array
	printf("Enter text (Press Enter followed by Ctrl+D to finish):\n");
	int i = 0;
	int c;
	while ((c = getchar()) != EOF && i < sizeof(str) - 1)
	{
		str[i++] = c;
	}
	str[i] = '\0';

	// Step 4: Write the string array into the file and close it
	write(fd, str, strlen(str));
	close(fd);

	// Step 5: Open the file for reading, display its content, and close it
	fd = open("file1", O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}

	printf("Contents of file1:\n");
	while ((i = read(fd, str, sizeof(str) - 1)) > 0)
	{
		str[i] = '\0';
		printf("%s", str);
	}
	close(fd);

	// Step 6: Program ends

	return 0;
}
