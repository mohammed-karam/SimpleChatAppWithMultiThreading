#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring> // For memset

// Structure for the message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
};

int reader() {
    key_t key;
    int msgid;

    // Generate a unique key
    key = ftok("progfile", 65);
    if (key == -1) {
        std::cerr << "Error generating key!" << std::endl;
        return 1;
    }

    // Access or create the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        std::cerr << "Error accessing message queue!" << std::endl;
        return 1;
    }

    mesg_buffer message;

    // Receive the message
    if (msgrcv(msgid, &message, sizeof(message.mesg_text), 1, 0) == -1) {
        std::cerr << "Error receiving message!" << std::endl;
        return 1;
    }

    // Display the received message
    std::cout << "Data Received is: " << message.mesg_text << std::endl;

    // Destroy the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        std::cerr << "Error deleting message queue!" << std::endl;
        return 1;
    }

    return 0;
}
