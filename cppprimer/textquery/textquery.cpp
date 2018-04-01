#include <iostream>
#include<string>
#include<boost/shared_ptr.hpp>
#include<set>
#include<vector>
#include<map>
#include<fstream>
#include<sstream>
using std:: cout;
using std:: endl;
using std:: map;
using std:: vector;
using std:: string;
using std:: shared_ptr;
using std:: ifstream;
using std:: ostream;
using std:: set;
using std:: istringstream;

class QueryResult;
class TextQuery
{
public:
    using line_no=vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>>file;
    map<string,shared_ptr<set<line_no> > >wm;
};

TextQuery::TextQuery(ifstream&is):file(new vector<string>)
{
    string text;
    while(getline(is,text))
    {
        file->push_back(text);
        int n=file->size()-1;
        istringstream line(text);
        string word;
        while(line>>word)
        {
            auto &lines=wm[word];
            if(!lines)
            lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

class QueryResult
{
friend ostream&print(ostream&,const QueryResult&);
public:
    using line_no=vector<string>::size_type;
    QueryResult(string s,shared_ptr<set<line_no> >p,shared_ptr<vector<string> >f):sought(s),lines(p),file(f){}

private:
    string sought;
    shared_ptr<set<line_no> > lines;
    shared_ptr<vector<string> >file;
};

ostream &print(ostream&os,const QueryResult &qr)
{
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" times"<<endl;
    
    for(auto num:*qr.lines)
    os<<"\t(line "<<num+1<<") "<<*(qr.file->begin()+num)<<endl;
    return os;
}

QueryResult TextQuery::query(const string &sought)const
{
    static shared_ptr<set<line_no>>nodata(new set<line_no>);

    auto loc=wm.find(sought);
    if(loc==wm.end())
        return QueryResult(sought,nodata,file);
    else
        return QueryResult(sought,loc->second,file);

}
int main(int argc, char *argv[])
{
    ifstream is("a.txt");
    TextQuery tqy(is); 
    
    print(cout,QueryResult(tqy.query(string("hello"))));
	return 0;
}
