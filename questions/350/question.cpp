#include<iostream>
#include<functional>
class Q{
    int v=0;
    public:
        Q(Q&&){
            std::cout << "M";
        }
        Q(const Q&){
            std::cout << "C";
        }
        Q(){
            std::cout << "D";
        }
        void change(){
            ++v;
        }
        void func(){
            std::cout << v;
        }
};
void takeQfunc(std::function<void(Q)> qfunc){
    Q q;
    q.func();
    qfunc(q);
    q.func();
}
int main(){
    takeQfunc([](Q&& q){
        q.change();
    });
    return 0;
}