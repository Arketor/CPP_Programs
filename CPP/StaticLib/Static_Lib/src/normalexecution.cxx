#include <iostream>
#include <boost/thread.hpp>
#include <algorithm> 
#include <chrono> 
#include<vector> 
using namespace std;
using boost::thread;
using boost::mutex;
using namespace std::chrono; 

mutex a;

int p[1000004];
void worker(int a) {
    int j;
    for(j=2;(j*j)<=a;j++)
    {
        if((a%j)==0)
        {
            p[a]=0;
            break;
        }
    }


}
void sol1(int a,int b)
{
    for(;a<=b;a++)
    worker(a);
}
void sol2(int a,int b)
{
    for(;a<=b;a++)
    worker(a);
}
void sol3(int a,int b)
{
    for(;a<=b;a++)
    worker(a);
}

void sol4(int a,int b)
{
    for(;a<=b;a++)
    worker(a);
}
void sol5(int a,int b)
{
    for(;a<=b;a++)
    worker(a);
}
void sol6(int a,int b)
{
    for(;a<=b;a++)
    worker(a);
}
void sol7(int a,int b)
{
    for(;a<=b;a++)
    worker(a);
}
void sol8(int a,int b)
{
    for(;a<=b;a++)
    worker(a);
}






int main(int argc, char** argv)
{

    memset(p,1,sizeof(p));
    
    thread *threads[3];
    
    auto start = high_resolution_clock::now(); 

    threads[0] = new thread(sol1,2,33000);
    threads[1] = new thread(sol2,33001,66000);
    threads[2] = new thread(sol3,66001,100000);
    threads[0]->join();
    threads[1]->join();
    threads[2]->join();
auto stop = high_resolution_clock::now(); 
auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    delete threads[0];
    delete threads[1];
    delete threads[2];
     memset(p,1,sizeof(p));
   

     start = high_resolution_clock::now();
    sol1(2,100000);
 stop = high_resolution_clock::now();
 duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 


 memset(p,1,sizeof(p));
    thread *threads2[6];
    start = high_resolution_clock::now();
    threads2[0] = new thread(sol1,1,16666);
    threads2[1] = new thread(sol2,16667,33332);
    threads2[2] = new thread(sol3,33333,49998);
    threads2[3] = new thread(sol4,49999,66664);
    threads2[4] = new thread(sol5,66665,83330);
    threads2[5] = new thread(sol6,83331,100000);
    threads2[0]->join();
    threads2[1]->join();
    threads2[2]->join();
    threads2[3]->join();
    threads2[4]->join();
    threads2[5]->join();
 stop = high_resolution_clock::now();
 duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    delete threads2[0];
    delete threads2[1];
    delete threads2[2];
delete threads2[3];
    delete threads2[4];
    delete threads2[5];
















 memset(p,1,sizeof(p));
    thread *threads3[8];
    start = high_resolution_clock::now();
    threads3[0] = new thread(sol1,1,12500);
    threads3[1] = new thread(sol2,12501,25000);
    threads3[2] = new thread(sol3,25001,37500);
    threads3[3] = new thread(sol4,37501,50000);
    threads3[4] = new thread(sol5,50001,62500);
    threads3[5] = new thread(sol6,62501,75000);

    threads3[6] = new thread(sol7,75001,87500);
    threads3[7] = new thread(sol8,87501,100000);
    threads3[0]->join();
    threads3[1]->join();
    threads3[2]->join();
    threads3[3]->join();
    threads3[4]->join();
    threads3[5]->join();
    threads3[6]->join();
    threads3[7]->join();
 stop = high_resolution_clock::now();
 duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    delete threads3[0];
    delete threads3[1];
    delete threads3[2];
delete threads3[3];
    delete threads3[4];
    delete threads3[5];
    delete threads3[6];
    delete threads3[7];


































    return 0;
}

