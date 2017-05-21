
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

int max = 15;

int m[15][15];
int m2[15][15];
int points = 0;

typedef struct node{
	int rot;
	int type;
	int x[4];
	int y[4];
} node;

node *tet;

void type(node *n){
	if(n -> type == 0){
		n -> x[0] = 4;
		n -> y[0] = -1;	

		n -> x[1] = 5;
		n -> y[1] = -1;	

		n -> x[2] = 5;
		n -> y[2] = 0;	

		n -> x[3] = 6;
		n -> y[3] = 0;	
	}else if(n -> type == 1){

		n -> x[0] = 5;
		n -> y[0] = 0;	

		n -> x[1] = 6;
		n -> y[1] = 0;	

		n -> x[2] = 5;
		n -> y[2] = -1;	

		n -> x[3] = 6;
		n -> y[3] = -1;		
	}else if(n -> type == 2){

		n -> x[0] = 5;
		n -> y[0] = 0;	

		n -> x[1] = 5;
		n -> y[1] = -1;	

		n -> x[2] = 5;
		n -> y[2] = -2;	

		n -> x[3] = 6;
		n -> y[3] = -2;		
	}else if(n -> type == 3){

		n -> x[0] = 5;
		n -> y[0] = 0;	

		n -> x[1] = 5;
		n -> y[1] = -1;	

		n -> x[2] = 5;
		n -> y[2] = -2;	

		n -> x[3] = 5;
		n -> y[3] = -3;		
	}else if(n -> type == 4){

		n -> x[0] = 4;
		n -> y[0] = 0;	

		n -> x[1] = 5;
		n -> y[1] = 0;	

		n -> x[2] = 5;
		n -> y[2] = -1;	

		n -> x[3] = 6;
		n -> y[3] = -1;		
	}else if(n -> type == 5){

		n -> x[0] = 5;
		n -> y[0] = 0;	

		n -> x[1] = 5;
		n -> y[1] = -1;	

		n -> x[2] = 5;
		n -> y[2] = -2;	

		n -> x[3] = 4;
		n -> y[3] = -2;		
	}
}
void rotate(node *n){
	if(n -> type == 0){
		if(n -> rot == 0){
			if(m2[n -> y[0] - 1][n -> x[0]] != 1 && m2[n -> y[0] - 1][n -> x[0] + 1] != 1 && m2[n -> y[0] - 2][n -> x[0] + 1] != 1){
			if(n -> y[0] - 1 < max && n -> x[0] + 1 < max && n -> y[0] - 2 < max){
			if(n -> y[0] - 1 >= 0  && n -> x[0] + 1 >= 0  && n -> y[0] - 2 >= 0 ){
				n -> rot = 1;
				n -> x[1] = n -> x[0];
				n -> y[1] = n -> y[0] - 1;	

				n -> x[2] = n -> x[0] + 1;
				n -> y[2] = n -> y[0] - 1;	

				n -> x[3] = n -> x[0] + 1;
				n -> y[3] = n -> y[0] - 2;
			}
			}
			}
		}else{
			if(m2[n -> y[0]][n -> x[0] - 1] != 1 && m2[n-> y[0] - 1][n -> x[0] - 1] != 1 && m2[n -> y[0] - 1][n -> x[0] - 2] != 1){
			if(n -> x[0] - 1 < max && n-> y[0] - 1 < max && n -> x[0] - 2 < max){
			if(n -> x[0] - 1 >= 0  && n-> y[0] - 1 >= 0  && n -> x[0] - 2 >= 0 ){
				n -> rot = 0;
				n -> x[1] = n -> x[0] - 1;
				n -> y[1] = n -> y[0];	

				n -> x[2] = n -> x[0] - 1;
				n -> y[2] = n -> y[0] - 1;	

				n -> x[3] = n -> x[0] - 2;
				n -> y[3] = n -> y[0] - 1;
			}
			}
			}
		}	
	}else if(n -> type == 2){
		if(n -> rot == 0){
			if(m2[n -> y[0]][n -> x[0] - 1] != 1 && m2[n -> y[0]][n -> x[0] - 2] != 1 && m2[n -> y[0] - 1][n -> x[0] - 2] != 1){
			if(n -> y[0] - 1 < max && n -> x[0] - 1 < max && n -> x[0] - 2 < max){
			if(n -> y[0] - 1 >= 0  && n -> x[0] - 1 >= 1  && n -> x[0] - 2 >= 1 ){
				n -> rot = 1;
				n -> x[1] = n -> x[0] - 1;
				n -> y[1] = n -> y[0];	

				n -> x[2] = n -> x[0] - 2;
				n -> y[2] = n -> y[0];	

				n -> x[3] = n -> x[0] - 2;
				n -> y[3] = n -> y[0] - 1;
			}
			}
			}
		}else if(n -> rot == 1){
			if(m2[n -> y[0]][n -> x[0] - 1] != 1 && m2[n -> y[0] - 1][n -> x[0]] != 1 && m2[n -> y[0] - 2][n -> x[0]] != 1){
			if(n -> y[0] - 1 < max && n -> y[0] - 2 < max && n -> x[0] - 1 < max){
			if(n -> y[0] - 1 >= 0  && n -> y[0] - 2 >= 0  && n -> x[0] - 1 >= 0 ){
				n -> rot = 2;
				n -> x[1] = n -> x[0] - 1;
				n -> y[1] = n -> y[0];	

				n -> x[2] = n -> x[0];
				n -> y[2] = n -> y[0] - 1;	

				n -> x[3] = n -> x[0];
				n -> y[3] = n -> y[0] - 2;
			}
			}
			}
		}else if(n -> rot == 2){
			if(m2[n -> y[0] - 1][n -> x[0]] != 1 && m2[n -> y[0]][n -> x[0] - 1] != 1 && m2[n -> y[0]][n -> x[0] - 2] != 1){
			if(n -> y[0] - 1 < max && n -> x[0] - 1 < max && n -> x[0] - 2 < max){
			if(n -> y[0] - 1 >= 0  && n -> x[0] - 1 >= 0  && n -> x[0] - 2 >= 0){
				n -> rot = 3;
				n -> x[1] = n -> x[0];
				n -> y[1] = n -> y[0] - 1;	

				n -> x[2] = n -> x[0] - 1;
				n -> y[2] = n -> y[0];	

				n -> x[3] = n -> x[0] - 2;
				n -> y[3] = n -> y[0];
			}
			}
			}
		}else if(n -> rot == 3){
			if(m2[n -> y[0] - 1][n -> x[0]] != 1 && m2[n -> y[0] - 2][n -> x[0]] != 1 && m2[n -> y[0] - 2][n -> x[0] + 1] != 1){
			if(n -> y[0] - 1 < max && n -> x[0] + 1 < max && n -> y[0] - 2 < max){
			if(n -> y[0] - 1 >= 0  && n -> x[0] + 1 >= 0  && n -> y[0] - 2 >= 0){
				n -> rot = 0;
				n -> x[1] = n -> x[0];
				n -> y[1] = n -> y[0] - 1;	

				n -> x[2] = n -> x[0];
				n -> y[2] = n -> y[0] - 2;	

				n -> x[3] = n -> x[0] + 1;
				n -> y[3] = n -> y[0] - 2;
			}
			}
			}
		}
	}else if(n -> type == 3){
		if(n -> rot == 0){
			if(m2[n -> y[0]][n -> x[0] - 1] != 1 && m2[n -> y[0]][n -> x[0] + 1] != 1 && m2[n -> y[0]][n -> x[0] + 2] != 1){
			if(n -> x[0] - 1 < max && n -> x[0] + 1 < max && n -> x[0] + 2 < max){
			if(n -> x[0] - 1 >= 0  && n -> x[0] + 1 >= 0  && n -> x[0] + 2 >= 0 ){
			n -> rot = 1;
			n -> x[1] = n -> x[0] - 1;
			n -> y[1] = n -> y[0];	

			n -> x[2] = n -> x[0] + 1;
			n -> y[2] = n -> y[0];	

			n -> x[3] = n -> x[0] + 2;
			n -> y[3] = n -> y[0];
			}
			}
			}
		}else{
			if(m2[n -> y[0] - 1][n -> x[0]] != 1 && m2[n -> y[0] - 2][n -> x[0]] != 1 && m2[n -> y[0] - 3][n -> x[0]] != 1){
			if(n -> y[0] - 1 < max && n -> y[0] - 2 < max && n -> y[0] - 3 < max){
			if(n -> y[0] - 1 >= 0  && n -> y[0] - 2 >= 0  && n -> y[0] - 3 >= 0 ){
			n -> rot = 0;
			n -> x[1] = n -> x[0];
			n -> y[1] = n -> y[0] - 1;	

			n -> x[2] = n -> x[0];
			n -> y[2] = n -> y[0] - 2;	

			n -> x[3] = n -> x[0];
			n -> y[3] = n -> y[0] - 3;
			}
			}
			}
		}
	}else if(n -> type == 4){
		if(n -> rot == 0){
			if(m2[n -> y[0] - 1][n -> x[0]] != 1 && m2[n -> y[0] - 1][n -> x[0] - 1] != 1 && m2[n -> y[0] - 2][n -> x[0] - 1] != 1){
			if(n -> y[0] - 1 < max && n -> x[0] - 1 < max && n -> y[0] - 2 < max){
			if(n -> y[0] - 1 >= 0  && n -> x[0] - 1 >= 0  && n -> y[0] - 2 >= 0 ){
				n -> rot = 1;
				n -> x[1] = n -> x[0];
				n -> y[1] = n -> y[0] - 1;	

				n -> x[2] = n -> x[0] - 1;
				n -> y[2] = n -> y[0] - 1;	

				n -> x[3] = n -> x[0] - 1;
				n -> y[3] = n -> y[0] - 2;
			}
			}
			}
		}else{
			if(m2[n -> y[0]][n -> x[0] + 1] != 1 && m2[n-> y[0] - 1][n -> x[0] + 1] != 1 && m2[n -> y[0] - 1][n -> x[0] + 2] != 1){
			if(n -> x[0] + 1 < max && n-> y[0] - 1 < max && n -> x[0] + 2 < max){
			if(n -> x[0] + 1 >= 0  && n-> y[0] - 1 >= 0  && n -> x[0] + 2 >= 0 ){
				n -> rot = 0;
				n -> x[1] = n -> x[0] + 1;
				n -> y[1] = n -> y[0];	

				n -> x[2] = n -> x[0] + 1;
				n -> y[2] = n -> y[0] - 1;	

				n -> x[3] = n -> x[0] + 2;
				n -> y[3] = n -> y[0] - 1;
			}
			}
			}
		}	
	}else if(n -> type == 5){
		if(n -> rot == 0){
			if(m2[n -> y[0]][n -> x[0] - 1] != 1 && m2[n -> y[0]][n -> x[0] - 2] != 1 && m2[n -> y[0] + 1][n -> x[0] - 2] != 1){
			if(n -> x[0] - 1 < max && n -> x[0] - 2 < max && n -> y[0] + 1 < max){
			if(n -> x[0] - 1 >= 0  && n -> x[0] - 2 >= 0  && n -> y[0] + 1 >= 0 ){
				n -> rot = 1;
				n -> x[1] = n -> x[0] - 1;
				n -> y[1] = n -> y[0];	

				n -> x[2] = n -> x[0] - 2;
				n -> y[2] = n -> y[0];	

				n -> x[3] = n -> x[0] - 2;
				n -> y[3] = n -> y[0] + 1;
			}
			}
			}
		}else if(n -> rot == 1){
			if(m2[n -> y[0]][n -> x[0] + 1] != 1 && m2[n-> y[0] - 1][n -> x[0]] != 1 && m2[n -> y[0] - 2][n -> x[0]] != 1){
			if(n -> x[0] + 1 < max && n -> y[0] - 1 < max && n -> y[0] - 2 < max){
			if(n -> x[0] + 1 >= 0  && n -> y[0] - 1 >= 0  && n -> y[0] - 2 >= 0 ){
				n -> rot = 2;
				n -> x[1] = n -> x[0] + 1;
				n -> y[1] = n -> y[0];	

				n -> x[2] = n -> x[0];
				n -> y[2] = n -> y[0] - 1;	

				n -> x[3] = n -> x[0];
				n -> y[3] = n -> y[0] - 2;
			}
			}
			}
		}else if(n -> rot == 2){
			if(m2[n -> y[0]][n -> x[0] - 1] != 1 && m2[n-> y[0] - 1][n -> x[0]] != 1 && m2[n -> y[0]][n -> x[0] - 2] != 1){
			if(n -> x[0] - 1 < max && n -> y[0] - 1 < max && n -> x[0] - 2 < max){
			if(n -> x[0] - 1 >= 0  && n -> y[0] - 1 >= 0  && n -> x[0] - 2 >= 0 ){
				n -> rot = 3;
				n -> x[1] = n -> x[0];
				n -> y[1] = n -> y[0] - 1;	

				n -> x[2] = n -> x[0] - 1;
				n -> y[2] = n -> y[0];	

				n -> x[3] = n -> x[0] - 2;
				n -> y[3] = n -> y[0];
			}
			}
			}
		}else if(n -> rot == 3){
			if(m2[n -> y[0] - 1][n -> x[0]] != 1 && m2[n-> y[0] - 2][n -> x[0]] != 1 && m2[n -> y[0] - 2][n -> x[0] - 1] != 1){
			if(n -> x[0] - 1 < max && n -> y[0] - 1 < max && n -> y[0] - 2 < max){
			if(n -> x[0] - 1 >= 0  && n -> y[0] - 1 >= 0  && n -> y[0] - 2 >= 0 ){
				n -> rot = 0;
				n -> x[1] = n -> x[0];
				n -> y[1] = n -> y[0] - 1;	

				n -> x[2] = n -> x[0];
				n -> y[2] = n -> y[0] - 2;	

				n -> x[3] = n -> x[0] - 1;
				n -> y[3] = n -> y[0] - 2;
			}
			}
			}
		}			
	}
}

void marg(node *n){
	int i;
	for(i = 0; i < 4; i++){
		if(n -> y[i] >= 0 && n -> x[i] >= 0 && n -> y[i] < max && n -> x[i] < max)
			m[n -> y[i]][n -> x[i]] = 1;	
	}
}
void movex(node *n){
	int i;
	for(i = 0; i < 4; i++){
		n -> y[i] += 1;
	}
}
void back(){
	int  i, j;
	for(i = 0; i < max; i++){
		for(j = 0; j < max; j++){
			m[i][j] = m2[i][j];
		}
	}
}
void win(){
	int i, j, k;	
	for(i = 0; i < max; i++){
		int f = 0;
		for(j = 0; j < max; j++){	
			if(m2[i][j] == 0) f = 1;		
		}
		int l;
		if(!f){
			points++;
			for(l = i; l > 0; l--){
				for(k = 0; k < max; k++)
				m2[l][k] = m2[l - 1][k];			
			}
			for(k = 0; k < max; k++)
				m2[0][k] = 0;
			back();	
			marg(tet);
			i--;		
		}
		
	}
	for(i = 0; i < max; i++) 
		if(m2[0][i] == 1){
			printf("\n\nPoints : %d \n\n", points);	
			exit(0);			
		}
	
}
void movey(node *n, int lf){
	if(lf){
		int i;
		
		for(i = 0; i < 4; i++){
			
			if(n -> x[i] + 1 > max - 1) return;
			if(m2[n -> y[i]][n -> x[i] + 1] == 1) return;
		}
		for(i = 0; i < 4; i++){
			n -> x[i] += 1;
		}
	}else{
		int i;
		for(i = 0; i < 4; i++){
			if(n -> x[i] - 1 < 0) return;
			if(m2[n -> y[i]][n -> x[i] - 1] == 1) return;
		}
		for(i = 0; i < 4; i++){
			n -> x[i] -= 1;
		}	
	}
}

int check(node *n){
	int i, j, k, l;	
	for(i = 0; i < 4; i++){
		if(m2[(n -> y[i]) + 1][n -> x[i]] == 1 || n -> y[i] == max - 1 ){
			for(j = 0; j < 4; j++)
				m2[n -> y[j]][n -> x[j]] = 1;
			return 1;	
		}
				
	}
	return 0;
}

void cube(float x1, float x2, float y1, float y2, float z1){
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y2, z1);
	glVertex3f(x1, y2, z1);

	glEnd(); 
}

void border(float x1, float y1, float z1, float w){
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	
	glVertex3f(x1, y1, z1);
	glVertex3f(x1 - 2*w + 0.02, y1, z1);
	glVertex3f(x1 - 2*w + 0.02, y1 + 0.01, z1);
	glVertex3f(x1, y1 + 0.01, z1);

	glEnd();

	glBegin(GL_QUADS);
	
	glVertex3f(x1, y1 + 2*w, z1);
	glVertex3f(x1 - 2*w + 0.02, y1 + 2*w, z1);
	glVertex3f(x1 - 2*w + 0.02, y1 + 2*w + 0.01, z1);
	glVertex3f(x1, y1 + 2*w + 0.01, z1);

	glEnd();

	glBegin(GL_QUADS);
	
	glVertex3f(x1, y1, z1);
	glVertex3f(x1 + 0.01, y1, z1);
	glVertex3f(x1 + 0.01, y1 + 2*w, z1);
	glVertex3f(x1, y1 + 2*w, z1);

	glEnd();

	glBegin(GL_QUADS);
	
	glVertex3f(x1 - 2*w + 0.01, y1, z1);
	glVertex3f(x1 - 2*w + 0.02, y1, z1);
	glVertex3f(x1 - 2*w + 0.02, y1 + 2*w, z1);
	glVertex3f(x1 - 2*w + 0.01, y1 + 2*w, z1);

	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();

	glTranslatef(0.0, 0.0, -2.0);
	int i,j;
	float x, y, z, c;
	float bo = -0.1*(max/2.0f);
	border(bo - 0.01, -bo - 0.01,0.0, bo);
	for(i = 0; i < max; i++){
		for(j = 0; j < max; j++){
			if(m[i][j] == 1)cube(bo + 0.1*j + 0.01, bo + 0.1*(j + 1) - 0.01, -bo - 0.1*i - 0.01, -bo - 0.1*(i + 1) + 0.01, 0.0);
		}
	}
	win();
	glutSwapBuffers();
}
void new(){
	tet = malloc(sizeof(node));
	srand(time(NULL));
	int rx = rand() % 6;
	tet -> type = rx;
	tet -> rot = 0;
	type(tet);
}
void myIdleFunc(int a) {
	if(check(tet)){
		new();
	}	
	back();
	marg(tet);
	movex(tet);
	glutPostRedisplay();
	
	glutTimerFunc(1000, myIdleFunc, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) {	
		printf("\n\nPoints : %d \n\n", points);	
		exit(0);	
	}else if((char)key == 'a'){
		movey(tet, 0);
		glutPostRedisplay();	
	}else if((char)key == 'd'){
		movey(tet, 1);
		glutPostRedisplay();	
	}else if((char)key == 'w'){
		rotate(tet);
		glutPostRedisplay();	
	}
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);	
	glLoadIdentity ();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLfloat acolor[] = {1.4, 1.4, 1.4, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, acolor);

}
void Reshape(int w, int h)
{
    	glViewport(0, 0, w/2, h);
    	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(45.0, (double)w/(double)h, 0.1, 200.0);
	
}
void disptext()
{
glRasterPos2f(100,400);
glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*) "Tetris by Asaad Aman and Arun Kumar");
}
int func1(int argc, char** argv){
				
		for(int i = 0; i < max; i++)
		for(int j = 0; j < max; j++){
			m [i][j] = 0;
			m2[i][j] = 0;		
		}
	tet = malloc(sizeof(node));
	srand(time(NULL));
	int rx = rand() % 6;
	tet -> type = rx;
	tet -> rot = 0;
	type(tet);
	movey(tet, 1);
	marg(tet);
	glutInit(&argc,argv);
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Tetris");
	init();
	glutTimerFunc(500, myIdleFunc, 0);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc( keyboard );
	disptext();
	glutDisplayFunc(display);
	glutMainLoop();
	}
int main(int argc, char** argv)
{
	int i, j,choice;
	printf("Welcome to Tetris by Asaad & Arun");
	printf("\nPress 0 to exit \nPress 1 to play: \n");
	LABEL:	
	scanf("%d",&choice);
	switch (choice)	
	{
	case 0:
	printf("\nThank You!\n");
	exit(0);
	break;
	case 1:	
	func1(argc,argv);		
	break;
	default:
	printf("\nWrong choice. Retry\n");
	goto LABEL;	
	}
}
