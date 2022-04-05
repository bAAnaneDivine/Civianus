#
#raccourci
#

CFLAGS=
CCLNK=gcc
CCOBJ=gcc -c
LIBMATH=-lm

#gcc src/main.c -o bin/main -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows

FLAGS = -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows
#
#  commande
#

test_click: bin/test_click

test_plateau:	bin/test_plateau

test_jeu:	bin/test_jeu

all: bin/prog

#
#  executable
#

bin/prog: obj/main.o obj/admin_SDL.o obj/menu.o obj/plateau.o obj/jeu.o obj/structure_jeu.o obj/bandeau_action.o obj/mouvement_personnage.o
	$(CCLNK) $(CFLAGS) obj/main.o obj/admin_SDL.o obj/menu.o obj/plateau.o obj/structure_jeu.o obj/jeu.o obj/bandeau_action.o obj/mouvement_personnage.o -o bin/prog $(FLAGS)

bin/test_jeu: obj/test_jeu.o obj/admin_SDL.o obj/menu.o obj/plateau.o obj/jeu.o obj/structure_jeu.o obj/bandeau_action.o obj/mouvement_personnage.o
	gcc obj/test_jeu.o obj/admin_SDL.o obj/menu.o obj/plateau.o obj/structure_jeu.o obj/jeu.o obj/bandeau_action.o obj/mouvement_personnage.o -o bin/test_jeu $(FLAGS)

bin/test_click: obj/test_click.o obj/admin_SDL.o obj/menu.o obj/plateau.o obj/structure_jeu.o
	$(CCLNK) $(CFLAGS) obj/test_click.o obj/admin_SDL.o obj/menu.o obj/plateau.o obj/structure_jeu.o -o bin/test_click $(FLAGS)

bin/test_plateau:  obj/admin_SDL.o obj/menu.o obj/plateau.o obj/test_plateau.o obj/structure_jeu.o
	$(CCLNK) $(CFLAGS) obj/admin_SDL.o obj/menu.o obj/plateau.o obj/test_plateau.o obj/structure_jeu.o -o bin/test_plateau $(FLAGS)

bin/texte: obj/texte.o
	gcc obj/texte.o -o bin/texte $(FLAGS)
#
#objets
#

obj/admin_SDL.o: src/admin_SDL.c src/headers/admin_SDL.h src/headers/menu.h src/headers/plateau.h
	$(CCOBJ) $(CFLAGS) src/admin_SDL.c -o obj/admin_SDL.o $(FLAGS)

obj/main.o: src/main.c src/headers/admin_SDL.h src/headers/menu.h src/headers/plateau.h src/headers/jeu.h
	$(CCOBJ) $(CFLAGS) src/main.c -o obj/main.o $(FLAGS)

obj/menu.o: src/menu.c src/headers/admin_SDL.h src/headers/menu.h src/headers/plateau.h
	$(CCOBJ) $(CFLAGS) src/menu.c -o obj/menu.o $(FLAGS)

obj/plateau.o: src/plateau.c src/headers/admin_SDL.h src/headers/menu.h src/headers/plateau.h
	$(CCOBJ) $(CFLAGS) src/plateau.c -o obj/plateau.o $(FLAGS)

obj/structure_jeu.o: src/fonction_personnage.c src/headers/admin_SDL.h src/headers/menu.h src/headers/plateau.h src/headers/structure_jeu.h
	$(CCOBJ) $(CFLAGS) src/fonction_personnage.c -o obj/structure_jeu.o $(FLAGS)

obj/jeu.o: src/jeu.c src/headers/admin_SDL.h src/headers/menu.h src/headers/plateau.h src/headers/structure_jeu.h src/headers/bandeau_action.h src/headers/mouvement_personnage.h
	$(CCOBJ) $(CFLAGS) src/jeu.c -o obj/jeu.o $(FLAGS)

obj/texte.o: src/texte.c
	gcc src/texte.c -c -o obj/texte.o $(FLAGS)

obj/bandeau_action.o: src/bandeau_action.c src/headers/plateau.h src/headers/structure_jeu.h src/headers/jeu.h src/headers/mouvement_personnage.h
	$(CCOBJ) $(CFLAGS) src/bandeau_action.c -o obj/bandeau_action.o $(FLAGS)

obj/mouvement_personnage.o: src/mouvement_personnage.c src/headers/plateau.h src/headers/structure_jeu.h
	$(CCOBJ) $(CFLAGS) src/mouvement_personnage.c -o obj/mouvement_personnage.o $(FLAGS)

#
#  tests
#
obj/test_click.o: src/tests/test_click.c src/headers/admin_SDL.h src/headers/menu.h src/headers/plateau.h src/headers/structure_jeu.h
	$(CCOBJ) $(CFLAGS) src/tests/test_click.c -o obj/test_click.o $(FLAGS)

obj/test_plateau.o: src/tests/test_plateau.c src/headers/admin_SDL.h src/headers/menu.h src/headers/plateau.h obj/structure_jeu.o
	$(CCOBJ) $(CFLAGS) src/tests/test_plateau.c -o obj/test_plateau.o $(FLAGS)

obj/test_jeu.o: src/tests/test_jeu.c src/headers/admin_SDL.h src/headers/menu.h src/headers/plateau.h src/headers/structure_jeu.h src/headers/jeu.h
	gcc src/tests/test_jeu.c -c -o obj/test_jeu.o $(FLAGS)

clean:
	rm obj/*.o
	rm bin/prog
	rm bin/test_click
	rm bin/test_plateau
