//Create program which count and print file names in some folder
//using <sys/types.h> and <dirent.h>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <cstdlib>                  //for exit()
#include <pthread.h>                //for work with treads

void * calculate(void * str);
void * printPath(void * str);

int main(int argc, char * argv[])
{
    using namespace std;
    pthread_t first, second;
    int i1, i2;
    if(argc == 1)                   //check command line argument
    {
        cerr << "Usage: " << argv[0] << " no folder specified!\n";
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
    auto temp = (char *)str;
    DIR * dir = opendir(temp);
    if(!dir)                           //check directory
    {
        std::cerr << temp << " no existing directory\n";
        exit(EXIT_FAILURE);
    }
    int count = 0;
    //returns NULL when the end of the list of files in the directory is reached
    while(readdir(dir))
        count++;
    closedir(dir);
    std::cout << count << " files in folder " << temp << std::endl;
    return 0;                           //for return void *
}
void * printPath(void * str)
{
    auto temp = (char *)str;
    DIR * dir = opendir(temp);
    if(!dir)                           //check directory
    {
        std::cerr << temp << " no existing directory\n";
        exit(EXIT_FAILURE);
    }
    //returns NULL when the end of the list of files in the directory is reached
    //returns the following dirent structure read from the directory file
    while(auto entry = readdir(dir))
        std::cout << temp << "/" << entry->d_name << std::endl;
    closedir(dir);
    return 0;                           //for return void *
}
