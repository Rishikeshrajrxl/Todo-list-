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
