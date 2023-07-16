#include<iostream>
using namespace std;

 char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 int row;
 int column;
 char input='x';
 bool draw=false;
 string a="";
 string b="";

void functionone()
{

   
    
    
    cout<<endl;
    cout<<"    |     |    \n";
    cout<<" "<<board[0][0]<<"  | "<<    board[0][1]<<"   | "<<board[0][2]<<" \n";
    cout<<"____|_____|____\n";
    cout<<"    |     |    \n";
    cout<<" "<<board[1][0]<<"  | "<<    board[1][1]<<"   | "<<board[1][2]<<" \n";
    cout<<"____|_____|____\n";
    cout<<"    |     |    \n";
    cout<<" "<<board[2][0]<<"  | "<<    board[2][1]<<"   | "<<board[2][2]<<" \n";
    cout<<"    |     |    \n";
 
}

void functiontwo()
{
   int n;
   if(input=='x'){
      cout<<a<<" it's your chance ";
      cin>>n;
   }
   if(input=='0'){
    cout<<b<<" it's your chance ";
    cin>>n;
   }
   if(n==1){
    row=0;
    column=0;
   }
   if(n==2){
    row=0;
    column=1;
   }
   if(n==3){
    row=0;
    column=2;
   }
   if(n==4){
    row=1;
    column=0;
   }
   if(n==5){
    row=1;
    column=1;
   }
   if(n==6){
    row=1;
    column=2;
   }
   if(n==7){
    row=2;
    column=0;
   }
   if(n==8){
    row=2;
    column=1;
   }
   if(n==9){
    row=2;
    column=2;
   }
   else if(n<1 || n>9) {
    cout<<"Invalid !!!"<<endl;
   }

   if(input=='x' && board[row][column] !='x' && board[row][column] !='0')
   {
    board[row][column]='x';
    input='0';
   }
   else if(input=='0' && board[row][column] !='x' && board[row][column] !='0')
   {
    board[row][column]='0';
    input='x';
   }
   else{
    cout<<"There is no empty space!"<<endl;
    functiontwo();
   }
     functionone();
}

bool functionthree()
{
   for(int i=0;i<3;i++)
   {
    if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[i][1] && board[0][i]==board[2][i])
    return true;
   
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] || board[0][2]==board[1][1] && board[1][1]==board[2][0])
    return true;
} 

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(board[i][j] !='x' && board[i][j] !='0'){
            return false;
        }
    }
}
  draw=true;
  return false;
}

int main(){
    cout<<"First Player : \n";
    getline(cin,a);
    cout<<"Second Player : \n";
    getline(cin,b);
    cout<<a<< " will start the game \n";
    while(!functionthree()){
        functionone();
        functiontwo();
        functionthree();
    }
    if (input=='0' && draw==false)
    {
        cout<<a<<" Wins!!!"<<endl;
        cout<<b<<" Lose"<<endl;
    }
    else if(input=='x' && draw==false)
    {
        cout<<b<<" Wins!!!"<<endl;
        cout<<a<<" Lose"<<endl;
    }
    else
    {
        cout<<"It's a draw!!"<<endl;
    }
}
