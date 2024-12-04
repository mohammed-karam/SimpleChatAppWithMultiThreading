
# Simple Chat App with MultiThreading and IPC using Message Queue in C++

[Screencast from 04 ديس, 2024 EET 09:08:29 م.webm](https://github.com/user-attachments/assets/1c9db0d6-9dcb-48e5-9118-ac2aa6ad9046)

This project demonstrates a simple chat application implemented in C++ using **multi-threading** and **Inter-Process Communication (IPC)** with **message queues**. The application allows communication between threads using message queues to simulate a chat between a writer and a reader.

## Features:
- **Multithreading**: The application uses threads to handle writing and reading operations concurrently.
- **IPC (Message Queue)**: Uses System V message queues for communication between the writer and reader threads.
- **Synchronization**: A mutex is used to synchronize access to shared resources.

## Files:
### 1. `writer.cpp`
This file contains the implementation of the `writer()` function. It allows the user to write data, which is then sent to the message queue for the reader to retrieve.

### 2. `reader.cpp`
This file contains the implementation of the `reader()` function. It reads the data from the message queue and displays it to the user.

### 3. `header.h`
This header file declares the `writer()` and `reader()` functions, providing the interface for the main program to call these functions.

### 4. `main.cpp`
This file is the entry point of the program. It creates two threads—one for the writer and one for the reader. Both threads communicate using the message queue, and synchronization is handled with a mutex.

## How It Works:
- The **writer** thread asks the user to input a message and sends it to the message queue.
- The **reader** thread reads messages from the message queue and prints them to the screen.
- Threads are synchronized using a mutex to ensure safe access to shared resources.

## Compilation:
To compile the program, run the following command:

```bash
g++ mai.cpp writer.cpp reader.cpp -o chat_app
```
## Run:
To compile the program, run the following command:

```bash
./chat_app
```

