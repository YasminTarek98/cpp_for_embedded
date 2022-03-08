#include "iostream"
#define READ_ONLY   0
#define WRITE_ONLY  1
#define RW          2
#define RESERVED    3
using namespace std;
template <typename T>

class myRegister{
    private:
        T reg;
        char permission;
    public:
       /* class PinPermmision
        {
            PinPermmision()
            {
                pinMode selectedPin=readWrite;
            }
            public:
                enum pinMode 
                {
                    readOnly ,
                    writeOnly ,
                    readWrite ,
                    reserved ,
                };
                void setReadOnly(void)
                {
                  pinMode selectedPin=readOnly;  
                }
                void setWriteOnly(void)
                {
                  pinMode selectedPin=writeOnly;  
                }
        };*/
        myRegister()
        {
            permission=RW;
        }
        myRegister(char state)
        {
            permission=state;
        }
        void setRegisterValue(T value)
        {
            if(permission==RW || permission==WRITE_ONLY)
            {
                reg=value;
            }
            else
            {
                cout<<"you cannot write on this register "<< endl;
            }
        }
        T getRegisterValue()
        {
            if(permission==RW || permission==READ_ONLY)
            {
                return reg;
            }
            else
            {
                cout<<"you cannot read from this register "<< endl;
            }
        }
        void setBit(char bitNum)
        {
            if(permission==RW || permission==WRITE_ONLY)
            {
                reg|=(1<<bitNum);
            }
            else
            {
                cout<<"you cannot write on this register "<< endl;
            }
        }
        void clearBit(char bitNum)
        {
            if(permission==RW || permission==WRITE_ONLY)
            {
                reg&=~(1<<bitNum);
            }
            else
            {
               cout<<"you cannot write on this register "<< endl; 
            }
        }
        char getBit(char bitNum)
        {
            if(permission==RW || permission==READ_ONLY)
            {
                return ((reg>>bitNum)&1);
            }
            else
            {
                cout<<"you cannot read from this register "<< endl; 
            }
        }
        void setPermission(char state)
        {
            permission=state;
        }

};

int main(void)
{
    /*myRegister<char> avr;
    myRegister<int> arm(RESERVED);
    avr.setRegisterValue(50);
    char value=avr.getBit(1);
    cout<<avr.getRegisterValue()<<endl;
    cout<<value<<endl;
    arm.clearBit(3);
    value= arm.getBit(5);*/

    return 0;

}