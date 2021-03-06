//Create program which count and print file names in some folder
#include <iostream>
#include <cstdlib>                  //for exit()
#include <cstdio>
#include <filesystem>               //for work with folder and files
//#include <pthread.h>                //for work with treads

void * calculate(void * str);
void * printPath(void * str);

int main(int argc, char * argv[])
{
    using namespace std;
    using namespace std::filesystem;
    pthread_t first, second;
    int i1, i2;
    if(argc == 1)                   //check command line argument
    {
        cerr << "Usage: " << argv[0] << " no folder specified!\n";
        exit(EXIT_FAILURE);
    }
    if(!exists(argv[1]))            //check directory
    {
        cerr << argv[1] << " no existing directory\n";
        exit(EXIT_FAILURE);
    }
    auto path = argv[1];
    //start first tread with calculate()
    i1 = pthread_create(&first, nullptr, calculate, (void *)path);
    //start second tread whith printPath()
    i2 = pthread_create(&second, nullptr, printPath, (void *)path);

    pthread_join(first, nullptr);
    pthread_join(second, nullptr);

    cout << " Hi!\n";
    return 0;
}
void * calculate(void * str)
{
    using namespace std::filesystem;
    auto temp = (char *)str;
    int count = 0;
    for(const auto & entry : directory_iterator(temp))
    {
        if(exists(entry.path()))
            count++;
    }
    std::cout << count << " files in folder " << temp << std::endl;
}
void * printPath(void * str)
{
    using namespace std::filesystem;
    auto temp = (char *)str;
    for(const auto & entry : directory_iterator(temp))
    {
        if(exists(entry.path()))
            std::cout << entry.path() << std::endl;
    }
}
