#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Socket erstellen
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Serveradresse konfigurieren
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(IP); // IP-Adresse
    address.sin_port = htons(PORT);         // Port

    // Socket an die IP und den Port binden
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Auf eingehende Verbindungen warten
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on %s:%d\n", IP, PORT);

    // Verbindung akzeptieren
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    // Daten vom Client empfangen
    ssize_t bytes_read = read(new_socket, buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("Read failed");
    } else {
        printf("Received message: %s\n", buffer);
    }

    // Antwort an den Client senden
    const char *response = "Message received!";
    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client\n");

    // Verbindung schließen
    close(new_socket);
    close(server_fd);
    printf("Server closed\n");

    return 0;
}