#include <string> //using string
#include<sstream>
#include <iostream> //input output
#include <stdio.h> //using standard input output
#include <conio.h> //
#include <fstream> //file input output
#include <vector> //used arraylist datastructure 
#include <Windows.h>//used function sleep()
using namespace std;

//set global variable
struct person{
    string name="";
    string ic="";
    string pb=""; //pb =place of birth
    string type="";
    int vote=0;
};
vector <person> users;//arraylist datastructure

struct statesandcode{
    string states="";
    string votingcentre="";
    string placeofbirth[2];
};
vector <statesandcode> vcenter;//arraylist datastructure

//1. display message about commision
void displayCommisionMotto(){
    cout<<" Melonjak kearah negara maju!!"<<endl;
}

//display menu based on category

bool isInputValid(person user){
    if(user.name!=""&& user.ic!=""){
        return true;
    }else{
        return false;
    } 
}
string getPlaceOfBirth(string ic){
return ic.substr(6,2);
}

bool checkuserregistration(person user){
    bool isfound=false;
    for(auto data:users){
        if(user.name==data.name && user.ic==data.ic){
            isfound=true;
        }
    }
    return isfound;
}

void adduser(string type){
    person user;
    init : 
     if(type=="C"){
         cout<<" enter candidate name : ";
     }else{
         cout<<" enter voter name : ";
     }
     getline(cin,user.name);
     if(type=="C"){
         cout<<" enter candidate ic number :";
     }else{
         cout<<" enter voter ic number :";
     }
     
     getline(cin,user.ic);
     user.type=type;
     user.pb=getPlaceOfBirth(user.ic);
     user.vote=0;
     if(isInputValid(user)){
         if(!checkuserregistration(user)){
             users.push_back(user);
             cout<<"user successfully registered"<<endl;
             Sleep(500);
         }else{
             cout<<"already registered "<<endl;
             goto init;
         }
         
     }else{
         cout<<"invalid input";
     }
}

void displaycandidates(){
    for(auto data:users){
        cout<<data.name<<" "<<data.ic<<" "<<data.type<<" "<<data.vote<<endl;
    }
    cout<<endl;
    getch();
}

void updateuser(){
    person user;
    person updateduserdata;
    bool found=false;
    cout<<"enter previous name :";
    getline(cin,user.name);
    cout<<"enter previous ic :";
    getline(cin,user.ic);

    cout<<"enter new name :";
    getline(cin,updateduserdata.name);
    cout<<"enter new ic :";
    getline(cin,updateduserdata.ic);
    int i=0;
    if(isInputValid(user)){
        for(auto data:users){
            if(data.name==user.name && data.ic==user.ic){
                users.at(i).name=updateduserdata.name;
                users.at(i).ic=updateduserdata.ic;
                found=true;
                cout<<"Successful to update"<<endl;
                Sleep(600);
                break;
            }
            i++;
        }
    }

    if(!found){
        cout<<"fail to update"<<endl;
        getch();
    }
}

void deleteuser(){
 person candidate;
 bool found;
    cout<<"enter name :";
    getline(cin,candidate.name);
    cout<<"enter ic :";
    getline(cin,candidate.ic);
    int i=0;
    for(auto data:users){
        if(data.name==candidate.name && data.ic==candidate.ic){
            users.erase(users.begin()+i);
            cout<<"successful to delete"<<endl;
            Sleep(600);
            found=true;
            break;
        }
        i++;
    }
    if(!found){
        cout<<"fail to delete"<<endl;
        getch();
    }
}

void registerUser(string type){
    string option;
    if(type=="C"){
        cout<<"1=add candidate"<<endl;
        cout<<"2=update candidate data"<<endl;
        cout<<"3=delete candidate data"<<endl;
    }else{
        cout<<"1=add voter"<<endl;
        cout<<"2=update voter data"<<endl;
        cout<<"3=delete voter data"<<endl;
    }
    
    cout<<"enter your choice :";
    getline(cin,option);
    if(option=="1"){
        adduser(type);
    }else if(option=="2"){
       updateuser(); 
    }else if(option=="3"){
        deleteuser();
    }else{
        displaycandidates();
    }

}

void registerCandidate(){registerUser("C");}

void registerVoter(){registerUser("V");}

void checkVotingCentre(){
    person user;
    bool exist=false;
         cout<<" enter user name : ";
         getline(cin,user.name);
         cout<<" enter user ic number :"; 
         getline(cin,user.ic);
         for(auto userdata:users){
             if(user.name==userdata.name && user.ic==userdata.ic){
                 exist=true;
                for(auto statesdata:vcenter){
                    if(userdata.pb==statesdata.placeofbirth[0] || userdata.pb==statesdata.placeofbirth[1]){
                        cout<<"Name          :"<<userdata.name<<endl;
                        cout<<"IC Number     :"<<userdata.ic<<endl;
                        cout<<"Voting centre :"<<statesdata.votingcentre<<endl;
                        break;
                    }
                }
             }
             
         }
         if(!exist){
             cout<<"user not registered"<<endl;
         }
         getch();
}

void electionResult(){
    string votingcentre;
    cout<<"please enter voting center :";
    getline(cin,votingcentre);
    person temp[3];
    person tempc;
    int i=0;
    for(auto data:vcenter){
        if(data.votingcentre==votingcentre){
            for(auto candidate:users){
                if(candidate.pb==data.placeofbirth[0] || candidate.pb==data.placeofbirth[1]){
                    temp[i].name=candidate.name;
                    temp[i].vote=candidate.vote;
                    i++;
                }
            }
        }
    }
    //sort the candidate decending order based on vote
    for(int j=0;j<i;j++){
        for(int k=0;k<i-1;k++){
            if(temp[k].vote<temp[k+1].vote){
                tempc.ic=temp[k].ic;
                tempc.name=temp[k].name;
                tempc.pb=temp[k].pb;
                tempc.type=temp[k].type;
                tempc.vote=temp[k].vote;

                temp[k].ic=temp[k+1].ic;
                temp[k].name=temp[k+1].name;
                temp[k].pb=temp[k+1].pb;
                temp[k].type=temp[k+1].type;
                temp[k].vote=temp[k+1].vote;

                temp[k+1].ic=tempc.ic;
                temp[k+1].name=tempc.name;
                temp[k+1].pb=tempc.pb;
                temp[k+1].type=tempc.type;
                temp[k+1].vote=tempc.vote;

            }
        }
    }
    cout<<"Candidate           vote"<<endl;
    for(int l=0;l<i;l++){
        cout<<temp[l].name<<"               "<<temp[l].vote<<endl;
    }

    cout<<endl<<"The highest vote is "<<temp[0].vote<<" with majority of "<<temp[0].vote-temp[1].vote<<" vote"<<endl;
getch();
}

void adminMenu(){
    string choice;
    string type="";
    cout<<"1=Register candidate"<<endl;
    cout<<"2=Register voter"<<endl;
    cout<<"3=Check voting centre"<<endl;
    cout<<"4=Election result"<<endl;
    cout<<"Choice :";
    getline(cin,choice);
    if(choice=="1"){ 
        type="C";
        system("cls");      
        registerCandidate();
    }else if(choice=="2"){
        type="V";
        system("cls");
        registerVoter();
    }else if(choice=="3"){
        system("cls");
        checkVotingCentre();
    }else if(choice=="4"){
        system("cls");
       electionResult();
    }
    
}
bool checkvoter(person user){
    bool result=false;
    if(checkuserregistration(user)){
        for(auto data:users){
            if(user.ic==data.ic && data.vote==0){
                result=true;
            }
        }
    }else{
        result=false;
    }

    return result;
}

void votecandidate(string candidatename){
    int i=0;
    for(auto data:users){
        if(data.name==candidatename &&data.type=="C"){
            users[i].vote+=1;
        }
        i++;
    }
}

void electionDay(){
    person user;
    person tempcandidate[3];
    string choosen;
    cout<<"enter your name :";
    getline(cin,user.name);
    cout<<"enter your ic :";
    getline(cin,user.ic);
    if(checkvoter(user)){
                int i=0;
            for(auto data:vcenter){
                if(getPlaceOfBirth(user.ic)==data.placeofbirth[0] || getPlaceOfBirth(user.ic)==data.placeofbirth[1]){
                    for(auto canddata:users){
                            if(getPlaceOfBirth(user.ic)==canddata.pb){
                                if(canddata.type=="C"){
                                    tempcandidate[i].name=canddata.name;
                                    i++;
                                }
                                
                            }
                    }
                }
            }

            cout<<"Choose candidate ...."<<endl<<endl;
            for(int j=0;j<i;j++){
                cout<<j+1<<"="<<tempcandidate[j].name<<endl;
            }
            cout<<"Input:";
            getline(cin,choosen);
            int ch;
            stringstream geek(choosen);
            geek>>ch;
            if(ch>0 && ch<=i){
                votecandidate(tempcandidate[ch-1].name);
            }
    }else{
        cout<<"you are not registered or already vote the candidate!!"<<endl;
    }
    getch();
}

void  voterMenu(){
    string option;
    cout<< "1. check voting center "<<endl;
    cout<< "2. election day(choose candidate)"<<endl;
    getline(cin,option);
    if(option=="1"){
        checkVotingCentre();
    }else if(option=="2"){
        electionDay();
    }
}

void getCategory(string usertype){
    if(usertype=="A"||usertype=="a"){
        system("cls");
        adminMenu();
    }else if(usertype=="V"||usertype=="v"){
        system("cls");
        voterMenu();
        cout<<"voter menu"<<endl;
    }
}

void accessFile(){
    statesandcode statescode;
    ifstream myflstream("votingandstates.txt");
    if(!myflstream.is_open()){
        cout<<"fail to open the file"<<endl;
    }
    string line;
    int i=0;
    while(getline(myflstream,line)){
        stringstream ss(line);
        getline(ss,statescode.states,',');
        getline(ss,statescode.votingcentre,',');
        getline(ss,statescode.placeofbirth[0],',');
        getline(ss,statescode.placeofbirth[1],',');
        vcenter.push_back(statescode);
        i++;
    }
myflstream.close();
}

void accessUsersfile(){
    person user;
    ifstream myflstream("users.txt");
    if(!myflstream.is_open()){
        cout<<"fail to open the file"<<endl;
    }
    string line;

    string vote;
    while(getline(myflstream,line)){
        stringstream ss(line);
        getline(ss,user.name,',');
        getline(ss,user.ic,',');
        getline(ss,user.pb,',');
        getline(ss,user.type,',');
        getline(ss,vote,',');
        stringstream numvote(vote);
        numvote>>user.vote; 
        users.push_back(user);
    }
}


void writeIntoUsersFile(){
    ofstream file("users.txt",ios::in|ios::out|ios::app);
    if(file.is_open()){
        for(auto data:users){
            file<<data.name<<","<<data.ic<<","<<data.pb<<","<<data.type<<","<<data.vote<<"\n";
        }
            
    }
}
 int main(){
     accessFile();
     accessUsersfile();
     string category;
     string choice="0";
         //step 1-display commision motto
       //displayCommisionMotto();
       while(choice!="2"){
           system("cls");
            cout<<"1=select category"<<endl;
            cout<<"2=exit"<<endl;
            cout<<" select your choice :";
            getline(cin,choice);

            if(choice=="1"){
                    system("cls");
                    //step 2-choose category
                    cout<<"A or a=Admin"<<endl;
                    cout<<"V or v=voter"<<endl;
                    cout<<"B or b=back to main"<<endl;
                    cout<<" please select your category :";
                    getline(cin,category);
                    // evaluate the category
                    getCategory(category);
            }else if(choice=="2"){
                writeIntoUsersFile();
            }

       }
    return 0;
}