CC = gcc
OBJS = functionMat.o Main.o numGame.o picMan.o
EXEC = prog
EXEC: $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)
	
	
clean:
	rm -f $(OBJS) $(EXEC)

functionMat.o: functionMat.c functionMat.h picMan.h
Main.o: Main.c picMan.h numGame.h
numGame.o: numGame.c numGame.h functionMat.h
picMan.o: picMan.c picMan.h functionMat.h

