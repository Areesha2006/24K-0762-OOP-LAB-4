#include<iostream>
using namespace std;
class Book{
    string title;
    float price;
    int *stock=new int;
    public:
        Book(string title,float p,int s){
            this->title=title;
            price=p;
            *stock=s;
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
        void applyDiscount(int qty,float p){
            if(qty>10){
                cout<<"You have got the discount of 10%"<<endl<<"Price before discount: "<<p*qty<<endl;
                p=(p*90)/100;
                cout<<"Final Price (After discount): "<<p*qty<<endl;
            }
            else{ 
                if(qty>5){
                    cout<<"You have got the discount of 5%"<<endl<<"Price before discount: "<<p*qty<<endl;
                    p=(p*95)/100;
                    cout<<"Final Price (After discount): "<<p*qty<<endl;
                }
                else{
                    cout<<"Price: "<<p*qty<<endl;
                }
            }
        }
        void purchase_book(int qty){
            if(qty>=0){
                if(*stock!=0){
                    if(qty<=*stock){
                        *stock-=qty;
                        cout<<qty<<" books purchased successfully"<<endl;
                        applyDiscount(qty,price);
                        if(*stock<5){
                            cout<<"Warning: Low Stock"<<endl;
                        }
                    }
                    else{
                        cout<<"Maximum "<<*stock<<" books are available only"<<endl;
                    }
                }
                else{
                    cout<<"No book available"<<endl;
                }
            }
            else{
                cout<<"Invalid quantity"<<endl;
            }
        }
        void display_book(){
            cout<<endl<<"Title: "<<title<<endl<<"Price: "<<price<<endl<<"Available Stock: "<<*stock<<endl;
        }
};
int main(){
    float price;
    string title;
    int stock;
    cout<<"Enter book title: ";
    cin>>title;
    cout<<"Enter book price: ";
    cin>>price;
    cout<<"Enter available stock of the book: ";
    cin>>stock;    
    Book b1(title,price,stock);
    int c,qty;
    while(1){
        cout<<endl<<"Enter the appropriate key to perform the required function\n1.Update Book Details\n2.Purchase a book\n3.Display book details\nAny other key to exit\nEnter: ";
        cin>>c;
        switch(c){
            case 1:
                b1.update_details();
                break;
            case 2:
                cout<<"How many books do you want to purchase: ";
                cin>>qty;
                b1.purchase_book(qty);
                break;
            case 3:
                b1.display_book();
                break;
            default:
                cout<<"Exited successfully";
                return 0;
        }
    }
}