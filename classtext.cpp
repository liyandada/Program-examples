#include <iostream>

using namespace std;

class Aname 
{
public: 
    Aname()
    {
        cout << "aaa" << endl;
    }
        ~Aname()
    {
        cout << "~aaa" << endl;
    }
    
 
};

class Bname: public Aname 
{
    public:
        Bname() {
            cout << "bbb" << endl;
        }
                ~Bname() {
            cout << "~bbb" << endl;
        }
    
};

int main () 
{
    Aname *x = new Bname();

    delete(x);
     

}