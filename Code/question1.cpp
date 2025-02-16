#include<iostream>
using namespace std;
class Book{
    string title;
    float price;
    int *stock=new int;
    public:
        Book(){
            title="Unknown";
            price=0.0;
            *stock=30;
        }
        void update_details(){
            cout<<"Enter book name: ";
            cin>>title;
            cout<<"Enter book price: ";
            cin>>price;
            cout<<"Enter book stock: ";
            cin>>*stock;
            cout<<"Book details updated successfully"<<endl;
        }
        void purchase_book(int qty){
            if(qty>=0){
                if(qty<=*stock){
                    *stock-=qty;
                    cout<<qty<<" books purchased successfully"<<endl;
                    if(*stock<5){
                        cout<<"Warning: Low Stock"<<endl;
                    }
                }
                else{
                    cout<<qty<<" are not available"<<endl;;
                }
            }
            else{
                cout<<"Invalid quantity"<<endl;
            }
        }
};
int main(){
    Book b1;
    int c,qty;
    while(1){
        cout<<"Enter the appropriate key to perform the required function\n1.Update Book Details\n2.Purchase a book\nAny other key to exit\nEnter: ";
        cin>>c;
        switch(c){
            case 1:
                b1.update_details();
;               break;
            case 2:
                cout<<"How many books do you want to purchase: ";
                cin>>qty;
                b1.purchase_book(qty);
                break;
            default:
                cout<<"Exited successfully";
                return 0;
        }
        cout<<endl;
    }
}