// A C++ code to demonstrate  namespace.
#include <iostream>
using namespace std;
  
// Creating a namespace
namespace ns
{
    void display(){
        cout << "ns::display()\n";
    };
    class geek
    {
    public:
       void display(){
        cout << "ns::geek::display()\n";
        };
    };
}// Defining methods of namespace outside possible


//namespace aliasing:
namespace name1 
    {
        namespace name2 
        {
            namespace name3 
            {
                int var = 42;
            }
        }
    }
  
// Aliasing 
namespace alias = name1::name2::name3;
   
  
// Driver code
int main()
{
    ns::geek obj;
    ns::display();
    obj.display();

    using namespace ns;
    display();

    cout<<alias::var;
  
    return 0;
}

/*
ns::display()      
ns::geek::display()
ns::display()
42
*/