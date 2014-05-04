#include<math.h>
#include<GL/glut.h>
#include<unistd.h>
#include "mines.h"

status_t        game_status     = GAME_NOT_STARTED;
int             start_flag      = 0; //displaying rules
mine_box_t      box [25]        = {0,};
int bigBoxCornersGUI [4][2]     = {
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

inline myBoolean_t
isOutSideBigBoxScope (int x_co, int y_co)
{
        if (x_co < bigBoxCornersGUI [0][0] || x_co > bigBoxCornersGUI [1][0])
                return TRUE;

        if (y_co < bigBoxCornersGUI [2][1] || x_co > bigBoxCornersGUI [0][1])
                return TRUE;

        return FALSE;
}

inline void
changeGameStatus (status_t status)
{
	game_status = status;
	start_flag=10;
}

//0   1  2  3  4
//5   6  7  8  9          box structure
//10 11 12 13 14
//15 16 17 18 19
//20 21 22 23 24

void
initAdjBoxList ()
{
	box [0].adjBox [] = {1, 6, 5, -1};
	box [1].adjBox [] = {0, 6, 5, 7, 2, -1};
	box [2].adjBox [] = {1, 6, 7, 8, 3, -1};
	box [3].adjBox [] = {2, 7, 8, 9, 4, -1};
	box [4].adjBox [] = {8, 3, 9, -1};
	box [5].adjBox [] = {0, 1, 6, 11, 10, -1};
	box [6].adjBox [] = {0, 1, 2, 5, 7, 12, 11 ,10, -1};
	box [7].adjBox [] = {1, 2, 3, 8, 13, 12, 11, 6, -1};
	box [8].adjBox [] = {2, 3, 4, 7, 12, 13, 14, 9, -1};
	box [9].adjBox [] = {3, 4, 8, 13, 14, -1};
	box [10].adjBox [] = {11, 6, 5, 16, 15, -1};
	box [11].adjBox [] = {5, 6, 7, 12, 17, 16, 15, 10, -1};
	box [12].adjBox [] = {6, 7, 8, 13, 18, 17, 16, 11, -1};
	box [13].adjBox [] = {17, 18, 19, 14, 9, 8, 7, 12, -1};
	box [14].adjBox [] = {9, 8, 13, 18, 19, -1};
	box [15].adjBox [] = {10, 11, 16, 21, 20, -1};
	box [16].adjBox [] = {10, 15, 20, 21, 22, 17, 12, 11, -1};
	box [17].adjBox [] = {21, 22, 23, 18, 13, 12, 11, 16, -1};
	box [18].adjBox [] = {22, 23, 24, 19, 14, 13, 12, 17, -1};
	box [19].adjBox [] = {24, 23, 18, 13, 14, -1};
	box [20].adjBox [] = {15, 16, 21, -1};
	box [21].adjBox [] = {17, 16, 15, 20, 22, -1};
	box [22].adjBox [] = {21, 16, 17, 18, 23, -1};
	box [23].adjBox [] = {22, 17, 24, 18, 19, -1};
	box [24].adjBox [] = {18, 19, 23, -1};
}

void
initBoxCornersGUI ()
{
        int     x0      = 10;
        int     y0      = 30;

	for (i = 0; i < TOTAL_BOXES; i++) {
                /* Bottom left */
                box [i].a [0][0] = x0;
                box [i].a [0][1] = y0;

                /* Bottom right */
                box [i].a [1][0] = x0 + 35;
                box [i].a [1][1] = y0;

                /* Top right */
                box [i].a [2][0] = x0 + 35;
                box [i].a [2][1] = y0 + 35;

                /* Top left */
                box [i].a [3][0] = x0;
                box [i].a [3][1] = y0 + 35;

                x0 += 35;
                if (((i + 1) % 5) == 0) {
                        x0 = 10;
                        y0 += 35;
                }
	}
}

void
initBox ()
{
        int     i       = 0;
        int     tmp     = -1;

        initBoxCornersGUI ();
        initAdjBoxList ();

        /* Below for loop places the bomb in random 10 boxes */
	for (i = 0; i < 10;) {
		tmp = rand() % TOTAL_BOXES;

		if (box [tmp].flag != FLAG_BOMB) {
                        i++;
                        box [tmp].flag = FLAG_BOMB;

                        /**
                         * Update the surrounding boxes flag to account for
                         * this bomb
                         */
                        for (j = 0; box [tmp].adjBox [j] != -1; j++)
                                box [box [tmp].adjBox [j]].flag ++;
                }
	}
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

void
myFunction ()
{
        for (int o = 0;o<25;o++){
                switch (box [i].dispStat){
                        case BOX_MARKED:
                        realDisplay(box [i].cornersGUI [3][0]+10,box [i].cornersGUI [3][1]-10,strdisp [0]);
                        break;
                        case BOX_OPENED:
                        switch (box [i].flag){
                                realDislay (box [i].cornersGUI [3][0]+10,
                                            box [i].cornersGUI [3][1]-10,
                                            numberToStr (box [i].flag));
                        }
                }

        }
}

void
display ()
{
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

                        myFunction ();
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

void myInit ()
{
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glClearColor(1,1,1,1);
	glColor3f (1.0, 0.0,0.0);
	glOrtho2D(0,200,0,300);
	//glMatrixMode(GL_MODELVIEW);
}

void main ()
{
        glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
        glutInitWindowSize (800,600);
        glutInitWindowPosition (100,100);
        glutCreateWindow ("Minesweeper");
        initBox ();
        glutDisplayFunc (display);
        glutKeyboardFunc (myKey);
        glutMouseFunc (myMouse);
        myInit ();
        glutMainLoop ();
}
