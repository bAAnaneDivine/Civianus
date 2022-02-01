#gcc src/main.c -o bin/main -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows

FLAGS = -I include -L lib -lmingw32 -lSDL2main -lSDL2  -mwindows

allcl: clean bin/prog

all: bin/prog

bin/prog: obj/main.o obj/admin_SDL.o obj/fenetre.o obj/menu.o
	gcc obj/main.o obj/admin_SDL.o obj/fenetre.o obj/menu.o -o bin/prog $(FLAGS)

obj/admin_SDL.o: src/admin_SDL.c src/admin_SDL.h src/fenetre.h src/menu.h
	gcc src/admin_SDL.c -c -o obj/admin_SDL.o $(FLAGS)

obj/main.o: src/main.c src/admin_SDL.h src/fenetre.h src/menu.h
	gcc src/main.c -c -o obj/main.o $(FLAGS)


obj/fenetre.o: src/fenetre.c src/admin_SDL.h src/fenetre.h src/menu.h
	gcc src/fenetre.c -c -o obj/fenetre.o $(FLAGS)

obj/menu.o: src/fenetre.c src/admin_SDL.h src/fenetre.h src/menu.h
	gcc src/menu.c -c -o obj/menu.o $(FLAGS)

clean:
	rm obj/*.o
	rm bin/prog
