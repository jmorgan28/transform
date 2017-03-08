#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"


/*======== void parse_file () ==========
Inputs:   char * filename 
          struct matrix * transform, 
          struct matrix * pm,
          screen s
Returns: 
Goes through the file named filename and performs all of the actions listed in that file.
The file follows the following format:
     Every command is a single character that takes up a line
     Any command that requires arguments must have those arguments in the second line.
     The commands are as follows:
         line: add a line to the edge matrix - 
	    takes 6 arguemnts (x0, y0, z0, x1, y1, z1)
	 ident: set the transform matrix to the identity matrix - 
	 scale: create a scale matrix, 
	    then multiply the transform matrix by the scale matrix - 
	    takes 3 arguments (sx, sy, sz)
	 translate: create a translation matrix, 
	    then multiply the transform matrix by the translation matrix - 
	    takes 3 arguments (tx, ty, tz)
	 rotate: create an rotation matrix,
	    then multiply the transform matrix by the rotation matrix -
	    takes 2 arguments (axis, theta) axis should be x y or z
	 apply: apply the current transformation matrix to the 
	    edge matrix
	 display: draw the lines of the edge matrix to the screen
	    display the screen
	 save: draw the lines of the edge matrix to the screen
	    save the screen to a file -
	    takes 1 argument (file name)
	 quit: end parsing
See the file script for an example of the file format
IMPORTANT MATH NOTE:
the trig functions int math.h use radian mesure, but us normal
humans use degrees, so the file will contain degrees for rotations,
be sure to conver those degrees to radians (M_PI is the constant
for PI)
====================*/
void parse_file ( char * filename, 
                  struct matrix * transform, 
                  struct matrix * edges,
                  screen s) {
  
  FILE *f;
  char line[256];
  clear_screen(s);
  if ( strcmp(filename, "stdin") == 0 ) 
    f = stdin;
  else
    f = fopen(filename, "r");


  int prev = 0;

  while ( fgets(line, 255, f) != NULL ) {
    printf("this: %d\n", prev);
    line[strlen(line)-1]='\0';
    //printf(":%s:\n",line);
    if(strcmp("line", line) == 0)
      prev = 1;
    if(strcmp("ident", line) ==0)
      prev = 2;
    if(strcmp("scale", line) ==0)
      prev = 3;
    if(strcmp("translate", line)== 0)
      prev = 4;
    if(strcmp("rotate", line) == 0)
      prev = 5;
    if(strcmp("apply", line) == 0)
      prev = 6;
    if(strcmp("display", line) == 0)
      prev = 7;
    if(strcmp("save", line) == 0)
      prev = 8;
    if(strcmp("quit", line) == 0)
      prev = 9;
    if(prev == 1){
      char * a = line;
      printf("value: %s\n", strsep(&a, " "));
      printf("you got this\n");
    }
  }
}
  
