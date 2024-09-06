# Nombre de los ejecutables
CLIENT_EXEC = client
SERVER_EXEC = server
BOTH_EXEC = both
MAIN_EXEC= main
# Archivos fuente
CLIENT_SRC = ClientSide/client.c
SERVER_SRC = ServerSide/server.c
MAIN_SRC = main.cpp
# Compilador y banderas de compilación
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Reglas de compilación
all: $(CLIENT_EXEC) $(SERVER_EXEC)

$(CLIENT_EXEC): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT_EXEC) $(CLIENT_SRC)

$(SERVER_EXEC): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER_EXEC) $(SERVER_SRC)

$(BOTH_EXEC): $(SERVER_SRC) $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(SERVER_EXEC) $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT_EXEC) $(CLIENT_SRC)


# Limpiar archivos compilados
clean:
	rm -f $(CLIENT_EXEC) $(SERVER_EXEC)

# Limpiar y recompilar todo
rebuild: clean all

.PHONY: all clean rebuild
