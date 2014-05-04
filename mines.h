#include <stdio.h>

#define NxN_MineSweeper 5
#define TOTAL_BOXES (NxN_MineSweeper * NxN_MineSweeper)

#define BOX_WIDTH 35
#define BOX_HEIGHT BOX_WIDTH

typedef enum {
	GAME_NOT_STARTED,
        GAME_OVER,
        GAME_WON,
        GAME_QUIT,
        GAME_INPROGRESS,
} status_t;

typedef enum {
        FALSE = 0,
        TRUE
} myBoolean_t;

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

typedef struct {
        /* Holds the GUI corner points of the box */
	int         cornersGUI [4][2];

        /* Holds the box numbers of the adjucent boxes.
           adj_box [0] contains the number of adjucent boxes */
	int         adjBox [9];

        /* Holds the value of the box that should be displayed when opened */
        flag_t      flag;

        /* Holds the display status of the box */
        box_stat_t  dispStat;
} mine_box_t;

//0   1  2  3  4
//5   6  7  8  9          box structure
//10 11 12 13 14
//15 16 17 18 19
//20 21 22 23 24
