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
        Book(Book& obj){
            title=obj.title;
            price=obj.price;
            *stock=*obj.stock;
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
        ~Book(){
            cout<<"Object destroyed successfully"<<endl;
            delete stock;
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
    Book b2=b1;
    cout<<"Details of books b1";
    b1.display_book();
    cout<<endl<<"Details of book b2 copied from book b1";
    b2.display_book();
    cout<<endl<<"Updating the details of book b1"<<endl;
    b1.update_details();
    cout<<"Details of books b1";
    b1.display_book();
    cout<<endl<<"Details of book b2";
    b2.display_book();
    return 0;
}