#include <iostream>
using namespace std;

#include "Board.h"

Board::Board(){
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

void Board::setSize(int n){
    boardSize = n;
}

//represent pixel color
struct RGB {
  uint8_t red, green, blue;
    public:
    RGB() {}
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};


//draw the TicTacToe board into new file
string Board::draw(int n){
      const int length = n, width = n;
      string fileName = "TicTacToe-Board.ppm";

      ifstream File(fileName);//create new file
        bool fileExist = false;

        if(File){
            cout << "exist!!!" << endl;
            fileExist = true;
        }

        int index = 1;

        while(fileExist){

            fileName = "TicTacToe-Board";
            fileName += to_string(index);
            fileName += ".ppm";

            ifstream File(fileName);//create new file

            if(File){
                index++;
            }
            else{
                fileExist=false;
            }


        }


      int strokSize = n/20;//width of the borders   

        ofstream imageFile(fileName);//create new file

        cout << "netanel: " << fileName << endl;


        

        imageFile << "P6" << endl << length <<" " << width << endl << 255 << endl;

        RGB image[n*n];

        ////////draw board////////
        for (int i = 0; i < n; i++)  {  
            for (int j = 0; j < n; j++) { 
            image[n*i+j].red = (256 % 256);
            image[n*i+j].green = (125 % 256);
            image[n*i+j].blue = ( (255) % 256);
            }
        }

        for (int i = n/3-(strokSize/2); i < n/3+(strokSize/2); i++)  {  // row
            for (int j = 0; j < n; j++) { // column
            image[n*i+j].red = (256 % 256);
            image[n*i+j].green = (256 % 256);
            image[n*i+j].blue = ( 256 % 256);
            }
        }

        for (int i = n-(n/3)-(strokSize/2); i < n-(n/3)+(strokSize/2); i++)  {  // row
            for (int j = 0; j < n; j++) { // column
            image[n*i+j].red = (256 % 256);
            image[n*i+j].green = (256 % 256);
            image[n*i+j].blue = ( 256 % 256);
            }
        }

        for (int i = 0; i < n; i++)  {  // row
            for (int j = n/3-(strokSize/2); j < n/3+(strokSize/2); j++) { // column
            image[n*i+j].red = (256 % 256);
            image[n*i+j].green = (256 % 256);
            image[n*i+j].blue = ( 256 % 256);
            }
        }

        for (int i = 0; i < n; i++)  {  // row
            for (int j = n-(n/3)-(strokSize/2); j < n-(n/3)+(strokSize/2); j++) { // column
            image[n*i+j].red = (256 % 256);
            image[n*i+j].green = (256 % 256);
            image[n*i+j].blue = ( 256 % 256);
            }
        }

        //////////draw board - END//////////////////

        //////////draw signs///////////////////////////

        int BoardSize0 = size();
        int loc = n/3;

        RGB red{255,17,0};
        RGB whith{255,255,255};

        for(int i=0; i<BoardSize0; i++){
            for(int j=0; j<BoardSize0; j++){

                if(getBoardChar(i,j)=='X'){

                    int lineSize = 10;
                    int tab = n/12;
                    int start = loc+tab;
                    int end = loc-tab;
                    int rows = 100;
                    int count = 0;


                    for(int l=loc*i+tab; l<loc*(i+1)-tab ; l++){

                        for(int k=loc*j+tab+count; k<loc*j+tab+count+lineSize; k++){
                            image[n*l+k].red = (255 % 256);
                            image[n*l+k].green = (255 % 256);
                            image[n*l+k].blue = ( 255 % 256);
                        }

                        for(int k=loc*(j+1)-tab-count; k>loc*(j+1)-tab-count-lineSize; k--){
                            image[n*l+k].red = (255 % 256);
                            image[n*l+k].green = (255 % 256);
                            image[n*l+k].blue = ( 255 % 256);
                        }
                        count++;
                    }

                }

                else if(getBoardChar(i,j)=='O'){

                    for(int l=loc*i+50; l<loc*(i+1)-50 ; l++){
                        for(int k=loc*j+50; k<loc*(j+1)-50; k++){
                            image[n*l+k].red = (255 % 256);
                            image[n*l+k].green = (17 % 256);
                            image[n*l+k].blue = ( 0 % 256);
                        }
                    }

                }

            }
        }

        ///
        ///image processing
        /// 
        imageFile.write(reinterpret_cast<char*>(&image), 3*n*n);


    
        imageFile.close();
  

    return fileName; 

}


