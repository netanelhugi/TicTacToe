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

    //draw board borders
    drawBorders(image, n);

    int BoardSize0 = size();
    int part = n / BoardSize0;

    ////////draw signs///////////////////////////

    // int loc = n / BoardSize0;

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
            //     int Jstart = (n - part * (BoardSize0 - j)) + (strokSize / 2);
            //     int Jend = (n - part * (BoardSize0 - j - 1)) - (strokSize / 2);
            //     int Jdiff = Jend - Jstart;

            //     int Istart = (n - part * (BoardSize0 - i)) + (strokSize / 2);
            //     int Iend = (n - part * (BoardSize0 - i - 1)) - (strokSize / 2);
            //     int Idiff = Iend - Istart;

            //     int tab = Idiff / 15;

            //     //DRAW 'O'
            //     //The function draws a red square in the file as 'O'
            //     for (int l = Iend - strokSize - tab; l >= Istart + strokSize + tab; l--)
            //     {
            //         for (int k = Jend - strokSize - tab; k >= Jstart + strokSize + tab; k--)
            //         {
            //             image[n * l + k].red = (255 % 256);
            //             image[n * l + k].green = (17 % 256);
            //             image[n * l + k].blue = (0 % 256);
            //         }
            //     }
            // }
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
    RGB black{255, 0, 0};
    RGB whith{255, 255, 255};
    RGB blue{0, 125, 255};

    //draw board borders
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            image[i][j] = black;
            image[j][i] = black;
        }
    }

    while (border < BoardSize0)
    {

        for (int i = (n - part * (border)) - (strokSize / 2); i < (n - part * (border)) + (strokSize / 2); i++)
        {
            for (int j = 0; j < n; j++)
            {
                image[i][j] = black;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = (n - part * border) - (strokSize / 2); j < (n - part * border) + (strokSize / 2); j++)
            {
                image[i][j] = black;
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
    int JdiffX = JendX - JstartX;

    int IstartX = (n - part * (boardSize - i)) + 1;
    // cout << "Istart: " << IstartX << endl;
    int IendX = (n - part * (boardSize - i - 1)) - 1;
    // cout << "Iend: " << IendX << endl;
    int IdiffX = IendX - IstartX;

    int lineSize = 3; //size of 'X'
    int count = 0;

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
    RGB black{255, 255, 0};
    int part = n / boardSize;

    int r = (part / 2);
    cout << "part: " << part << endl;
    int Cx = part * i + r;
    int Cy = part * j + r;
    int r2 = r-part/30;
    int xNorm;
    int yNorm;

    for (int y = Cy - r2; y <= Cy + r2; y++)
    {
        for (int x = Cx - r2; x <= Cx + r2; x++)
        {
            xNorm = x - Cx;
            yNorm = y - Cy;
            if (xNorm * xNorm + yNorm * yNorm <= r2 * r2)
            {
            cout << "Xn: " << Cx+xNorm << " Yn: " <<Cy+yNorm << " R: " << r << endl;
                image[Cx+xNorm][Cy+yNorm] = black;
            }
        }

    }

}
