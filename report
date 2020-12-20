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
