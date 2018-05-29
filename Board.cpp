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


        int strokSize = 2;//width of the borders   

        ofstream imageFile(fileName);//create new file

        imageFile << "P6" << endl << length <<" " << width << endl << 255 << endl;

        //crate array of Rgb objects
        RGB image[n*n];

        //draw board background
        for (int i = 0; i < n; i++)  {  
            for (int j = 0; j < n; j++) { 
            image[n*i+j].red = (256 % 256);
            image[n*i+j].green = (125 % 256);
            image[n*i+j].blue = ( (255) % 256);
            }
        }

        int border = 1;
        int BoardSize0 = size();
        int part = n/BoardSize0;


        //draw board borders
        while(border<BoardSize0){

            for (int i = (n-part*(border))-(strokSize/2); i < (n-part*(border))+(strokSize/2); i++)  {
                for (int j = 0; j < n; j++) {
                    image[n*i+j].red = (256 % 256);
                    image[n*i+j].green = (256 % 256);
                    image[n*i+j].blue = ( 256 % 256);
                }
            }

            for (int i = 0; i < n; i++)  {
                for (int j = (n-part*border)-(strokSize/2); j <(n-part*border)+(strokSize/2); j++) {
                image[n*i+j].red = (256 % 256);
                image[n*i+j].green = (256 % 256);
                image[n*i+j].blue = ( 256 % 256);
                }
            }

            border++;

        }
        ////////draw board - END//////////////////



        ////////draw signs///////////////////////////

        int loc = n/BoardSize0;

        RGB red{255,17,0};
        RGB whith{255,255,255};

        for(int i=BoardSize0-1; i>=0; i--){
            for(int j=BoardSize0-1; j>=0; j--){

                if(getBoardChar(i,j)=='X'){

                    cout << "i= " << i << " j= " << j << endl;

                    int JstartX = (n-part*(BoardSize0-j))+(strokSize/2);
                    cout << "Jstart: " <<JstartX << endl;
                    int JendX = (n-part*(BoardSize0-j-1))-(strokSize/2);
                    cout << "Jend: " <<JendX<< endl;

                    int JdiffX = JendX-JstartX;
                    // cout << "diff: " << JdiffX << endl;


                    int IstartX = (n-part*(BoardSize0-i))+(strokSize/2);
                    cout << "Istart: " <<IstartX << endl;
                    int IendX = (n-part*(BoardSize0-i-1))-(strokSize/2);
                    cout << "Iend: " <<IendX<< endl;

                    int IdiffX = IendX-IstartX;
                    cout << "diff: " << IdiffX << endl;

                    // int tabX2 = Idiff/15;


                    int lineSize = 3;
                    int tab =0;
                    int tabX = n/(BoardSize0*3);
                    int start = loc+tab;
                    int end = loc-tab;
                    int rows = n;
                    int count = 0;
                    int counter = 0;

                    for(int l=IstartX+tab+1; l<IendX-tab-1; l++){

                        for(int k=JstartX+count+1; k<JstartX+count+lineSize; k++){
                            image[n*l+k].red = (255 % 256);
                            image[n*l+k].green = (255 % 256);
                            image[n*l+k].blue = ( 255 % 256);
                        }

                        for(int k=JendX-count-1; k>JendX-count-lineSize; k--){
                            image[n*l+k].red = (255 % 256);
                            image[n*l+k].green = (255 % 256);
                            image[n*l+k].blue = ( 255 % 256);
                        }

                        
                        // if(counter%2==0){
                        //     count+=1;
                        // }
                        count++;
                    }

                }

                else if(getBoardChar(i,j)=='O'){

                    // cout << "i= " << i << " j= " << j << endl;


                    int Jstart = (n-part*(BoardSize0-j))+(strokSize/2);
                    // cout << "start: " <<Jstart << endl;
                    int Jend = (n-part*(BoardSize0-j-1))-(strokSize/2);
                    // cout << "end: " <<Jend<< endl;

                    int Jdiff = Jend-Jstart;
                    // cout << "diff: " << Jdiff << endl;


                    // cout << "//////////IIIIIIIIII//////////" << endl;


                    int Istart = (n-part*(BoardSize0-i))+(strokSize/2);
                    // cout << "start: " <<Istart << endl;
                    int Iend = (n-part*(BoardSize0-i-1))-(strokSize/2);
                    // cout << "end: " <<Iend<< endl;

                    int Idiff = Iend-Istart;
                    // cout << "diff: " << Idiff << endl;

                    int tab = Idiff/15;
                    

                        for(int l=Iend-strokSize-tab; l>=Istart+strokSize+tab; l--){
                        for(int k=Jend-strokSize-tab; k>=Jstart+strokSize+tab; k--){
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


