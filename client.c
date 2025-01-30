#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Socket erstellen
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Serveradresse konfigurieren
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // IP-Adresse konvertieren
    if (inet_pton(AF_INET, IP, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Verbindung zum Server herstellen
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    printf("Connected to server at %s:%d\n", IP, PORT);

    // Nachricht an den Server senden
    while (1==1)
    {
    char *message;
    printf("/nSend message");
    scanf("%s", message);
    send(sock, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    // Antwort vom Server empfangen
    ssize_t bytes_read = read(sock, buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("Read failed");
    } else {
        printf("Server response: %s\n", buffer);
    }

    // Verbindung schließen
    if (buffer == "END"){
    close(sock);
    printf("Client disconnected\n");

    return 0;
    }
    }
}
