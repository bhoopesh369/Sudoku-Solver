#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printVectorMatrix(vector<vector<int>> vec)
{ cout<<endl<<endl;
  for (int i = 0; i < vec.size(); i++)
  { cout<<"                   ";
    for (int j = 0; j < vec[i].size(); j++){
        cout<<vec[i][j]<<" ";
    }   
    cout << endl;
  }
}
int rowpos(vector<vector<int> > board)
{
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++){
        if(board[i][j]==0)
         return i;
    }  
  }
 return -1;
}
int colpos(vector<vector<int> > board)
{
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++){
        if(board[i][j]==0)
         return j;
    }  
  }
  return -1;
}
bool isUnique(vector<vector<int> > board ,int num)
{
  int row,col;
  row = rowpos(board);
  col = colpos(board);
  //checking row
  for(int i=0;i<board.size();i++)
  {
    if(board[row][i]==num)
     return false;  
  }
  //checking col
  for(int i=0;i<board.size();i++)
  {
    if(board[i][col]==num)
     return false;  
  }
  //checking individual boxes
  int rstart,cstart;
  rstart = row - (row%3);
  cstart = col - (col%3);
  for(int i=rstart;i<rstart+3;i++)
  {
    for(int j=cstart;j<cstart+3;j++)
    {
     if(board[i][j]==num)
      return false;  
    }   
  }
  return true;
}

void Sudoku(vector<vector<int> >board)
{
  int row,col;
  row = rowpos(board);
  col = colpos(board);

  if (row == -1)
  {
    printVectorMatrix(board);
    cout<<endl<<endl;
    return;
  }
  
  for(int i=1;i<=9;i++)
  {
      if(isUnique(board,i))
      {
          board[row][col]=i;
          Sudoku(board);
          //backtracking
          board[row][col]=0;
      }
  } 

}
int main()
{ 
  vector<vector<int> > board={ 
         {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} 
    };
  Sudoku(board);
  return 0;
}