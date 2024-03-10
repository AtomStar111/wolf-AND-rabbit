#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    bool gameOver = false;
    const int ROW = 100;
    const int COL = 100;
    int arr[ROW][COL];
    int w_x, w_y ;
    int r_x, r_y ;
    int wolf = 20, rabbit = 20 ;
    int step = 1;
    int step_w, step_r;
    int count_r = rabbit;
    int count_w = wolf;
    int life ;
    for(int i = 0 ; i < 20 ; i++)
    {
        w_x = rand() % COL;
        w_y = rand() % ROW;
        r_x = rand() % COL;
        r_y = rand() % ROW;
    }

    while(!gameOver)
    {
        cout<<"ХОД : "<<step<<"\t"<<"Число волков : "<<rabbit<<"\t"<<"Число заяц : "<<rabbit<<endl;
        cout<<endl;
        for(int i=0 ; i<ROW ; i++)
        {
            for(int j=0 ; j<COL ; j++)
            {
                arr[i][j] = 0;
                if( (w_x == j && w_y == i) || (r_x == j && r_y == i) )
                {
                    arr[w_y][w_x] = 1;
                    arr[r_y][r_x] = 1;
                }
                step_w = rand() % 8+1;
                switch(step_w)
                {
                    case 1:
                    w_x += 1;
                    break;

                    case 2:
                    w_x -= 1;
                    break;

                    case 3:
                    w_y += 1;
                    break;

                    case 4:
                    w_y -= 1;

                    case 5:
                    {
                        w_x += 1;
                        w_y += 1;
                    }
                    break;

                    case 6:
                    {
                        w_x -= 1;
                        w_y += 1;
                    }
                    break;

                    case 7:
                    {
                        w_x += 1;
                        w_y -= 1;
                    }
                    break;

                    case 8:
                    {
                        w_x -= 1;
                        w_y -= 1;
                    }
                    break;

                }
                step_r = rand() % 8+1;
                switch(step_r)
                {
                    case 1:
                    r_x += 1;
                    break;

                    case 2:
                    r_x -= 1;
                    break;

                    case 3:
                    r_y += 1;
                    break;

                    case 4:
                    r_y -= 1;
                    break;

                    case 5:
                    {
                        r_x += 1;
                        r_y += 1;
                    }
                    break;

                    case 6:
                    {
                        r_x -= 1;
                        r_y += 1;
                    }
                    break;

                    case 7:
                    {
                        r_x += 1;
                        r_y -= 1;
                    }
                    break;

                    case 8:
                    {
                        r_x -= 1;
                        r_y -= 1;
                    }
                    break;

                }
           
                if(w_x == r_x && w_y == r_y) {count_r -= 1; wolf += 1;}
                else if(w_x + 1 == r_x && w_y == r_y) {count_r -= 1; wolf +=1;}
                else if(w_x - 1 == r_x && w_y == r_y) {count_r -= 1; wolf +=1;}
                else if(w_x == r_x && w_y + 1 == r_y) {count_r -= 1; wolf +=1;}
                else if(w_x == r_x && w_y - 1 == r_y) {count_r -= 1; wolf +=1;}
                else if(w_x + 1 == r_x && w_y + 1 == r_y) {count_r -= 1; wolf +=1;}
                else if(w_x - 1 == r_x && w_y + 1 == r_y) {count_r -= 1; wolf +=1;}
                else if(w_x + 1 == r_x && w_y - 1 == r_y) {count_r -= 1; wolf +=1;}
                else if(w_x - 1 == r_x && w_y - 1 == r_y) {count_r -= 1; wolf +=1;}
                
                if(step % 3 == 0)
                {
                    if(count_r == rabbit)
                    {
                        count_r += 1;
                        rabbit += 1;
                    }
                }
                if(step % 5 == 0)
                {
                    if(count_r == rabbit)
                    {
                        wolf -= 1;
                    }
                }
                
                life = rand() % 20 + 15;
                if(life == step)
                {
                   rabbit -= 1;
                   wolf -= 1;
                }                
                                
                if(rabbit == 0 || wolf == 0)
                {
                    gameOver = true;
                }

            }
        }
        step++;
    }
}
