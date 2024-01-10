#include<iostream>
#include<vector>
using namespace std;
long long score1=0, score2=0;

void display(vector<vector<char>> &arr, string &p1, char &ch1, string &p2, char &ch2){
    cout<<endl<<"\tNote :-"<<ch1<<"'s :-"<<p1;
    cout<<endl<<"\t  "<<ch2<<"'s :-"<<p2;
    cout<<endl<<endl;
    int num=0;
    for(auto i=0; i<3 ; i++){
        cout<<"\t";
        for(auto j=0 ; j<3 ; j++){
            ++num;
            if(arr[i][j] == ch1)
               cout<<" "<<ch1<<" ";
            else if(arr[i][j] == ch2)
               cout<<" "<<ch2<<" ";
            else
               cout<<" "<<num<<" ";

            if(j != 2)
               cout<<"|";
        }
        if(i !=2)
          cout<<endl<<"\t---|---|---"<<endl;
    }
    cout<<endl;
}

int ver_check(vector<vector<char>>&arr,char &ch){

    //all vertical positions
    int count1=0,count2=0,count3=0;
    for(auto i=0;i<3;i++){
        if(arr[i][0] == ch)  ++count1;
        if(arr[i][1] == ch)  ++count2;
        if(arr[i][2] == ch)  ++count3;
    }

    if(count1==3 || count2==3 || count3==3)
      return 1;
    return 0;
}

int hor_check(vector<vector<char>>&arr, char &ch){

    //all horizontal positions
    vector<int> count(3,0);
    for(auto i=0; i<3; i++){
        for(auto j=0; j<3; j++){
            if(arr[i][j] == ch)
              ++count[i];
        }
    }

    if(count[0]==3 || count[1]==3 || count[2]==3)
       return 1;
    return 0;
}

int dia_check(vector<vector<char>> &arr, char &ch){

    //diagonal positions checking
    int count1=0, count2=0;
    for(auto i=0; i<3; i++){
        if(arr[i][i] == ch)   ++count1;
        if(arr[i][2-i] == ch)  ++count2;
    }

    if(count1==3 || count2==3)
       return 1;
    return 0;   
}

int match_result(vector<vector<char>> &arr, char &ch){
    if(ver_check(arr, ch)==0){
        if(hor_check(arr, ch)==0){
            if(dia_check(arr,ch)==0){
                return 0;
            }
            else
              return 1;
        }
        else
           return 1;
    }
    else 
       return 1;
}

void TicTacToe(vector<vector<char>> &arr){

    string p1,p2;
    char ch1,ch2;
    int p1_ind, p2_ind, win=0, board_fill=0;

    cout<<endl<<" Note :- player-1 will start the game always";
    cout<<endl<<"  so,enter the players name accordingly\n";

    cout<<endl<<"enter player-1 name=";
    getline(cin,p1);
    cout<<"enter player-2 name=";
    getline(cin, p2);
    cout<<endl;

    //player-1 entry until valid character found
    for(int i=1; i>0; i++){
        cout<<"enter player-1 choice (X or O)=";
        cin>>ch1;
        fflush(stdin);
        ch1=toupper(ch1);
        if(ch1=='x' || ch1=='X' || ch1=='o' || ch1=='O')
          break;
        else
          cout<<"WARNING! =only X or O is accepted. Enter again to continue.\n"<<endl;
    }

    //player-2 character to be alternate
    ch1 == 'X' ? ch2 == 'O' : ch2 = 'X';
    cout<<"now player-2 choice is ="<<ch2<<endl;

    //Initially
    display(arr, p1, ch1, p2, ch2);
    cout<<endl<<"REMARKS:-Start the match"<<endl;

    while(win!=1){
        //1st player's mark entry until valid mark found
        for(int i=1; i>0; i++){
            cout<<endl<<p1<<"'s turn : enter any integer shown to put your mark =";
            cin>>p1_ind;
            fflush(stdin);
            --p1_ind;
            if(p1_ind>=0 && p1_ind<=8 && arr[p1_ind/3][p1_ind%3]==0){
                arr[p1_ind/3][p1_ind%3] = ch1;
                break;
            }
            else if(p1_ind>=0 && p1_ind<=8 && arr[p1_ind/3][p1_ind%3]!=0)
                cout<<"enter only the vacant place that doesn't contain any previous mark"<<endl;
            else
                cout<<"WARNING! = enter only among the numbers shown "<<endl;    
        }
        board_fill +=1;
        display(arr, p1, ch1, p2, ch2);
        win = match_result(arr,ch1);
        cout<<endl<<"REMARKS :- ";
        if(win == 1){
            cout<<"Congratulations,"<<p1<<"   has won the game"<<endl;
            ++score1;
            return;
        }
        else if(board_fill==9){
            cout<<"Match DRAW"<<endl;
            return;
        }
        else
           cout<<"Hold on your breath, match is ongoing"<<endl;

        //2nd player's mark entry until valid mark found
        for(int i=1; i>0; i++){
            cout<<endl<<p2<<"'s turn : enter any integer shown to put your mark =";
            cin>>p2_ind;
            fflush(stdin);
            --p2_ind;
            if(p2_ind>=0 && p2_ind<=8 && arr[p2_ind/3][p2_ind%3]==0){
                arr[p2_ind/3][p2_ind%3] = ch2;
                break;
            }
            else if(p2_ind>=0 && p2_ind<=8 && arr[p2_ind/3][p2_ind%3]!=0)
                cout<<"enter only the vacant place that doesn't contain any previous mark"<<endl;
            else 
                cout<<"WARNING! = enter only among the numbers shown"<<endl;
        }
        board_fill +=1;
        display(arr, p1, ch1, p2, ch2);
        win = match_result(arr, ch2);
        cout<<endl<<"REMARKS :-";
        if(win==1){
            cout<<"Congratulations,"<<p2<<"   has won the game"<<endl;
            ++score2;
            return;
        }
        else if(board_fill==9){
            cout<<"Match DRAW"<<endl;
            return;
        }
        else 
           cout<<"Hold on your breath,match is ongoing"<<endl;
    }
}

int main(){
    string quit;
    cout<<endl;
    cout<<"\t  Welcome to Tic Tac Toe game\n";
    cout<<"\t  let's start and have some fun\n";

    //start
    while( quit.size()==0 || quit[0]=='y' || quit[0]=='Y'){
        //3x3 matrix
        vector<vector<char>>arr(3, vector<char>(3,0));

        TicTacToe(arr);

        //exit_block
        cout<<endl<<"want to play another game? (y/n) =";
        getline(cin,quit);

        //clear matrix
        arr.clear();
        arr.shrink_to_fit();

    }
    cout<<endl<<"come back again.Have a nice day"<<endl;
    return 0;
}