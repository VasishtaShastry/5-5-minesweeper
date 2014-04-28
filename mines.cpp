#include<math.h>
#include<GL/glut.h>
int stat_flag=0; //0->starting,1->going on,2->terminated
int start_flag=0;
typedef struct mine
{
	int a[4][2];	//4-points,2-x,y
	int adj[8];
	int num,flag;	//flag= 1->bomb,2-flag
	int open ;	//0 if not yet explored
}box[25];


void fill_box()
{
	//a[][]
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
	//flags
	for(int i=0;i<25;i++)	box[tmp].num=0;
	for(int i=0;i<10;)
	{
		int tmp=rand()%25;
		if(box[tmp].flag!=1)	i++,box[tmp].flag=1,box[tmp].num=-1;
	}
	//adj[]
	box[0].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[1].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[2].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[3].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[4].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[5].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[6].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[7].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[8].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[9].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[10].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[11].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[12].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[13].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[14].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[15].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[16].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[17].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[18].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[19].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[20].adj[]={1,6,5,-1,-1,-1,-1,-1};
	box[21].adj[]={17,16,15,-1,-1,-1,-1,-1};
	box[22].adj[]={21,16,17,18,23,-1,};
	box[23].adj[]={22,17,24,18,19,-1};
	box[24].adj[]={18,19,23,-1};
	//box structure
0   1  2  3  4 
5   6  7  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24	
}
void my_mouse(int b,int s,int x,int y)
{	
	if(s==GLUT_DOWN)
	{	
		if(!stat_flag)
		{
			start_flag++;
			reneder_start();
			if(start_flag>=3)	stat_flag++;
		}

		if(b==GLUT_LEFT_BUTTON)		update_box(check_box(x,y),1);	//open
		if(b==GLUT_RIGHT_BUTTON)	handle_flags(check_box(x,y),2);	//flag
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
