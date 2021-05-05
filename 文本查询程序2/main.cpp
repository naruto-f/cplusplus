#include "TextQuery.h"
#include "QueryResult.h"


std::string make_plural(std::set<QueryResult::line_no>::size_type n, const std::string& m, const std::string& s)

{
    return (n > 1)?(m + s):m;
}

std::ostream& print(std::ostream& os, const QueryResult &res)
{
    os << res.sought << " occurs " << res.lines->size() << " " << make_plural(res.lines->size(), "time", "s") << std::endl;
    for(auto num : *(res.lines))
    {
        os << "\t(line " << num + 1 << ") " << *(res.file->begin() + num) << std::endl;
    }
    return os;
}

void runQueries(std::ifstream & infile)
{
    TextQuery tq(infile);
    while(true)
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        //若遇到文件尾或者输入q(quit)时循环终止
        if(!(std::cin >> s) || s == "q")
        {
             break;
        }
        print(std::cout, tq.query(s)) << std::endl;
        //std::cout << std::endl;
    }
}

int main()
{
    std::ifstream is("/mnt/c/Users/123456/CLionProjects/text/text.txt");  //注意：这里出现了一个使用相对路径读不出来文件的问题
    assert(is);                                                             //以后遇到这种问题要试着使用绝对路径是否能正确运行。
    runQueries(is);
    return 0;
}



