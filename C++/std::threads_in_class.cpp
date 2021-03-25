#include <thread>
#include <iostream>
using namespace std;
class Wrapper {
public:
    //数据
    int a=1;
    int b=2;
    //中间函数 不同进程调用，它的线程也是不一样
    void mid_f()
    {
        cout<<"mid_f "<<std::this_thread::get_id()<<endl;
    }
    //写自己的分开函数
    void f1()
    {
      cout<<"f2 start"<<std::this_thread::get_id()<<endl;
      while(1)
      {
          mid_f();
          std::cout << "f1" << endl;
          std::this_thread::sleep_for(std::chrono::seconds(1));
      }
    }
    void f2(int a,int b)
    {
      cout<<"f2 start"<<std::this_thread::get_id()<<endl;
      while(1)
      {
          mid_f();
          std::cout << "f2 " <<a<<" "<<b<<endl;
          std::this_thread::sleep_for(std::chrono::seconds(1));
      }
    }

    //lamda表达式
    std::thread f1Thread() {
      return std::thread([=] { f1(); });
    }
    std::thread f2Thread(int a, int b) {
      return std::thread([=] { f2(a, b); });
    }

    std::thread f11Thread() {
      return std::thread([=] { f1(); });
    }
    std::thread f21Thread() {
      return std::thread([=] { f2(5,10); });
    }


    //启动函数
    void run()
    {
      std::thread tw1 = f1Thread();
      std::thread tw2 = f2Thread(a, b);
      std::thread tw11 = f11Thread();
      tw1.detach();
      tw2.detach();
      tw11.detach();
    }

};
int main()
{
   Wrapper *w = new Wrapper();
   w->run();
   while(1)
   {
       int a=0;
   }
   return 0;
}
