TARGET = trabalhoPDS

all:
	make compilar
	make run
	make clean

compilar: funcoes.h tron.c getch.c menu.c
	gcc -o $(TARGET) menu.c funcoes.c funcoes.h getch.c

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)