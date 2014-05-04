#include<math.h>
#include<GL/glut.h>
#include<unistd.h>

#define NxN_MineSweeper 5

int start_flag=0; //displaying rules
typedef enum {	
	GAME_NOT_STARTED,
        GAME_OVER,
        GAME_WON,
        GAME_QUIT,
        GAME_INPROGRESS,
} status_t;
status_t game_status = GAME_NOT_STARTED;

#define BOX_WIDTH 35
#define BOX_HEIGHT BOX_WIDTH

int bigBoxCornersGUI [4][2] = {
        {10, 210},                                      {190, 210},
             /*----------------------------------------*
              |                                        |
              |                                        |
              |                                        |
              |                                        |
              |                                        |
              *----------------------------------------*/
        {10, 30},                                       {190, 30}
};

typedef enum {
        FALSE = 0,
        TRUE
} myBoolean_t;

inline myBoolean_t
isOutSideBigBoxScope (int x_co, int y_co)
{
        if (x_co < bigBoxCornersGUI [0][0] || x_co > bigBoxCornersGUI [1][0])
                return TRUE;

        if (y_co < bigBoxCornersGUI [2][1] || x_co > bigBoxCornersGUI [0][1])
                return TRUE;

        return FALSE;
}
inline void changeGameStatus (status_t status)
{ 	
	game_status = status;
	start_flag=10;
}
typedef enum {
        FLAG_0_AROUND = 0,
        FLAG_1_AROUND,
        FLAG_2_AROUND,
        FLAG_3_AROUND,
        FLAG_4_AROUND,
        FLAG_5_AROUND,
        FLAG_6_AROUND,
        FLAG_7_AROUND,
        FLAG_8_AROUND,
        FLAG_BOMB,
} flag_t;

typedef enum {
        BOX_CLOSED,
        BOX_OPENED,
        BOX_MARKED
} box_stat_t;

struct mine {
        /* Holds the GUI corner points of the box */
	int         cornersGUI [4][2];

        /* Holds the box numbers of the adjucent boxes.
           adj_box [0] contains the number of adjucent boxes */
	int         adj_box [9];

        /* Holds the value of the box that should be displayed when opened */
        flag_t      flag;

        /* Holds the display status of the box */
        box_stat_t  dispStat;
} box[25];

//0   1  2  3  4
//5   6  7  8  9          box structure
//10 11 12 13 14
//15 16 17 18 19
//20 21 22 23 24

void fill_box()
{
	//a[][]
	int     x0=0;
        int     y0 =30;

	for (int k = 0; k < 25; k++) {
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				box[k].a[0][o]=x0;
				box[k].a[1][1]=y0;
				box[k].a[2][o]=x0;
				box [k].a [3][1] = y0;
                        }
		}
		y0+=35;
	}

	//flags
	for (int i=0;i<25;i++)	box[tmp].num=0;
	for (int i=0;i<10;)
	{
		int tmp=rand()%25;
		if (box [tmp].flag!=1)	i++,box [tmp].flag=1,box [tmp].num=-1;
	}
	//adj[]
	box [0].adj []={1, 6, 5, -1};
	box [1].adj []={0, 6, 5, 7, 2, -1};
	box [2].adj []={1, 6, 7, 8, 3, -1};
	box [3].adj []={2, 7, 8, 9, 4, -1};
	box [4].adj []={8, 3, 9, -1};
	box [5].adj []={0, 1, 6, 11, 10, -1};
	box [6].adj []={0, 1, 2, 5, 7, 12, 11 ,10, -1};
	box [7].adj []={1, 2, 3, 8, 13, 12, 11, 6, -1};
	box [8].adj []={2, 3, 4, 7, 12, 13, 14, 9, -1};
	box [9].adj []={3, 4, 8, 13, 14, -1};
	box [10].adj []={11, 6, 5, 16, 15, -1};
	box [11].adj []={5, 6, 7, 12, 17, 16, 15, 10, -1};
	box [12].adj []={6, 7, 8, 13, 18, 17, 16, 11, -1};
	box [13].adj []={17, 18, 19, 14, 9, 8, 7, 12, -1};
	box [14].adj []={9, 8, 13, 18, 19, -1};
	box [15].adj []={10, 11, 16, 21, 20, -1};
	box [16].adj []={10, 15, 20, 21, 22, 17, 12, 11, -1};
	box [17].adj []={21, 22, 23, 18, 13, 12, 11, 16, -1};
	box [18].adj []={22, 23, 24, 19, 14, 13, 12, 17, -1};
	box [19].adj []={24, 23, 18, 13, 14, -1};
	box [20].adj []={15, 16, 21, -1};
	box [21].adj []={17, 16, 15, 20, 22, -1};
	box [22].adj []={21, 16, 17, 18, 23, -1};
	box [23].adj []={22, 17, 24, 18, 19, -1};
	box [24].adj []={18, 19, 23, -1};
	//box structure

}

/* TODO: Check for correctness of the algo below */
int
getBox (int x, int y)
{
        if (isOutSideBigBoxScope (x, y))
                return -1;

        xColn  = (x - box [0]. cornersGUI [0][0]) / BOX_WIDTH;

        yColn = (y - box [0]. cornersGUI [0][1]) / BOX_HEIGHT;

        return ((NxN_MineSweeper * yColn + xColn) - 1);
}

void
myMouse (int button, int mouse_status, int x, int y)
{
        /* If the event is not GLUT_DOWN, this is of not our interest */
	if (mouse_status != GLUT_DOWN)
                return;

        if (start_flag < 6) {
                if (x > 80 && x < 120)
                        if (y > 10 && y < 30) {
        			changeGameStatus (GAME_INPREOGRESS);  
                        }

                start_flag++;

                display();

                if (start_flag>=6) {
                        changeGameStatus (GAME_INPREOGRESS);
                }
        }

        if (stat_flag==1)
                updateBox (getBox (x,y), button);	//open
}

void
myKey (unsigned char key ,int x,int y)
{
	if (key == 'e')
                explore_box (getBox (x,y));

	if (key == 'q') {
                game_status = GAME_QUIT;

                display();
        }
}

/* Based on the mouse button the function changes the display status of the
 * box which is clicked
 */
void
updateBox (int bNum, int type)
{
	switch(type) {
        case GLUT_LEFT_BUTTON:
                switch (box [bNum].dispStat) {
                case BOX_CLOSED:
                	box [bNum].dispStat = BOX_OPENED;
                	
                        if (box [bNum].flag == FLAG_BOMB)
                                game_status = GAME_OVER;

                        display ();
                        break;

                case BOX_MARKED:
                case BOX_OPENED:
                default:
                        break;
                }
                break;

        case GLUT_RIGHT_BUTTON:
                switch (box [bNum].dispStat) {
                case BOX_CLOSED:
                        box [bNum].dispStat = BOX_MARKED;
                        display ();
                        break;

                case BOX_MARKED:
                        box [bNum].dispStat = BOX_CLOSED;
                        display ();
                        break;

                case BOX_OPENED:
                default:
                        break;
                }
                break;

        default:
                break;
	}
}

void display()
{	//display 5*5 minesweeper
	//vasi
	glClearColor(1,1,1,1);
	char *str[50];
	str [12] = "5*5 Minesweeper";
	str [20] = "by-Vasishta shastry & Uttam";
	str [21] = "Made in Bharath";
	
	realDisplay (280,150,str [12]);
	realDisplay (20,20,str [20]);
	realDisplay (250,20,str [21]);
	
	switch(game_status)
	{

		//strs-starting
		case GAME_NOT_STARTED:
		
		str [1] = "Rules and Directions";
		str [2] = "1.10 random ones of 25 following boxex have bombs.";
		str [3] = "Main aim of the game is to explore all boxes";
		str [4] = "which does not contain a bomb";
		str [5] = "2.Use Left mouse button to open a box."
		str [6] = "if you try to open a box which has a bomb";
		str [7] = "you'll be out of the game."
		str [8] = "3.Guess the first box where bomb may not be present.";
		str [9] = "The opened box will give you the clue for next one.";
		str [10] = "4.Number present in the explored box will tell you";
		str [11] = "how many adjecent(atleast 1 common vertex) boxes have";
		str [12] = "bombs.";
		str [13] ="5.You can keep flags on boxes on which you have doubt.";
		str [14] ="you can use atmost 10 flags.";
		str [15] ="Use Right mouse button to place a flag.";
		str [19] = "ALL THE BEST"

		switch(start_flag) {
			case 1://rule 1
			realDisplay (150,250,str [1]);
			realDisplay (80,200,str [2]);
			realDisplay (80,160,str [3]);
			realDisplay (80,120,str [4]);
			break;
			case 2://rule 2
			realDisplay (80,200,str [5]);
			realDisplay (80,160,str [6]);
			realDisplay (80,120,str [7]);
			break;
			case 3://rule 3
			realDisplay (80,200,str [8]);
			realDisplay (80,120,str [9]);
			break;
			case 4://rule 4
			realDisplay (80,200,str [10]);
			realDisplay (80,160,str [11]);
			realDisplay (150,120,str [12]);
			break;
			case 5://rule 5
			realDisplay (80,200,str [13]);
			realDisplay (120,160,str [14]);
			realDisplay (80,120,str [15]);
			realDisplay (150,50,str [19]);
			break;
		
		}
			break;
			
		case GAME_INPROGRESS://draw box
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
			char *strdisp[1];
			strdisp [0] = 'F';
			strdisp [1] = '1';
			strdisp [2] = '2';
			strdisp [3] = '3';
			strdisp [4] = '4';
			strdisp [5] = '5';
			strdisp [6] = '6';
			strdisp [7] = '7';
			strdisp [8] = '8';
			strdisp [9] = '0';
			
			for (int o = 0;o<25;o++){
				
				switch (box [i].dispStat){
					case BOX_MARKED:	
					realDisplay(box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [0]);
					break;
					case BOX_OPENED:
					switch (box [i].flag){
						case FLAG_0_AROUND:
						realDislay((box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [9]);
						case FLAG_1_AROUND:
						realDislay((box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [1]);
						case FLAG_2_AROUND:
						realDislay((box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [2]);
						case FLAG_3_AROUND:
						realDislay((box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [3]);
						case FLAG_4_AROUND:
						realDislay((box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [4]);
						case FLAG_5_AROUND:
						realDislay((box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [5]);
						case FLAG_6_AROUND:
						realDislay((box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [6]);
						case FLAG_7_AROUND:
						realDislay((box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [7]);
						case FLAG_8_AROUND:
						realDislay((box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [8]);
						
					}
				}
				
			}
			break;
		case GAME_OVER://strs ending
			str [23] = "Oops !! You lost ; Better Luck Next Time";
			realDisplay(100,160,str [23]);
			break;
		case GAME_QUIT:
			str [24] = "You Have Decided To Quit The Game.";
			realDisplay(100,160,str [24]);
			break
		case GAME_WON:
			str [25] = "Congadulations!! You have Won the Game";
			str [26]="Thank You For Playing This Game";
			str [27]="We Hope You Enjoyed The Game";
			realDisplay(100,160,str [25]);
			
		
		
	
	

	}
}

void myinit()
{
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glClearColor(1,1,1,1);
	glColor3f (1.0, 0.0,0.0);
	glOrtho2D(0,200,0,300);
	//glMatrixMode(GL_MODELVIEW);
}

void main()
{
        glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
        glutInitWindowSize (800,600);
        glutInitWindowPosition (100,100);
        glutCreateWindow ("Minesweeper");
        glutDisplayFunc (display);
        glutKeyboardFunc (myKey);
        glutMouseFunc (myMouse);
        myinit ();
        glutMainLoop ();
}
