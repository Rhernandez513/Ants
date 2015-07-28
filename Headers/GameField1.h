
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
GameField1(int width,int height,int n,int nblue,int nred);



}
