#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Point2D
{
  Point2D(int x, int y): x(x),y(y){}
  int x;
  int y;
  bool state;

  void print()
  {
    std::cout<<"("<<x<<" , "<<y<<")"<<std::endl;
  }

};
int neighborCheck(Point2D point,Point2D limits);
vector<vector<bool>> generateBoard(Point2D limits);

std::vector<std::vector<bool>> board;
int main(){
  //inputs
  int columns;
  int lines;
  int turns;
  std::cin>>columns>>lines>>turns;
  Point2D limits(columns,lines);
  board = generateBoard(limits);



  return 0;
};
void readFromConsole(Point2D limits)
{
  for (int lin = 0; lin < limits.y; lin++)
  {
    std::string line;
    std::cin>>line;
    for (int col = 0; col < limits.x; col++) {
      board[lin][col] = line[col]=='#';
    }
  }
}
void step(Point2D limits) {
auto newBoard = board;

for(int l=0;l<limits.y;l++){
  for(int c=0; c<limits.x; c++) {
    auto neighbors = neighborCheck({c, l}, limits);
    auto isAlive = board[l][c];
    if(isAlive && (neighbors == 2 || neighbors == 3))
      newBoard[l][c] = true;
    else if(!isAlive && neighbors == 3)
      newBoard[l][c] = true;
    else
      newBoard[l][c] = false;
  }
}
board = newBoard;
}
    /*if(board[north.y][north.x])
    count++;*/
vector<vector<bool>> generateBoard(Point2D limits) {
  vector<vector<bool>> board;
  for(int lin=0; lin<limits.y; lin++){
    vector<bool> line;
    line.reserve(limits.x);
    for(int col=0; col<limits.x; col++)
      line.push_back(false);
    board.push_back(line);
  }
  return board;
}
Point2D getNorth(Point2D point, Point2D limits){
  point.y--;
  if(point.y < 0)
    point.y = limits.y-1;
  return point;
}
Point2D getSouth(Point2D point, Point2D limits)
{
  point.y++;
  if (point.y>0)
    point.y = limits.y+1;
  return point;

}
Point2D getEast(Point2D point, Point2D limits)
{
  point.x++;
  if (point.x>0)
  {
    point.x=limits.x+1;
  }
  return point;
}
Point2D getWest(Point2D point, Point2D limits)
{
  point.x--;
  if (point.x<0)
  {
    point.x=limits.x-1;
  }
  return point;
}
Point2D getNorthEast(Point2D point,Point2D limits)
{
  point.y--;
  if(point.y < 0)
    point.y = limits.y-1;
  point.x++;
  if (point.x>0)
  {
    point.x=limits.x+1;
  }
  return point;
}
Point2D getNorthWest(Point2D point,Point2D limits)
{
  point.y--;
  if(point.y < 0)
    point.y = limits.y-1;
  point.x--;
  if (point.x<0)
  {
    point.x=limits.x-1;
  }
  return point;

}
Point2D getSouthEast(Point2D point,Point2D limits)
{
  point.y++;
  if (point.y>0)
    point.y = limits.y+1;
  point.x++;
  if (point.x>0)
  {
    point.x=limits.x+1;
  }
  return point;
}

Point2D getSouthWest(Point2D point,Point2D limits)
{
  point.y++;
  if (point.y>0)
    point.y = limits.y+1;
  point.x--;
  if (point.x<0)
  {
    point.x=limits.x-1;
  }
  return point;
}
int neighborCheck(Point2D point,Point2D limits)
{
  int count;



  return getNorth(point,limits).state + getNorthEast(point,limits).state+ getEast(point,limits).state+ getSouthEast(point,limits).state+ getSouth(point,limits).state+ getSouthWest(point,limits).state+ getWest(point,limits).state+ getNorthWest(point,limits).state;

}

