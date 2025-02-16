#include<iostream>
using namespace std;
class Book{
    string title;
    float *price=new float;
    int *stock=new int;
    public:
        Book(string title,float *price,int s){
            this->title=title;
            this->price=price;
            *stock=s;
        }
        Book(Book& obj){
            title=obj.title;
            *price=*obj.price;
            *stock=*obj.stock;
        }
        void update_details(){
            cout<<"Enter book name: ";
            cin>>title;
            cout<<"Enter book price: ";
            cin>>*price;
            cout<<"Enter book stock: ";
            cin>>*stock;
            cout<<"Book details updated successfully"<<endl;
        }
        void applyDiscount(int qty,float price){
            if(qty>100){
                cout<<"You have got the discount of 40%"<<endl<<"Price before discount: "<<price*qty<<endl;
                price=(price*60)/100;
                cout<<"Final Price (After discount): "<<price*qty<<endl;
            }
            else if(qty>20){
                cout<<"You have got the discount of 20%"<<endl<<"Price before discount: "<<price*qty<<endl;
                price=(price*80)/100;
                cout<<"Final Price (After discount): "<<price*qty<<endl;
            }
            else if(qty>10){
                cout<<"You have got the discount of 10%"<<endl<<"Price before discount: "<<price*qty<<endl;
                price=(price*90)/100;
                cout<<"Final Price (After discount): "<<price*qty<<endl;
            }
            else if(qty>5){
                cout<<"You have got the discount of 5%"<<endl<<"Price before discount: "<<price*qty<<endl;
                price=(price*95)/100;
                cout<<"Final Price (After discount): "<<price*qty<<endl;
            }
            else{
                cout<<"Price: "<<price*qty<<endl;
            }
        }
        void purchase_book(int qty){
            if(qty>=0){
                if(*stock!=0){
                    if(qty<=*stock){
                        *stock-=qty;
                        cout<<qty<<" books purchased successfully"<<endl;
                        applyDiscount(qty,*(this->price));
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
            cout<<endl<<"Title: "<<title<<endl<<"Price: "<<*price<<endl<<"Available Stock: "<<*stock<<endl;
        }
        ~Book(){
            cout<<"Object destroyed successfully"<<endl;
            delete stock;
            delete this->price;
        }
};
int main(){
    float price;
    string title;
    int stock,c1,c2,qty;
    cout<<"For book b1"<<endl;
    cout<<"Enter book title: ";
    cin>>title;
    cout<<"Enter book price: ";
    cin>>price;
    cout<<"Enter available stock of the book: ";
    cin>>stock;    
    Book b1(title,&price,stock);
    Book b2=b1;
    cout<<"Details of books b1";
    b1.display_book();
    cout<<endl<<"Details of book b2 copied from book b1";
    b2.display_book();
    cout<<endl<<"Updating the details of book b1"<<endl;
    b1.update_details();
    cout<<endl<<"Details of books b1";
    b1.display_book();
    cout<<endl<<"Details of book b2";
    b2.display_book();
    while(1){
        cout<<endl<<"Enter the appropriate key to perform the required function\n1.Update Book Details\n2.Purchase a book\n\tIf you buy in bulk (more than 100) you will get 40% discount\n\tIf you buy more than 5 books you will get 5% discount\n\tIf you buy more than 10 books you will get 10% discount\n\tIf you buy more than 20 books you will get 20% discount\n3.Display book details\nAny other key to exit\nEnter: ";
        cin>>c1;
        switch(c1){
            case 1:
                cout<<endl<<"Enter the appropriate key according to the book\n1.Book b1\n2.Book b2\nEnter: ";
                cin>>c2;
                if(c2==1){
                    b1.update_details();
                }
                else if(c2==2){
                    b2.update_details();
                }
                else{
                    cout<<"Invalid input"<<endl;
                }
                break;
            case 2:
                cout<<endl<<"Enter the appropriate key according to the book\n1.Book b1\n2.Book b2\nEnter: ";
                cin>>c2;
                if(c2==1){
                    cout<<"How many books do you want to purchase: ";
                    cin>>qty;
                    b1.purchase_book(qty);
                }
                else if(c2==2){
                    cout<<"How many books do you want to purchase: ";
                    cin>>qty;
                    b2.purchase_book(qty);
                }
                else{
                    cout<<"Invalid input"<<endl;
                }
                break;
            case 3:
                cout<<endl<<"Enter the appropriate key according to the book\n1.Book b1\n2.Book b2\nEnter: ";
                cin>>c2;
                if(c2==1){
                    b1.display_book();
                    break;
                }
                else if(c2==2){
                    b2.display_book();
                }
                else{
                    cout<<"Invalid input"<<endl;
                }
                break;
            default:
                cout<<"Exited successfully"<<endl;
                return 0;
        }
    }
}