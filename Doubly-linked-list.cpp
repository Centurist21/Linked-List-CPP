#include<iostream>
using namespace std;

class node{
    public:
    int ele;
    node * next;
    node * prev;// prevoius node pointer 
    node(){
        ele = 0;
        next = NULL;
        prev = NULL;
    }
    node(int e){
        ele = e;
        next = NULL;
        prev = NULL;
    }
};


/// 10->11->12->13->14->NULL
//  10<-11<-12<-13<-14<-NULL
class Doublylinkedlist{
    public:
    node * head;
    node * tail;
    int count;
    Doublylinkedlist(){
         head = NULL;
         tail=NULL;
         count = 0;
    }
    int addelementatend(int e){
        count++;
        node * n = new node(e);
        if(head == NULL){
            head = n;
            tail = n;
            head -> prev = tail;
            tail -> next = head;
            return 0;
        }
        tail->next=n;
        n->prev = tail;
        tail=n;
        tail->next=NULL;
        cout<<"element added sucessfully at end!"<<endl;
        return 0;
        
    }
    int addatbegin(int e){
        count++;
        cout<<"element added sucessfully at the begining!"<<endl;
        node *n = new node(e);
        if(head == NULL){
            head = n;
            tail=n;
            return 0;
        }
        else{
            n->next = head;
            head->prev = n;
            head = n;
            head->prev = NULL;
            return 0;
        }
        
    }
    int remvatbeg(){
        if(head == NULL){
            return 1;

        }
        if(head==tail){
            delete head;
            head = NULL;
            tail= NULL;
            count--;
            return 0;
            
        }
        head=head->next;
        delete head->prev;
        head->prev=NULL;
        
    }
    int remvatend(){
        if(head == NULL){
            return 1;
        }
        if(head->next == NULL){
            delete head;
            head = NULL;
            tail = NULL;
            count--;
            return 0;
        }
        tail=tail->prev;
        delete tail->next;
        tail->next=NULL;
        count--;
        return 0;
    }
    void display(){
        if(head == NULL){
            cout<<"The list is empty! "<<endl;
            return ;
        }
        node * temp = head;
        while(temp != NULL){
            cout << temp->ele<<"->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
    int addatpos(int i,int e){
        if(i > count + 1 || i < 1){
            return 1;
        }
        if(head == NULL){
            if(i != 1){
                return 1;
            }
            else{
                addatbegin(e);
                return 0;
            }
        }
        if(i==count+1){
            addelementatend(e);
            return 0;
        }
        if(i==1){
            addatbegin(e);
            return 0;
        }

        node * n = new node(e);
        int c = 1;
        node *temp = head;
        while(c != i){
            temp = temp->next;
            c++;
        }
        // 10 20 [n] ->30 50
        n->prev=temp->prev;
        n->next=temp;
        temp->prev->next=n;
        temp->prev=n;
        return 0;
    }

    int removeatpos(int i){
        if(i > count){
            return 1;//invalid pos
    }
        if(head == NULL){
            return 1;//empty list
        }
        if(i == 1){
            remvatbeg();
            return 0;//removing the first element(base case)
        }
        if(i==count){
            remvatend();
            return 0;
        }

        // 10 20 [33] 30 50
        int cn = 1;
        node*temp = head;
        while(cn != i){
            temp = temp->next;
            cn++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        count--;
        return 0;
    }
    int searchele(int c){
        if(head == NULL){
            return -1;
        }
        node *temp = head;
        int counter = 1;
        while(temp != NULL && temp->ele != c){
            temp = temp->next;
            counter++;
        }

        if(temp != NULL){
            return counter;
        }
        else{
            return -1;
        }
    }

    
};


int main(){
    
    
    int n=1;
    Doublylinkedlist obj;

    int success;
    
    while(n != 0){
    cout<<"welcome to the menu!\nplease select the preffered option :"<<endl;
    cout<<"to display the list : 1 "<<endl;
    cout<<"to add an element at the end of the list : 2 "<<endl;
    cout<<"to add an element at the begining of the list : 3 "<<endl;
    cout<<"to remove element at the begining of the list : 4 "<<endl;
    cout<<"to remove an element at the end of the list : 5 "<<endl;
    cout<<"to add an element at a certain position : 6 "<<endl;
    cout<<"to remove an element from a certain position : 7 "<<endl;
    cout<<"to search for an element : 8"<<endl;
    cout<<"to exit the program :0 "<<endl;
    cout<<"enter the option : "<<endl;
    cin>>n;

        switch (n)
        {
        case 1:
            obj.display();
            break;
        case 2:
            int a;
            cout<<"enter the element :";
            cin>>a;
            obj.addelementatend(a);
            break;
        
        case 3:
            int b;
            cout<<"enter the element :";
            cin>>b;
            obj.addatbegin(b);
            break;

        case 4:
            
            int check;
            check=obj.remvatbeg();
            if(check){
                cout<<"empty list, cant remove anyhting! "<<endl;
            }
            else{

                cout<<"element removed! "<<endl;
            }
            
            break;

        case 5:
            success = obj.remvatend();
            if(success!=1){
                cout<<"element removed"<<endl;
            }
            else{
                cout<<"empty list"<<endl;
            }
            
            break;
        case 6:
            int num;
            int pos;
            int see;
            cout << "enter the element : ";
            cin >> num;
            cout << "enter the position : ";
            cin >> pos;
            see = obj.addatpos(pos,num);
            if(see){
                cout<<"invalid position given! " << endl;
            }
            else{
                cout << "element added sucessfully!" << endl;
            }
            break;

        case 7:
            int posn,checker;
            cout<<"enter the position at which the elemnt should be removed : ";
            cin>>posn;
            checker = obj.removeatpos(posn);
            if(checker){
                cout << "Invalid Position or Empty List" << endl;

            }
            else{
                cout << "element removed" << endl;
            }
            break;

        case 8:
            int search;
            cout<<"entert the element to search : ";
            cin>>search;
            int ans;
            ans=obj.searchele(search);
            if(ans==-1){
                cout<<"element not found"<<endl;
            }
            else{
                cout<<"element found at : "<<ans<<endl;
            }
            break;
        default:
            if(n!=0){
                cout<<" enter correct command "<<endl;
            }
            else{
                cout<<"exited program"<<endl;
            } 
            break;
        }

    }
    return 0;
}
