#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int mkfifo(const char *filename, mode_t mode);

#define BUFFER_SIZE 20
struct requete_client_serveur {
    pid_t client_pid; //PID du Client

    tube_client = open("client",O_WRONLY);

    char expression[BUFFER_SIZE - 1]; //text de l expression a evaluer.
};

