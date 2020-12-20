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
