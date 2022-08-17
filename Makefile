NAME = 
SERVER = server
CLIENT = client
SRC_S = server.c
SRC_C = client.c
OBJ_S = $(patsubst %.c, %.o, $(SRC_S))
OBJ_C = $(patsubst %.c, %.o, $(SRC_C))

FLAGS = -Wall -Wextra -Werror
CC = gcc

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_S)
	gcc $(FLAGS) -o $(SERVER) $(OBJ_S)

$(CLIENT): $(OBJ_C)
	gcc $(FLAGS) -o $(CLIENT) $(OBJ_C)

clean:
	rm -rf $(OBJ_S) $(OBJ_C)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all 

.PHONY: all clean fclean re exe
