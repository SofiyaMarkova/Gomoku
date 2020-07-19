#define N_COLS 9
#define N_ROWS 9

const char BLACK = 'B';
const char WHITE = 'W';
const char EMPTY = ' ';

// win for white, column 4
// if you're testing horizontally (oops),
//		black win, row 8
char whiteClear[N_ROWS][N_COLS] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'B', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'B', ' ', ' ', 'W', ' ', ' ', ' ', ' '},
    {' ', ' ', 'B', 'W', 'W', ' ', ' ', ' ', ' '},
    {' ', 'B', 'W', 'B', 'W', 'B', 'B', 'W', ' '},
    {' ', 'B', 'B', 'B', 'W', ' ', ' ', ' ', ' '},
    {' ', 'B', 'W', 'W', 'W', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', 'B', 'B', 'B', 'B', 'B', ' ', ' '}
};

// win for black, column 4
char blackClear[N_ROWS][N_COLS] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', ' ', ' ', 'B', ' ', ' ', ' ', ' '},
    {' ', ' ', 'W', 'B', 'B', ' ', ' ', ' ', ' '},
    {' ', 'W', 'B', 'W', 'B', 'W', 'W', 'B', ' '},
    {' ', 'W', 'W', 'W', 'B', ' ', ' ', ' ', ' '},
    {' ', 'W', 'B', 'B', 'B', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

// win for white, black at either end, column 0
char whiteBracketed[N_ROWS][N_COLS] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'B', ' ', 'B', ' ', ' ', ' ', ' ', ' ', ' '},
    {'W', ' ', 'B', ' ', ' ', ' ', ' ', ' ', ' '},
    {'W', ' ', ' ', 'B', 'W', ' ', ' ', ' ', ' '},
    {'W', ' ', 'B', 'W', 'B', 'B', 'B', 'W', ' '},
    {'W', ' ', 'B', 'B', 'B', ' ', ' ', ' ', ' '},
    {'W', ' ', 'B', 'W', 'W', ' ', ' ', ' ', ' '},
    {'B', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

// win for black, column 8, bottom row
char blackBottom[N_ROWS][N_COLS] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', 'W', 'B', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', 'B', 'W', 'W', 'W', 'B', ' ', 'B'},
    {' ', 'W', 'W', 'W', ' ', ' ', ' ', ' ', 'B'},
    {' ', 'W', 'B', 'B', ' ', ' ', ' ', ' ', 'B'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B'}
};

// win for white, column 0, top
// also win for black, but white should be only
// one found
char whiteTop[N_ROWS][N_COLS] = {
    {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'W', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'W', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'W', ' ', 'W', 'B', ' ', ' ', ' ', ' ', ' '},
    {'W', 'W', 'B', 'W', 'W', 'W', 'B', ' ', 'B'},
    {' ', 'W', 'W', 'W', ' ', ' ', ' ', ' ', 'B'},
    {' ', 'W', 'B', 'B', ' ', ' ', ' ', ' ', 'B'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B'}
};

// four consecutive white, column 4, no win
char whiteFour[N_ROWS][N_COLS] = {
    {' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'B', ' ','B', ' ', ' ', ' ', ' ', ' '},
    {' ', 'B', ' ','W', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', 'B','W', 'W', ' ', ' ', ' ', ' '},
    {' ', 'B', 'W','W', 'B', 'B', 'B', 'W', ' '},
    {' ', 'B', 'B','W', 'B', ' ', ' ', ' ', ' '},
    {' ', 'B', 'W','B', 'W', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ','B', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' '}
};

// six consecutive black, column 4, no win
char blackSix[N_ROWS][N_COLS] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', ' ', ' ', 'B', ' ', ' ', ' ', ' '},
    {' ', ' ', 'W', 'B', 'B', ' ', ' ', ' ', ' '},
    {' ', 'W', 'B', 'W', 'B', 'W', 'W', 'B', ' '},
    {' ', 'W', 'W', 'W', 'B', ' ', ' ', ' ', ' '},
    {' ', 'W', 'B', 'B', 'B', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

// six consecutive white at bottom, column 4,
//		no win
char whiteSixBottom[N_ROWS][N_COLS] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'B', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'B', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', 'B', 'W', 'W', ' ', ' ', ' ', ' '},
    {' ', 'B', 'W', 'B', 'W', 'B', 'B', 'W', ' '},
    {' ', 'B', 'B', 'B', 'W', ' ', ' ', ' ', ' '},
    {' ', 'B', 'W', 'W', 'W', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', 'W', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', 'W', ' ', ' ', ' ', ' '}
};

// win for black column 4,
//		two white six consecutives
char blackWithWhiteSix[N_ROWS][N_COLS] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', ' ', ' ', 'B', ' ', ' ', 'W', ' '},
    {' ', 'W', 'W', 'B', 'B', ' ', ' ', 'W', ' '},
    {' ', 'W', 'B', 'W', 'B', 'W', 'W', 'W', ' '},
    {' ', 'W', 'W', 'W', 'B', ' ', ' ', 'W', ' '},
    {' ', 'W', 'B', 'B', 'B', ' ', ' ', 'W', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};



 
