#include<math.h>
#include<GL/glut.h>
int stat_flag=0; //0->starting,1->going on,2->terminated
int start_flag=0;
typedef struct mine
{
	int a[4][2];	//4-points,2-x,y
int num,flag;	//num- 1->bomb,2-flag
int open ;	//0 if not yet explored
}box[25];

void fill_dimension()
{
	int x0=0,y0=0;
	for(int k=0;k<25;k++)
	{
		x0=10;
		for(int i=0;i<5;i++)
		{
			box[k].a[i][o]=x0;
			box[k].a[i][1]=y0;
			x0+=35;
		}
		y0+=35;
	}
}

void fill_box()
{
	for(int i=0;i<10;)
	{
		int tmp=rand()%25;
	if(box[tmp]!=1)	i++,box[tmp]=1,box[tmp].num=-1;
}
for(int i=0;i<25;i++)	box[tmp].num=0;
for(int i=0;i<25;i++)
{
//Care has been taken to maintain generality with small changes	





void my_mouse(int b,int s,int x,int y)
{	
	if(s==GLUT_DOWN)
	{	
if(!stat_flag)
{
start_flag++;
	if(start_flag>=3)	stat_flag++;
}

		if(b==GLUT_LEFT_BUTTON)		update_box(check_box(x,y),1);	//open
	if(b==GLUT_RIGHT_BUTTON)	update_box(check_box(x,y),2);	//flag
}
}
void my_key(unsigned char key ,int x,int y)
{
	if(key==’e’)	explore_box(check_box(x,y));
}
void update_box(int b_num,int type)
{
	switch(type)
	{
		case 1:	//open
		case 2:	//flag
			if(
	}
}
void myinit()
{
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glClearColor(1,1,1,1);
	glColor3f(1.0,0.0,0.0);
	glOrtho(-500,500,-500,500,-500,500);
	//glMatrixMode(GL_MODELVIEW);
}
void main()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Minesweeper");
	glutDisplayFunc(display);
	glutKeyboardFunc(my_key);
	glutMouseFunc(my_mouse);
	myinit();
	glutMainLoop();
}
