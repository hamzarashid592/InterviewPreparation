# include <iostream>
using namespace std;


class strategy{
public:
    virtual void do_something()=0;
};

class strategy1 : public strategy{
public:
    void do_something(){
        cout<<"Something from strategy 1"<<endl;
    }
};

class strategy2 : public strategy{
public:
    void do_something(){
        cout<<"Something from strategy 2"<<endl;
    }
};


class context{
private:
    strategy *strgy;

public:
    context(){

    }
    ~context(){
        delete this->strgy;
    }

    void set_strategy(strategy *strgy){
        this->strgy=strgy;
    }

    void get_strategy(){
        this->strgy->do_something();
    }

};

class person{
public:
    
};

int main(){

    context *obj1= new context();
    obj1->set_strategy(new strategy1);
    obj1->get_strategy();

    obj1->set_strategy(new strategy2);
    obj1->get_strategy();


    return 0;
}