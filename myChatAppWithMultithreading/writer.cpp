#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstdlib> // For exit()
#include <cstdio>  // For perror()

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
};

int writer() {
    key_t key;
    int msgid;

    // Generate a unique key
    key = ftok("progfile", 65);
    if (key == -1) {
        perror("Error generating key using ftok");
        return 1;
    }

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Error creating message queue");
        return 1;
    }

    mesg_buffer message;
    message.mesg_type = 1;

    std::cout << "Write Data: ";
    std::cin.getline(message.mesg_text, 100);

    // Send the message
    if (msgsnd(msgid, &message, sizeof(message.mesg_text), 0) == -1) {
        perror("Error sending message");
        return 1;
    }

    std::cout << "Data sent is: " << message.mesg_text << std::endl;
    return 0;

   
}
