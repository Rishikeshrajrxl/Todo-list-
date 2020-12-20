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
