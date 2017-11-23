
#include <iostream>
#include <conio.h>
#include <windows.h>
#include<dos.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[50], tailY[50];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

 int ch;// for levels

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail=0;
}
void Draw()
{
    system("cls"); //system("clear");
     cout<<"---------------------------------------------LEVEL "<<ch<<"----------------------------------------------------\n\n\n\n";

    cout<<"\t\t\t\t";//change****
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
       cout<<"\t\t\t\t";//change****
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }


            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
   cout<<"\t\t\t\t"; //change****
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;



    cout<<"\t\t\t\t"; //change****
    cout << "Score:" << score << endl;



    if(ch==1 && score==30)
        gameOver=true;

}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }


  if(ch==1)  //in level 1 snake touches boundary comes from other side
    {  if (x >= width) x = 0; else if (x < 0) x = width - 1;
       if (y >= height) y = 0; else if (y < 0) y = height - 1;
    }

else   //in level 2 if snake touches boundary GAMEOVER
     {  if (x > width || x < 0 || y > height || y < 0)
        gameOver =true;
      }

    for (int i = 0; i < nTail; i++)  //if tail touches head
        if (tailX[i] == x && tailY[i] == y)
            gameOver =true;

    if (x == fruitX && y == fruitY) //eats fruit length increases
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }


}



int main()
{



        for(int i=0;i<59;i++)
       {cout<<"--";}

        cout<<"\t\t\t\t\t\t\tSNAKE GAME"<<endl;

            for(int i=0;i<59;i++)
            {cout<<"--";}
            cout<<endl<<endl;

            cout<"\n\n\n";
         for(int i=0;i<16;i++)
               {cout<<"  ";}
            for(int i=0;i<20;i++)
                {cout<<"--";}
        cout<<" \n\t\t\t\tBY ABDUL WAHED AND ABRAR ATHAR HASHMI\n";
        for(int i=0;i<16;i++)
               {cout<<"  ";}
            for(int i=0;i<20;i++)
                {cout<<"--";}

 system("color 0a");
 cout<<"\n\n\n\t\t\t\t\tPlease wait while loading\n\n";
 char a=177, b=219;
 cout<<"\t\t\t\t\t";
 for (int i=0;i<=15;i++)
 cout<<a;
 cout<<"\r";
 cout<<"\t\t\t\t\t";
 for (int i=0;i<=15;i++)
 {
  cout<<b;
  for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
 }
   system("cls");

        for(int i=0;i<59;i++)
            {cout<<"--";}
        cout<<"\t\t\t\t\t\t\tLEVELS"<<endl;
            for(int i=0;i<59;i++)
                {cout<<"--";}



                for(int i=0;i<20;i++)
                {cout<<"\t\t\t\t";}
            for(int i=0;i<20;i++)
                {cout<<"--";}

        cout<<"\n\t\t\t\t\t SELECT DIFFICULTY "<<endl;

            for(int i=0;i<16;i++)
               {cout<<"  ";}
            for(int i=0;i<20;i++)
                {cout<<"--";}

      cout<<"\n\t\t\t\t\t    LEVEL 1"<<endl<<endl;
      cout<<"\n\t\t\t\t\t    LEVEL 2"<<endl;

      cout<<"\n\t\t\t\t\t  ENTER YOUR CHOICE:";
       cin>>ch;

      if(ch==1)
    cout<<"******INSTRUCTION : snake CAN touch the barrier ";
     else
        cout<<"*******INSTRUCTION : snake CANNOT touch the barrier ";


        system("cls");
        cout<<"\n\n\t\t\t\tGAME LOADING";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";




   switch(ch)
  {
      case 1:


            Setup();
                while (!gameOver)
                {
                 Draw();
                 Input();
                 Logic();
                 Sleep(10); //sleep(10);
                }

            int t;
             if(score!=30)
               {
                system("cls");
                cout<<"\n\n\t\t\t\t*****GAME OVER******";
                cout <<"\tScore:" <<score<< endl;
                cin>>t;
                break;
                }
            else
             {
                cout<<"\n\t\t\t***congratulations LEVEL 1 completed";
                Sleep(1000);
                cout<<".";
                Sleep(1000);
                cout<<".";

                system("cls");
                cout<<"\n\t\tENTERING LEVEL 2";
                Sleep(1000);
                cout<<".";
                Sleep(1000);
                cout<<".";

                system("cls");

                ch=2;

            }


      case 2:

            ch=2;

      gameOver =false;




            Setup();
                while (!gameOver)
                {
                 Draw();
                 Input();
                 Logic();
                 Sleep(10); //sleep(10);
                }

                Sleep(1000);
                cout<<".";

                system("cls");

              cout<<" \n\n\n\n\n\t\t\t\t*****GAME OVER******";
              cout << "\n\n\t\t\tScore:" << score << endl;

            break;

         }
        Sleep(1000);
        cout<<".";

        system("cls");
        cout<<"\n\n\n\t\t\t\tTHANK YOU FOR PLAYING";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
 return 0;
}
