#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
    int sock;
    struct sockaddr_in adresse;
    socklen_t longueurAdresse;

    sock = socket(AF_INET, SOCK_STREAM,0);

    if(sock < 0){
        perror("socket");
        exit(-1);
    }
    
    printf("Socket crée avec succes !\n");

    longueurAdresse = sizeof(adresse);

    memset(&adresse, 0x00, longueurAdresse);

    adresse.sin_family = AF_INET;
    
    adresse.sin_port = htons(IPPORT_USERRESERVED);
    printf("Port : %d \n", IPPORT_USERRESERVED);

    inet_aton("127.0.0.1", &adresse.sin_addr);

    if((connect(sock, (struct sockaddr *)&adresse, longueurAdresse)) == -1){
        perror("connect");
        close(sock);
        exit(-1);
    }

    printf("Connexion au serveur reussie\n");

    close(sock);
    return EXIT_SUCCESS;
}