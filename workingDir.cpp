#include <filesystem>
#include <iostream>
// #include <experimental/filesystem>
// namespace fs = std::experimental::filesystem;
namespace fs = std::filesystem;
int main(int argc, char *argv[])
{
    if (argv[1] == nullptr)
    {
        std::cout << "부족한 인수 : 생성 디렉토리 이름";
    }
    fs::create_directory(fs::current_path() / argv[1]);
    fs::create_directory(fs::current_path() / argv[1] / "src");
    fs::create_directory(fs::current_path() / argv[1] / "obj");
}