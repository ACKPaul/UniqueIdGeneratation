#include<iostream>
#include "UniqueIdGenerator.h"
#include<thread>
#include <unordered_set> 


using namespace std; 


int main()
{
    auto previousTime = Clock::now();
    UniqueIdGenerator generator(1, 10, previousTime);

    unordered_set<uint64_t> uset; 

    // Simulate some delay
    std::this_thread::sleep_for(std::chrono::seconds(1));

    for(int i =0; i< 10000; i++)
    {
    
        uint64_t id = generator.getId();
        std::cout << "Unique ID: " << id << std::endl;

    if(uset.find(id) == uset.end())
    {
        uset.insert(id);
    }
    else 
    {
        cout<<"Conflict happned:: BOOM"<< id <<endl;
    }
    
    }

    return 0;
}