#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<queue>
using namespace std;

//help : Shows the usage
void help()
{
    cout<<"Usage :-"<<endl;
    cout<<" $ ./todo add \"todo item \"     # Add a new todo"<<endl;
    cout<<" $ ./todo ls                   # Show remaining todos"<<endl;
    cout<<" $ ./todo del NUMBER           # Delete a todo"<<endl;
    cout<<" $ ./todo done NUMBER          # Complete a todo"<<endl;
    cout<<" $ ./todo help                 # Show usage"<<endl;
    cout<<" $ ./todo report               # Statistics"<<endl;
}
//add : Add a new todo
void add(string name)
{
    ifstream fin;
    fin.open("todo.txt");

    queue<string>q;

    int count=0;
    char line[100];
    while(!fin.eof())
    {
        fin.getline(line,50);
        q.push(line);
        count++;
    }
    fin.close();
    ofstream fout;
    fout.open("todo.txt");
    fout<<name;
    while(count--)
    {
        fout<<"\n"<<q.front();
        q.pop();
    }
   cout<<"Added todo : "<<"\""<<name<<"\""<<endl;
   fout.close();

}

//ls : Show the remaining todo from todo.txt file
void ls()
{
    ifstream fin;
    fin.open("todo.txt");

     char line[50];
     int count=0;

     //counting all the todos
     while(!fin.eof())
    {
         fin.getline(line,50);
         count++;
    }
    fin.close();

    //printing all the to-dos in reverse order
    count-=1;
    if(count>0)
    {
        fin.open("todo.txt");
        int i=0;
        while(i<count)
        {
            fin.getline(line,100);
            cout<<"\n["<<count-i<<"] "<<line;
            i++;
        }
        fin.close();
    }
    else{
        cout<<"List is Empty"<<endl;
    }
}

int main(int argc, char* argv[])
{

        std::string argv1;
        //checking if it has more than 1 text in command line
        if(argc>1)
            argv1=argv[1];
        else if(argc==1)
            help();


    //calling the help command
    if(argv1=="help")
        help();

    // calling the add command
    else if(argv1=="add")
    {
        std::string name="";
        for(int i=2;i<argc;i++)
        {
            name=name+argv[i];
            if(argv[i+1]!=NULL)
               name+=" ";
        }
        add(name);
    }
    // calling the ls command
    else if(argv1=="ls")
        ls();

    return 0;
}
