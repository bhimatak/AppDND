CC = gcc

ProjDir = /home/bhima/AppDND

INC = $(ProjDir)/inc
SRC = $(ProjDir)/src
OBJ = $(ProjDir)/obj
BIN = $(ProjDir)/bin


CFLAGS = -c -g -Wall

LDFLAGS = -o

IFLAGS = -I $(INC)


all: DND

DND: $(OBJ)/main.o $(OBJ)/common.o $(OBJ)/signUp.o $(OBJ)/dnd_services.o $(OBJ)/personal_d.o $(OBJ)/login.o
	$(CC) $(LDFLAGS) $(BIN)/DND $(OBJ)/main.o $(OBJ)/common.o $(OBJ)/signUp.o $(OBJ)/dnd_services.o $(OBJ)/personal_d.o $(OBJ)/login.o

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
	mv main.o $(OBJ)/
	
$(OBJ)/signUp.o: $(SRC)/signUp.c
	$(CC) $(CFLAGS) $(SRC)/signUp.c $(IFLAGS)
	mv signUp.o $(OBJ)/

$(OBJ)/common.o: $(SRC)/common.c
	$(CC) $(CFLAGS) $(SRC)/common.c $(IFLAGS)
	mv common.o $(OBJ)/

$(OBJ)/dnd_services.o: $(SRC)/dnd_services.c
	$(CC) $(CFLAGS) $(SRC)/dnd_services.c $(IFLAGS)
	mv dnd_services.o $(OBJ)/

$(OBJ)/personal_d.o: $(SRC)/personal_d.c
	$(CC) $(CFLAGS) $(SRC)/personal_d.c $(IFLAGS)
	mv personal_d.o $(OBJ)/

$(OBJ)/login.o: $(SRC)/login.c
	$(CC) $(CFLAGS) $(SRC)/login.c $(IFLAGS)
	mv login.o $(OBJ)/


clean:
	rm -f *.out *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
	@echo "Cleaning Done!"
