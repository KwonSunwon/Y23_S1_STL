//-----------------------------------------------------------------------------
// save.cpp 한 학기 강의 저장하는 함수
//-----------------------------------------------------------------------------

#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include "save.h"

void save(const std::string& fileName)
{
    std::ifstream in{ fileName };

    std::ofstream out{ "2023_STL.txt", std::ios::app };

    out << '\n'
        << '\n'
        << '\n';

    auto now = std::chrono::system_clock::now();
    auto utc = std::chrono::system_clock::to_time_t(now);
    auto lt = std::localtime(&utc);

    auto old = out.imbue(std::locale("ko_KR"));
    out << "==============================================" << '\n';
    out << fileName << std::put_time(lt, "%x %A %X") << '\n';
    out << "==============================================" << '\n';
    out << '\n';
    out.imbue(old);

    std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>{out});
}

void git_commit(const std::string& msg)
{
    std::string cmd = "git add . && git commit -m \"" + msg + "\"";
	system(cmd.c_str());
}