#include<time.h>

struct Block{
bool full;
Ant* a;
  
};
Class GameField1
{
private:
int width, height;
int nblue,nred;
int nummoves;
bool turn;//false for red, true for blue
Block** Field;
vector<Ant*> blueTeam,redTeam;

public:

GameField1(int width,int height,int n,int nblue,int nred)
{
  
srand(time(NULL));
this->width=width;
this->height=height;
turn=false;
this->nummoves=n;
this->nred=nred;
this->nblue=nblue;
Field=new Block[height][width];
//randomly fill field right side
int i=0,x,y;

while(i<nblue)
{
  
  x=rand()%width/2;
  y=rand()%height;
  if(i==0)
  {
    Field[x+width/2][y].full=true;
    Field[x+width/2][y].a=new Ant(Color::Blue,Heirarchy::Queen);
    i++;
    continue;
  }
  
  if(Field[x+width/2][y].full)
    continue;
    
    
  Field[x+width/2][y].full=true;
  if(i%3==0)
   Field[x+width/2][y].a=new Ant(Color::Blue,Heirarchy::Worker);
  if(i%3==1)
   Field[x+width/2][y].a=new Ant(Color::Blue,Heirarchy::Soldier);
   if(i%3==2)
   Field[x+width/2][y].a=new Ant(Color::Blue,Heirarchy::Knight);
   i++;
   
}

while(i<nred)
{
  
  x=rand()%width/2;
  y=rand()%height;
  if(i==0)
  {
    Field[x][y].full=true;
    Field[x][y].a=new Ant(Color::Red,Heirarchy::Queen);
    i++;
    continue;
  }
  
  if(Field[x][y].full)
    continue;
    
    
  Field[x][y].full=true;
  if(i%3==0)
   Field[x][y].a=new Ant(Color::Red,Heirarchy::Worker);
  if(i%3==1)
   Field[x][y].a=new Ant(Color::Red,Heirarchy::Soldier);
   if(i%3==2)
   Field[x][y].a=new Ant(Color::Red,Heirarchy::Knight);
   i++;
   
}

}
