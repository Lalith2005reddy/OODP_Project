                                                        //Inline Function example
/*#include<iostream>
using namespace std;
inline int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    cout<<max(5,7);
    cout<<max(8,10);
}*/
                                                        //Friend function example
#include<iostream>
using namespace std;
class B;           //forward declaration
class A{
    private:
    int a;
    public:
    void get(){
        cin>>a;
    }
    friend void add(A,B);
};
class B{
    private:
    int b;
    public:
    void get(){
        cin>>b;
    }
    friend void add(A,B);
};
void add(A o,B k){          // Access private data by non member function
    cout<<o.a+k.b;
}
int main(){
    A obj;
    B oj;
    obj.get();
    oj.get();
    add(obj,oj);
}


                                      //Friend Class
/*#include<iostream>
using namespace std;
class B;
class A{
    private:
    int a;
    public:
    A(){
        a=10;
    }
    friend class B;
};
class B{
    private:
    int b;
    public:
    B(){
        b=5;
    }
    int add(){
        A obj;
        return obj.a+b;
    }
};
int main(){
    B l;
    cout<<l.add();
    return 0;
}*/