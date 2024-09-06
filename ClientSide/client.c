#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h> // close
#include <string.h> //strings 
#include <stdlib.h> //exit etc...

//typedefs
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;




//wrapper para errores
void error(char *msg){
    perror(msg);
    exit(1);
}

void sendMsg(int sockFd, char* buff) {
	fgets(buff,256,stdin);
		if (send(sockFd,buff,strlen(buff),0) == -1)
			error("No se enviaron datos");
	memset(buff,0,sizeof(buff));
}


int getSock() //Obtiene un file descriptor para el socket
{
	int sockFd;
	
	if ((sockFd = socket(AF_INET,SOCK_STREAM,0)) == -1)
		error("Hubo un error, socket FD no se pudo generar");
	return sockFd;
}

void getSockAddr(const char* ip_addr, int port, sockaddr_in* addr_in) {
    addr_in->sin_family = AF_INET; // IPv4
    addr_in->sin_port = htons(port); // Puerto
    
    if (inet_pton(AF_INET, ip_addr, &addr_in->sin_addr) <= 0) { // Presentar dirección en formato binario
        error("inet_pton error");
    }
}

int main(int argc, const char* argv[]) {
    int sockFd = getSock();
    sockaddr_in addr;
    getSockAddr("127.0.0.1", 1024, &addr);
	

	if ((connect(sockFd,(sockaddr*) &addr,sizeof(addr))) == -1)
		error("Hubo un error, conexion cancelada");
	

	char buff[256];
	while(strcmp(buff,"stop\n") != 0)
	{
		sendMsg(sockFd, buff);
	}
	

	close(sockFd);
	return  0;
}
