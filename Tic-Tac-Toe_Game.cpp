/*
work on different plans for different startings
*/


#include <iostream>
#include <string.h> //for memset
#include <cstdlib> //for rand()

using namespace std;

char paper[3][3];
int inRow, inCol;
int comp_turn_counter = 1;

void print();
void take_input();
void comp_input();
bool isVictory(char letter);
bool isComplete();
bool isVictory_X();
bool isVictory_O();
bool isDanger(bool *danger, int *danger_row, int *danger_col);

int main()
{
    //welcome message
    cout << "Welcome to tic-tac-toe!" << endl << endl;
    cout << "How to play:" << endl;
    cout << "-input row number" << endl;
    cout << "-input column number" << endl;
    cout << "-input method: press the number then press enter" << endl;
    cout << endl << "Have fun!" << endl << endl << endl;
    
    
    // calling a function should be included in another function --> can't be in the global
    memset(paper, '?', sizeof (paper)); //to change all elements of array(can't be treated as integers)
    
    while (!(isVictory_X()) && !(isVictory_O()) && !(isComplete()))
    {
        cout << "your turn: " << endl;
        take_input();
        print();
        if (!(isVictory_X()) && !(isVictory_O()) && !(isComplete()))
        {
            cout << "computer turn:" << endl;
            comp_input();
            print();
        }
    }
    
    if (isVictory_X())
    {
        cout << "X is the winner!";
    }
    else if (isVictory_O())
    {
        cout << "O is the winner!";
    }
    else if(isComplete())
    {
        cout << "draw!";
    }
    
    
    
    return 0;
}

bool isDanger(bool *danger, int *danger_row, int *danger_col)
{
    *danger = false;
    int counter = 0;
    //horizontal count
        for (int i = 0; i <= 2; i++)
        {
            counter = 0;
            for (int j = 0; j <= 2; j++)
            {
                if (paper[i][j] == 'X')
                    counter++;
                if (counter == 2)
                {
                    *danger = true;
                    break;
                }
            }
            //checking that the empty spot doesn't contain O
            if(*danger == true)
            {
                for(int j = 0; j <= 2; j++)
                {
                    if (paper[i][j] == 'O')
                    {
                        *danger = false;
                    }
                }
            }
            //iterating over row to find the empty spot
            if (*danger == true)
            {
                for(int j = 0; j <= 2; j++)
                {
                    if (paper[i][j] == '?')
                    {
                        *danger_row = i;
                        *danger_col = j;
                    }
                }
            }
            if (*danger == true)
                break;
        }
   
    //vertical counter
    if (*danger == false)
    {
        for (int i = 0; i <= 2; i++)
        {
            counter = 0;
            for (int j = 0; j <= 2; j++)
            {
                if (paper[j][i] == 'X')
                    counter++;
                if (counter == 2)
                {
                    *danger = true;
                    break;
                }
            }
            //checking that the empty spot doesn't contain O
            if(*danger == true)
            {
                for(int j = 0; j <= 2; j++)
                {
                    if (paper[j][i] == 'O')
                    {
                        *danger = false;
                    }
                }
            }
            //iterating over column to find the empty spot
            if (*danger == true)
            {
                for(int j = 0; j <= 2; j++)
                {
                    if (paper[j][i] == '?')
                    {
                        *danger_row = j;
                        *danger_col = i;
                    }
                }
            }
            if (*danger == true)
                break;
        }
    }
    
    //forward diagonal counter
    if (*danger == false)
    {
        counter = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (paper[i][i] == 'X')
                counter++;
            if (counter == 2)
            {
                *danger = true;
                break;
            }
        }
        //checking that the empty spot doesn't contain O
        if(*danger == true)
        {
            for(int i = 0; i <= 2; i++)
            {
                if (paper[i][i] == 'O')
                {
                    *danger = false;
                }
            }
        }
        //iterating over forward diagonal to find the empty spot
        if (*danger == true)
        {
            for(int i = 0; i <= 2; i++)
            {
                if (paper[i][i] == '?')
                {
                    *danger_row = i;
                    *danger_col = i;
                }
            }
        }
    }
    
    //backward diagonal count
    if (*danger == false)
    {
        counter = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (paper[i][2-i] == 'X')
                counter++;
            if (counter == 2)
            {
                *danger = true;
                break;
            }
        }
        //checking that the empty spot doesn't contain O
            if(*danger == true)
            {
                for(int i = 0; i <= 2; i++)
                {
                    if (paper[i][2-i] == 'O')
                    {
                        *danger = false;
                    }
                }
            }
        //iterating over backward diagonal to find the empty spot
            if (*danger == true)
            {
                for(int i = 0; i <= 2; i++)
                {
                    if (paper[i][2-i] == '?')
                    {
                        *danger_row = i;
                        *danger_col = 2-i;
                    }
                }
            }
    }
    
}

bool isComplete()
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (paper[i][j] == '?')
                return false;
        }
    }
    return true;
}

bool isVictory_X()
{
    if(isVictory('X'))
        return true;
    else
        return false;    
}

bool isVictory_O()
{
    if(isVictory('O'))
        return true;
    else
        return false;  
}

bool isVictory(char letter)
{
    bool victory;
    
    //horizontal check
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                victory = (paper[i][j] == letter);
                if (victory == false)
                    break;
            }
            if (victory == true)
                break;
        }
    }
   
    //vertical check
    if (victory == false)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                victory = (paper[j][i] == letter);
                if (victory == false)
                    break;
            }
            if (victory == true)
                break;
        }
    }
    
    //forward diagonal check
    if (victory == false)
    {
        for (int i = 0; i <= 2; i++)
        {
            victory = (paper[i][i] == letter);
                if (victory == false)
                    break;
        }
    }
    
    //backward diagonal check
    if (victory == false)
    {
        for (int i = 0; i <= 2; i++)
        {
            victory = (paper[i][2-i] == letter);
                if (victory == false)
                    break;
        }
    }
    
    return victory;
}

void comp_input()
{
    bool danger;
    int danger_row, danger_col;
    int randRow, randCol;
    
    isDanger(&danger, &danger_row, &danger_col);
    
    if(comp_turn_counter == 1)
    {
        bool forbiden;
        //forbiding the computer from putting the O in unwanted cells(middle cells)
        do
            {
                randRow = rand() % 3;
                randCol = rand() % 3;
                forbiden =  (randRow == 0 && randCol == 1) || //checking if the chosen cell is the middle cell in the top or bottom rows or left or right coloumns
                            (randRow == 1 && randCol == 0) ||
                            (randRow == 1 && randCol == 2) ||
                            (randRow == 2 && randCol == 1);
            }
            while (paper[randRow][randCol] != '?' || forbiden); // checking if the place is reserved 
            
            paper[randRow][randCol] = 'O';
            comp_turn_counter++;
    }
    else
    {
        if (danger == true)
        {
            paper[danger_row][danger_col] = 'O';
        }
        else
        {
            do
            {
                randRow = rand() % 3;
                randCol = rand() % 3;
            }
            while (paper[randRow][randCol] != '?'); // checking if the place is reserved
            
            paper[randRow][randCol] = 'O';
        }
    }
}

void take_input()
{
    bool pass;
    do
    {
        pass = true;
        cin >> inRow >> inCol;
        
        if(inRow < 1 || inRow > 3 || inCol < 1 || inCol > 3)
        {
            cout << "invalid input: out of range" << endl;
            pass = false;
        }
        
        else if (paper[inRow - 1][inCol - 1] != '?')
        {
            cout << "already reserved" << endl;
            pass = false;
        }
    }
    while (!pass);
    paper[inRow - 1][inCol - 1] = 'X';
}

void print()
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            cout << paper[i][j];
            if (j == 2)
                break;
            cout << "#";
        }
        cout << endl;
        if (i == 2)
            break;
        cout << "#####" << endl;
    }
    cout << endl;
}





