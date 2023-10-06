#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//to include functions like fork(), exec(), read(), write() etc
#include <sys/wait.h> // Include the header for wait()

int main(int argc, char *arg[]) { //argument declared as a variable and pointer
	int pid;//process id
	pid = fork();//fork() is used to create new process
	if (pid < 0) { //pid willbe less then '0' when error occure while creating process id
		printf("fork failed");
		exit(1);
	} else if (pid == 0) {//pid willbe '0' when process id not created
		execlp("whoami", "whoami", NULL);
		/*execlp() replace the current process image with a new process image specified by the given command.
		whoami is program name that we want to execute,
		"ls" is first argument that willbe passed to new program,
		NULL is required to terminate the list of arguments. */
		exit(0);
	} else {
		printf("\nProcess id is  %d\n", getpid());//getpid() retrieve the process ID
		wait(NULL);
		exit(0);
	}
}
