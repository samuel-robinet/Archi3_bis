#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <unistd.h>




#define PORT 12345
int sock, socket2, lg;
char mess[80];
struct sockaddr_in local; //champs d entete local
struct sockaddr_in distant; //champs d'entete distant

void creer_socket(){
    bzero(&local, sizeof(local));
    local.sin_family=AF_INET;
    local.sin_port=htons(PORT); //convention ordre
    local.sin_addr.s_addr=INADOR_ANY;
    bzero(&(local.sin_zero),8);

    lg= sizeof(struct sockaddr_in);

    //création socket du serveur mode tcp/IP
    sock=socket(AF_INET, SOCK_STREAM,0);
    //nommage de la socket

    bind(sock, (struct sockaddr*) &local, lg);

}

main(){
    creer_socket();
    //ouvrir pour l'ecoute
    listen(sock,10);
    print("je rentre dans la boucle d'attente\n");
    while(1){
        prinf("attente d'un client\n");

        socket2=accept( sock, struct sockaddr*) &distant, &lgdistant);
        write(socket2,"message rcu !",80);
    }
    close(socket2);
}
