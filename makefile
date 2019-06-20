TARGET = tron
TRASH = config.h.gch mapa.h.gch

all:
	make compilar
	make run
	make clean

compilar: tron.c menu.c menu.h mapa.c mapa.h config.c config.h comandos.c -lcurses
	gcc -o $(TARGET) tron.c menu.c menu.h mapa.c mapa.h config.c config.h comandos.c -lcurses

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET) $(TRASH)
