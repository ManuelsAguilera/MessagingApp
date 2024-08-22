#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

/***
 * Hacer una aplicacion de mensajeria, que funciona usando varios
 *  dispositivos que se conenctan a un host.
 * 
 * De esta manera se debe hacer una aplicacion SS y CS.
 * 
 * Requerimientos Funcionales:
 * La aplicacion SS, deberia almacenar la direccion ip de aquellos
 * clientes que manden un request.
 * La aplicacion reenvia mensajes asegurandose que no se trate
 * de contenido malicioso, o que quiera vulnerar el sistema.
 * 
 * La aplicacion CS, deberia almacenar solamente la direccion de el server de mensajeria.
 * Esta envia y recibe mensajes.
 * 
 * Requerimientos No Funcionales:
 * 
 * Ser una via segura de mensajeria,
 * Aceptar varios computadores,
 * Ser de facil uso.
 */

int main()
{

    int socketFD = socket(AF_INET,SOCK_STREAM,0);

    printf("Made a new File Descriptor %d",socketFD);
    //connect(socketFD);


    return EXIT_SUCCESS;
}