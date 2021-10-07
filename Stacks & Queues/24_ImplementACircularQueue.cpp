#include <iostream>
using namespace std;
template <typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
public:
    QueueUsingArray(T s){
        data=new int[s];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=s;
    }
    
    int getSize(){
        return size;
    }
    
    bool check(){
        return size==0;
    }
    
    void enqueue(T element){
        if(size==capacity){
            cout<<"queue is full"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex==-1){
            firstIndex=0;
        }
        size++;

    }
    
    T front(){
        if(check()){
            cout<<"queue empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    
    T dequeue(){
        if(check()){
            cout<<"queue empty"<<endl;
            return 0;
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        if(size==0){
            firstIndex=-1;
            nextIndex=0;
        }
        return ans; 
        
        
    }
};
 
int main() {
    QueueUsingArray<int>s(5);
    int ch;
    
     while(ch!=6)
    {
        cout<<"\n1. enqueue\n";
        cout<<"2. dequeue\n";
        cout<<"3. front\n";
        cout<<"4. size\n";
        cout<<"5. check\n";
        cout<<"6. exit\n";
        cout<<"\nEnter your Choice :: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            int x;
            cout<<"enter the element"<<endl;
            cin>>x;
                s.enqueue(x);
                break;

            case 2:
                cout<<"deleted data "<<s.dequeue()<<endl;
                break;

            case 3:
                cout<<s.front()<<endl;
                break;

            case 4:
                
                cout<<s.getSize()<<endl;
               
                break;
                
                case 5:
                cout<<s.check()<<endl;
                break;
                
                case 6:
                ch=6;
                break;

            default:
                cout<<"\nWrong Choice!! \n";
                break;
        }
    }
return 0;
}
