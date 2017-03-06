#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main(int argc, char **argv) {

  screen s;
  struct matrix * edges;
  struct matrix * transform;

  struct matrix * edges3 =  new_matrix(4, 4);

  
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;


  add_edge(edges3,150,80,0,250,80,0);
  add_edge(edges3,150,80,0,150,280,0);
  add_edge(edges3,250,80,0,250,280,0);
  add_edge(edges3,150,280,0,250,280,0);
  add_edge(edges3,150,280,0,200,330,0);
  add_edge(edges3,250,280,0,200,330,0);
  add_edge(edges3,250,80,0,300,120,0);
  add_edge(edges3,250,280,0,300,320,0);
  add_edge(edges3,300,320,0,300,120,0);
  add_edge(edges3,200,330,0,250,370,0);
  add_edge(edges3,300,320,0,250,370,0);

  matrix_mult(make_rotX(90),edges3);
  draw_lines(edges3,s,c);
  display(s);
 save_extension(s, "matrix.png");

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  print_matrix(make_rotX(30));
  
  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );

  
  free_matrix( edges );
  free_matrix( transform );
}  
