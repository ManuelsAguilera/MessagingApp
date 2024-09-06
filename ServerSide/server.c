#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h> // close
#include <string.h> //strings 
#include <stdlib.h> //exit etc...

//wrapper para errores
void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, const char* argv[])
{
	
	int sockFd ;
	
	if ((sockFd = socket(AF_INET,SOCK_STREAM,0)) == -1)
		error("Hubo un error, socket no se pudo generar");

	const char* ip_addr = "127.0.0.1";
	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1024);
	socklen_t len_addr = sizeof(addr);

	inet_pton(AF_INET,ip_addr,&addr.sin_addr.s_addr);


    int clientFd;

    bind(sockFd,(struct sockaddr * ) &addr, len_addr);

    
    listen(sockFd,10);
    
    printf("Escuchando dispositivos\n");

    clientFd = accept(sockFd,(struct sockaddr * ) &addr,&len_addr);
    printf("Se acaba de encontrar un dispositivo\n");

    if (clientFd == -1)
        error("Se recibio un mensaje error");

    
    char buff[256];
    while (strcmp(buff,"stop\n") != 0)
    {
        memset(buff,0,sizeof(buff));

        ssize_t bytes_r = recv(clientFd,buff,sizeof(buff),0);
        if (bytes_r == -1)
            error("Error al recibir mensaje");
        else if (bytes_r == 0)
        {
            printf("Se ha cerrado la conexion\n");
            break;
        }
            
        
        printf("%s",buff);
    }
    
    
    close(sockFd);
    close(clientFd);

    return 0;
}
