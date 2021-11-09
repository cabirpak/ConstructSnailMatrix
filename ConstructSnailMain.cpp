#include <iostream>
using namespace std;

int** constructSnailMatrix(int M, int N){
    if(M == 0 || N == 0)
        return nullptr;
    
    int** m=new int*[M];
    for(int i=0; i<M; i++)
        m[i] = new int[N];
    bool completed = false;
    int direction = 0;//0: right, 1: down, 2: left, 3: up
    int counter = 0;
    int x=0, y=0;
    
    //move limits
    int x_limit_start = 0;
    int x_limit_end = N;
    int y_limit_start = 0;
    int y_limit_end = M;
    
    cout << "started" << endl;
    
    //int loopCount = 0;
    
    // iterate through different directions and fill the elements
    while(counter < M*N){
        cout << "direction: " << direction << endl;
        
        //after doing actions for each direction, the limits and current 
        //  positions are updated
        
        if(direction == 0){
            for(x=x_limit_start; x<x_limit_end; x++){
                m[y][x] = ++counter;
            }
            x--;
            y_limit_start++;
        }
        else if(direction == 1){
            for(y=y_limit_start; y<y_limit_end; y++){
                cout << x << ", " << y << endl;
                m[y][x] = ++counter;
            }
            y--;
            x_limit_end--;
        }
        else if(direction == 2){
            for(x=x_limit_end-1; x>=x_limit_start; x--){
                m[y][x] = ++counter;
            }
            x++;
            y_limit_end--;
        }
        else if(direction == 3){
            for(y=y_limit_end-1; y>=y_limit_start; y--){
                m[y][x] = ++counter;
            }
            y++;
            x_limit_start++;
        }
        direction = (direction + 1) % 4;
        
        //for debugging aim
        /*for(int i =0; i<M; i++){
            for(int j=0; j<N; j++){
                cout << m[i][j] << "\t";
            }
            cout << endl;
        }*/
    }
    return m;
}

int main()
{
    //the test main
    
    int **m;
    m = constructSnailMatrix(5, 4);
    if(m == nullptr){
        cout << "empty matrix" << endl;
        return 0;
    }
    for(int i =0; i<5; i++){
        for(int j=0; j<4; j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
