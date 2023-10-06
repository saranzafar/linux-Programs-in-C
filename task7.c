// The message "pipe no error" is not an error message. It's a custom message printed to indicate that the pipe function call did not encounter an error. The code you provided uses the perror function to print error messages when an error occurs, but it also includes custom messages for when specific operations are successful. In this case, "pipe no error" is just a custom message indicating that the pipe function executed successfully without errors.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MSG_LEN 64

int main()
{
    printf("Start the program.\n");

    int result;
    int fd[2];
    char message[MSG_LEN];
    char recvd_msg[MSG_LEN];

    // Step 3: Read the choice
    int choice;
    printf("Enter your choice (1 for 'strcpy', 2 for 'strcat'): ");
    scanf("%d", &choice);

    result = pipe(fd); // Step 4: Create a piping process using IPC
    if (result < 0)
    {
        perror("pipe");
        // exit(1);
    }

    // Step 5: Assign the variable lengths
    size_t message_len = 0;
    size_t recvd_msg_len = 0;

    if (choice == 1)
    {
        strncpy(message, "Linux World!! ", MSG_LEN); // Step 6: "strcpy" the message
        message_len = strlen(message);
    }
    else if (choice == 2)
    {
        strncpy(message, "Understanding ", MSG_LEN);
        message_len = strlen(message);
    }

    result = write(fd[1], message, message_len);
    if (result < 0)
    {
        perror("write");
        exit(2);
    }

    // Step 7: To join the operation using IPC
    result = read(fd[0], recvd_msg, MSG_LEN);
    if (result < 0)
    {
        perror("read");
        exit(3);
    }

    printf("Received Message: %s\n", recvd_msg);

    printf("Stop the program.\n");

    return 0;
}
