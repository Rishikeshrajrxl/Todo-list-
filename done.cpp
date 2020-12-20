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
