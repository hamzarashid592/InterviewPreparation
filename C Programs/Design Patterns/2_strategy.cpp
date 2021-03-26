# include <iostream>
using namespace std;

class skin{
    public:
        virtual string skinType()=0;
};

class deep_fur : public skin{
    public:
        string skinType(){
            return("The animal has deep fur");
        }
};

class normal_fur : public skin{
    public:
        string skinType(){
            return("The animal has normal fur");
        }
};

class feathers : public skin{
    public:
        string skinType(){
            return("The animal has feathers");
        }
};


class animal
{
    private:
        
    public:
        animal(){

        }
        ~animal(){

        }
        string get_skin(){
            return khaal->skinType();
        }
        void set_skin(skin *khaal){
            this->khaal=khaal;
        }
    protected:
        skin *khaal;
};

class bird : public animal{
    private:
    
    public:
        bird(){
            khaal = new feathers;
        }

};

class lion : public animal{
    private:
    
    public:
        lion(){
            khaal = new deep_fur;
        }

};

class cat : public animal{
    private:
    
    public:
        cat(){
            khaal = new normal_fur;
        }

};


int main(){

    bird tweety;
    cout<<"Tweety: "<< tweety.get_skin()<<endl;
    tweety.set_skin(new deep_fur);
    cout<<"Tweety after some evolution: "<< tweety.get_skin()<<endl;
    lion samba;
    cout<<"Samba: "<< samba.get_skin()<<endl;
    cat tom;
    cout<<"Tom: "<< tom.get_skin()<<endl;


    return 0;
}
