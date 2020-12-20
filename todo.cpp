#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<queue>
#include<time.h>
using namespace std;
#define DTTMFMT "%Y-%m-%d"
#define DTTMSZ 21

static char *getDtTm(char*buff){
    time_t t=time(0);
    strftime(buff,DTTMSZ, DTTMFMT, localtime(&t));
    return buff;
}


//help : Shows the usage
void help()
{
    cout<<"Usage :-";
    cout<<"\n$ ./todo add \"todo item \" # Add a new todo";
    cout<<"\n$ ./todo ls               # Show remaining todos";
    cout<<"\n$ ./todo del NUMBER       # Delete a todo";
    cout<<"\n$ ./todo done NUMBER      # Complete a todo";
    cout<<"\n$ ./todo help             # Show usage";
    cout<<"\n$ ./todo report           # Statistics";
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
    while( fin.getline(line,50))
    {
        q.push(line);
        count++;
    }
    fin.close();

    ofstream fout;
    fout.open("todo.txt");
    fout<<name;
    while(!q.empty())
    {
        fout<<"\n"<<q.front();
        q.pop();
    }
    cout<<"Added todo: "<<"\""<<name<<"\"";
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
     while(fin.getline(line,50))
    {
         count++;
    }
    fin.close();

    //printing all the to-dos in reverse order

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
        cout<<endl;
        fin.close();
    }
    else{
        cout<<"There are no pending todos!";
    }
}

void del(int num)
{

    vector<string>v;
    int count=0;
    char line[50];
    ifstream fin;
    fin.open("todo.txt");
    while(fin.getline(line,50))
    {
        count++;
    }
    fin.close();

   if(num<=count && num>=1)
   {
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
        cout<<"Deleted todo #"<<num;
   }
   else{
    cout<<"Error: todo #"<<num<<" does not exist. Nothing deleted.";
   }

}

//done : function to complete the todo
void done(int num)
{
    vector<string>v;
    int count=0;
    char line[50];
    ifstream fin;
    fin.open("todo.txt");
    while( fin.getline(line,50))
    {
        count++;
    }
    fin.close();

   if(num<=count && num>=1)
   {
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

        ifstream fr;
        fr.open("done.txt",ios::in);
        char ch[50];
        int k=0;
        while(fr.getline(ch,50))
        {
            k++;
        }
        fr.close();

        ofstream f1;
        f1.open("done.txt",ios::out|ios::app);
        if(k!=0)
            f1<<"\n";
        f1<<*itr;
        f1.close();
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
        cout<<"Marked todo #"<<num<<" as done.";
   }
   else{
    cout<<"Error: todo #"<<num<<" does not exist.";
   }

}

void report()
{
     ifstream fin;
     fin.open("todo.txt",ios::in);

     char line[50];
     int todo=0;

     //counting all the todos
     while( fin.getline(line,50))
    {
         todo++;
    }
    fin.close();
    fin.open("done.txt",ios::in);

     char ln[50];
     int dn=0;

     //counting all the todos
     while(fin.getline(ln,50))
    {
         dn++;
    }
    char buff[DTTMSZ];
    cout<< getDtTm(buff)<<" Pending : "<<todo<<" Completed : "<<dn;
    fin.close();

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
         if(argc==2)
           cout<<"Error: Missing todo string. Nothing added!";
         else
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

    }
    // calling the ls command
    else if(argv1=="ls")
        ls();
     else if(argv1=="del")
    {
         if(argc==2)
           cout<<"Error: Missing NUMBER for deleting todo.";
         else
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

    }
    else if(argv1=="done")
    {
        if(argc==2)
           cout<<"Error: Missing NUMBER for marking todo as done.";
        else
        {
            //converting string into integer value.
              std::string argv2=argv[2];

             int num=0;
             for(int i=0;i<argv2.length();i++)
             {
               int k=argv2[i]-48;
               num=num*10+k;
             }
             done(num);
        }

    }
    else if(argv1=="report")
    {
        report();
    }

    return 0;
}
