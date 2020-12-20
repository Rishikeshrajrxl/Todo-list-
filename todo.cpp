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
    cout<<" $ ./todo report               # Statistics";
}
//add : Add a new todo
/* For adding new todo item in the beginning
   Here I have used queue data structure     */
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
    cout<<"Added todo : "<<"\""<<name<<"\"";
    fout.close();

}

//ls : Show the remaining todo from todo.txt file
void ls()
{
    ifstream fin;
    fin.open("todo.txt",ios::in);

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
        fin.open("todo.txt",ios::in);
        int i=0;
        while(i<count)
        {
            if(fin.tellg()!=0)
                cout<<"\n";

            fin.getline(line,100);
            cout<<"["<<count-i<<"] "<<line;
            i++;

        }
        fin.close();
    }
    else{
        cout<<"List is Empty";
    }
}

void del(int num)
{

    vector<string>v;
    int count=0;
    char line[50];
    ifstream fin;
    fin.open("todo.txt");
    while(fin)
    {
        fin.getline(line,50);
        count++;
    }
    count--;
    fin.close();

    fin.open("todo.txt");
    int i=0;
    while(i<count)
    {
        fin.getline(line,50);
        v.push_back(line);
        i++;
    }
    fin.close();

    int diff=count-num;
    vector<string>::iterator itr;
    itr=v.begin();
    itr+=diff;
    v.erase(itr);

    ofstream fout;
    fout.open("todo.txt",ios::out);

    for(auto i=v.begin();i!=v.end();i++)
    {
        fout<<*i;
        if((i+1)!=v.end())
            fout<<"\n";
    }
        fout.close();
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
     else if(argv1=="del")
    {
        //converting string into integer value.
        std::string argv2=argv[2];
            int num=0;
           for(int i=0;i<argv2.length();i++)
           {
               int k=argv2[i]-48;
               num=num*10+k;
           }
        del(num);
    }

    return 0;
}
