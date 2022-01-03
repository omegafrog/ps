#include <filesystem>
#include <iostream>
// #include <experimental/filesystem>
// namespace fs = std::experimental::filesystem;
namespace fs = std::filesystem;
int main(int argc, char *argv[])
{
    fs::create_directory(fs::current_path() / argv[1]);
    fs::create_directory(fs::current_path() / argv[1] / "src");
    fs::create_directory(fs::current_path() / argv[1] / "obj");
}