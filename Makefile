#gcc src/main.c -o bin/main -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows

FLAGS = -I include -L lib -lmingw32 -lSDL2main -lSDL2  -mwindows

allcl: clean bin/prog

all: bin/prog

test: bin/test_menu_select

bin/prog: obj/main.o obj/admin_SDL.o  obj/menu.o 
	gcc obj/main.o obj/admin_SDL.o obj/menu.o -o bin/prog $(FLAGS)
 
obj/admin_SDL.o: src/admin_SDL.c hd/admin_SDL.h  
	gcc src/admin_SDL.c -c -o obj/admin_SDL.o $(FLAGS)

obj/main.o: src/main.c hd/admin_SDL.h hd/menu.h
	gcc src/main.c -c -o obj/main.o $(FLAGS)

obj/menu.o: src/menu.c hd/admin_SDL.h hd/menu.h 
	gcc src/menu.c -c -o obj/menu.o $(FLAGS)

obj/test_menu_select.o: src/test_menu_select.c hd/admin_SDL.h hd/menu.h 
	gcc src/test_menu_select.c -c -o obj/test_menu_select.o $(FLAGS)




clean:
	rm obj/*.o
	rm bin/prog
	rm bin/test_menu_select
	




#----------test------------

bin/test_menu_select: obj/test_menu_select.o obj/admin_SDL.o  obj/menu.o 
	gcc obj/test_menu_select.o obj/admin_SDL.o obj/menu.o -o bin/test_menu_select $(FLAGS)