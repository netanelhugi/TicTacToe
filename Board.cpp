#include <iostream>
using namespace std;

#include "Board.h"

Board::Board()
{
    //default constructor
}

//constructor, get int(size of the board)
Board::Board(int n)
{

    boardSize = n;

    // create&allocat matrix of BoardChar's
    BoardMat = new BoardChar *[n];

    for (int i = 0; i < boardSize; i++)
    {
        BoardMat[i] = new BoardChar[boardSize];
    }
}

// //destractor
Board::~Board()
{
    //free memory
    for (int i = 0; i < boardSize; i++)
    {
        delete[] BoardMat[i];
    }
    delete[] BoardMat;
}

//getSize
int Board::size() const
{
    return boardSize;
}

//fill the board with some char
Board &Board::operator=(char c)
{

    if (c != '.' && c != 'O' && c != 'X')
    {
        throw IllegalCharException{c};
    }

    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; j++)
        {
            BoardMat[i][j] = '.';
        }
    }
    return *this;
}

//get char place from the matrix
char Board::operator[](BoardIndex c) const
{
    if (c.i >= boardSize || c.j >= boardSize)
        throw IllegalCoordinateException{c};
    return BoardMat[c.i][c.j];
}

//get BoardChar place from the matrix
BoardChar Board::operator[](BoardIndex c)
{
    if (c.i >= boardSize || c.j >= boardSize)
        throw IllegalCoordinateException{c};
    return BoardMat[c.i][c.j];
}

//get char in loction
char Board::getBoardChar(int i, int j) const
{
    return BoardMat[i][j];
}

void Board::setSize(int n)
{
    boardSize = n;
}

//draw the TicTacToe board into new file
string Board::draw(int n)
{
    const int length = n, width = n;
    string fileName = "TicTacToe-Board.ppm";

    ifstream File(fileName); //create new file
    bool fileExist = false;

    if (File) //check if "fileName" is exist
    {
        fileExist = true;
    }

    int index = 1;
    /**
    *if the file name is exist,
    *the methot add 'i' to the end of the file name
    *d check again
    */
    while (fileExist)
    {

        fileName = "TicTacToe-Board";
        fileName += to_string(index);
        fileName += ".ppm";

        ifstream File(fileName); //create new file

        if (File)
        {
            index++;
        }
        else
        {
            fileExist = false;
        }
    }

    int strokSize = 2; //width of the borders

    ofstream imageFile(fileName); //create new file

    imageFile << "P6" << endl
              << length << " " << width << endl
              << 255 << endl;

    //crate array of Rgb objects
    RGB **image;
    image = new RGB *[n];

    RGB red{255, 17, 0};
    RGB whith{255, 255, 255};
    RGB blue{0, 125, 255};

    for (int i = 0; i < n; i++)
    {
        image[i] = new RGB[n];
        for (int j = 0; j < n; j++)
        {
            image[i][j] = blue;
        }
    }

    //draw board lines
    drawBorders(image, n);

    int BoardSize0 = size();
    int part = n / BoardSize0;

    /*
    *Draw Board signs
    */
    for (int i = BoardSize0 - 1; i >= 0; i--)
    {
        for (int j = BoardSize0 - 1; j >= 0; j--)
        {

            if (getBoardChar(i, j) == 'X')
            {
                drawX(image, n, i, j);
            }

            else if (getBoardChar(i, j) == 'O')
            {
                drawO(image, n, i, j);
            }
        }
    }

    ///
    ///image processing
    ///
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            imageFile.write(reinterpret_cast<char *>(&image[i][j]), 3);
        }
    }

    imageFile.close();

    return fileName;
}

void Board::drawBorders(RGB **image, int n)
{

    int border = 1;
    int BoardSize0 = size();
    int part = n / BoardSize0;
    int strokSize = 2; //width of the borders
    RGB red{255, 0, 0};
    RGB whith{255, 255, 255};
    RGB blue{0, 125, 255};

    //draw board borders
    for (int i = 0; i < n; i++)
    {
        image[i][0] = red;
        image[0][i] = red;
        image[i][n - 1] = red;
        image[n - 1][i] = red;
    }

    while (border < BoardSize0)
    {

        for (int i = (n - part * (border)) - (strokSize / 2); i < (n - part * (border)) + (strokSize / 2); i++)
        {
            for (int j = 0; j < n; j++)
            {
                image[i][j] = red;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = (n - part * border) - (strokSize / 2); j < (n - part * border) + (strokSize / 2); j++)
            {
                image[i][j] = red;
            }
        }

        border++;
    }
}

void Board::drawX(RGB **image, int n, int i, int j)
{
    RGB black{0, 0, 0};
    int part = n / boardSize;

    int JstartX = (n - part * (boardSize - j)) + 1;
    int JendX = (n - part * (boardSize - j - 1)) - 1;

    int IstartX = (n - part * (boardSize - i)) + 1;
    int IendX = (n - part * (boardSize - i - 1)) - 1;

    int lineSize = 3; //width of 'x'
    int count = 0;    //"tab"

    for (int l = IstartX + 1; l < IendX - 1; l++)
    {

        for (int k = JstartX + count + 1; k < JstartX + count + lineSize; k++)
        {
            image[l][k] = black;
        }

        for (int k = JendX - count - 1; k > JendX - count - lineSize; k--)
        {
            image[l][k] = black;
        }
        count++;
    }
}

void Board::drawO(RGB **image, int n, int i, int j)
{
    RGB yellow{255, 255, 0};
    int part = n / boardSize;

    int r = (part / 2);
    int Cx = part * i + r;
    int Cy = part * j + r;
    int r2 = r - part / 30; //outside line limit of 'O'
    int r3 = r2 * 0.9;      //inside line limit of 'O'
    int xNorm;
    int yNorm;

    for (int y = Cy - r2; y <= Cy + r2; y++)
    {
        for (int x = Cx - r2; x <= Cx + r2; x++)
        {
            xNorm = x - Cx;
            yNorm = y - Cy;
            if ((xNorm * xNorm + yNorm * yNorm <= r2 * r2) && (xNorm * xNorm + yNorm * yNorm >= r3 * r3))
            {
                image[Cx + xNorm][Cy + yNorm] = yellow;
            }
        }
    }
}
