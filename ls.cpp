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
