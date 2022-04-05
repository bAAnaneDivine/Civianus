#define V 5


char * tab[V] = {
  "Stutgart",
  "Hambourg",
  "Berlin",
  "Dortmund",
  "Francfort"
};

typedef struct {char * nom_ville;int x;int y;int  niveau_ville; int  culture;int science;}ville;

typedef struct t_ville t_ville;

struct t_ville{ville * Ville_P; t_ville * succ;};

void test_ville();
