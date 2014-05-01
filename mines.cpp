#include<math.h>
#include<GL/glut.h>
#include<unistd.h>
int stat_flag=0; //0->starting,1->going on,2->terminated
int start_flag=0; //displaying rules 
int efin=0;	//everything finished 1->won,2->game over,3->pressed q
typedef struct mine
{
	int a[4][2];	//4-points,2-x,y
	int adj[8];
	int num,flag;	//flag= 1->bomb,2-flag
	int open ;	//0 if not yet explored
}box[25];
//0   1  2  3  4 
//5   6  7  8  9          box structure
//10 11 12 13 14
//15 16 17 18 19
//20 21 22 23 24

void fill_box()
{
	//a[][]
	int x0=0,y0=30;
	for(int k=0;k<25;k++)
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				box[k].a[i][o]=x0;
				box[k].a[i][1]=y0;
				box[k].a[i][o]=x0;
				box[k].a[i][1]=y0;
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
	box[0].adj[]={1,6,5,-1};
	box[1].adj[]={0,6,5,7,2,-1};
	box[2].adj[]={1,6,7,8,3,-1};
	box[3].adj[]={2,7,8,9,4,-1};
	box[4].adj[]={8,3,9,-1};
	box[5].adj[]={0,1,6,11,10,-1};
	box[6].adj[]={0,1,2,5,7,12,11,10,-1};
	box[7].adj[]={1,2,3,8,13,12,11,6,-1};
	box[8].adj[]={2,3,4,7,12,13,14,9,-1};
	box[9].adj[]={3,4,8,13,14,-1};
	box[10].adj[]={11,6,5,16,15,-1};
	box[11].adj[]={5,6,7,12,17,16,15,10,-1};
	box[12].adj[]={6,7,8,13,18,17,16,11,-1};
	box[13].adj[]={17,18,19,14,9,8,7,12,-1};
	box[14].adj[]={9,8,13,18,19,-1};
	box[15].adj[]={10,11,16,21,20,-1};
	box[16].adj[]={10,15,20,21,22,17,12,11,-1};
	box[17].adj[]={21,22,23,18,13,12,11,16,-1};
	box[18].adj[]={22,23,24,19,14,13,12,17,-1};
	box[19].adj[]={24,23,18,13,14,-1};
	box[20].adj[]={15,16,21,-1};
	box[21].adj[]={17,16,15,20,22,-1};
	box[22].adj[]={21,16,17,18,23,-1};
	box[23].adj[]={22,17,24,18,19,-1};
	box[24].adj[]={18,19,23,-1};
	//box structure
	
}
int check_box(int x,int y)
{
	if(x>10 && x<190)
}
void my_mouse(int b,int s,int x,int y)
{	
	if(s==GLUT_DOWN)
	{	
		//starting
		
		if(start_flag<6)
		{	
			if(x>80 && x<120)	if(y>10 && y<30)	stat_flag++,start_flag=10;
			
			start_flag++;
			display();
			if(start_flag>=6)	stat_flag++,start_flag=10;
		}
		
		if(stat_flag==1)
		{
			if(b==GLUT_LEFT_BUTTON)		update_box(check_box(x,y),1);	//open
			if(b==GLUT_RIGHT_BUTTON)	handle_flags(check_box(x,y),2);	//flag

		}
	}
}
void my_key(unsigned char key ,int x,int y)
{
	if(key==’e’)	explore_box(check_box(x,y));
	if(key=='q')	efin=3,stat_flag=2,display();
	
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
void display()
{	//display 5*5 minesweeper
	//vasi
	char strg[2][10];
	strg[0]="5*5 Minesweeper";
	strg[1]="by-Vasishta shastry & Uttam";
	strg[2]="Made in Bharath";
	switch(stat_flag)
	{

		//strs-starting
		case 0:char str1[16][50];
		char str2[3][20];
		str2[0]="Rules and Directions";
		str1[0]="1.10 random ones of 25 following boxex have bombs.";
		str1[1]="Main aim of the game is to explore all boxes";
		str1[2]="which does not contain a bomb"; 
		str1[3]="2.Use Left mouse button to open a box."
		str1[4]="if you try to open a box which has a bomb";
		str1[5]="you'll be out of the game."
		str1[6]="3.Guess the first box where bomb may not be present.";
		str1[7]="The opened box will give you the clue for next one.";
		str1[8]="4.Number present in the explored box will tell you";
		str1[9]="how many adjecent(atleast 1 common vertex) boxes have";
		str2[1]="bombs.";
		str1[10]="5.You can keep flags on boxes on which you have doubt.";
		str1[11]="you can use atmost 10 flags.";
		str1[12]="Use Right mouse button to place a flag.";
		str1[13]="If you feel that you have got same number of bombs";
		str1[14]="around the same as mentioned in it,press 'e' on the box";
		str1[15]="to open other adjecent boxes all at a time.";
		str2[2]="ALL THE BEST"
		
		switch(start_flag)
		{
			case 1://rule 1
			break;
			case 2://rule 2
			break;
			case 3://rule 3
			break;
			case 4://rule 4
			break;
			case 5://rule 5
			break;
			case 6://rule 6
			break;
		}
			break;
		case 1://draw box
			for(int i1=0;i1<25;i1++)
			{
				
				glBegin(GL_LINE_LOOP)
				glVertex2fv(box[i1].a[0]);
				glVertex2fv(box[i1].a[1]);
				glVertex2fv(box[i1].a[2]);
				glVertex2fv(box[i1].a[3]);
				glEnd();
			}
			//display b,f,num
				
			break;
		case 2://strs ending
		char str2[][50];
		str2[0]="Thank You For Playing This Game";
		str2[1]="We Hope You Enjoyed The Game";
		switch(efin)
		{
			case 1://won
			str2[2]="Congadulations!! You have Won the Game";
			break;
			case 2://lost
			str2[3]="Oops !! You lost ; Better Luck Next Time";
			
			break;
			case 3:// pressed q 
			str2[4]="You Have Decided To Quit The Game.";
			break;
		}
			
	}
}
void myinit()
{
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glClearColor(1,1,1,1);
	glColor3f(1.0,0.0,0.0);
	glOrtho2D(0,200,0,300);
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
