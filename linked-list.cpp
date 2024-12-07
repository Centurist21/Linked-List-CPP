#include<iostream>
using namespace std;


class node{
    public:
    int ele ;
    // int rollnumber;   these parameters could also be passed to node
    // bool gender;

    node * next; //pointer to next node
    node(){
        
        ele = 0;
        next = NULL;
    }
    node(int e){
        ele = e;
        next = NULL;
    }

};

/// 10->11->12->13->14->NULL  example of how a linked list looks


class linkedlist{
    public:
    node * head;
    node * tail;
    int count; //number of nodes
    linkedlist(){
         head = NULL;
         tail=NULL;
         count = 0;
    }
    int addelementatend(int e){
        count++;
        node * n = new node(e);
        if(head == NULL){              //base cases
            head = n;
            tail=n;
            return 0;
        }
        if(head->next == NULL){
            head->next = n;
            tail=n;
            return 0;
        }
        
        //general case

        tail->next=n;
        tail=n;
        cout<<"element added sucessfully at end!"<<endl;
        return 0;
        
    }
    int addatbegin(int e){
        count++; //adding a node
        cout<<"element added sucessfully at the begining!"<<endl;

        node *n = new node(e);

        if(head == NULL){
            head = n;
            tail=n;
            return 0;
        }
        else{
            n->next = head;
            head = n;
            return 0;
        }
        
    }
    int remvatbeg(){
        if(head == NULL){
            return 1;

        }
        if(head==tail ){// also can be written as head->next==NULL
            delete head;
            head = NULL;
            tail= NULL;
            count--;
            return 0;
            
        }

        node*temp = head->next;
        delete head;
        head = temp;
        count--;
        return 0; 
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
        node *temp = head;
        while(temp->next!=tail){
            temp = temp->next;

        }
        delete tail;
        tail = temp;
        temp->next = NULL;
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
        node * n = new node(e);
        int c = 1;
        node *temp = head;
        while(c != i-1){
            temp = temp->next;
            c++;
        }
        n->next = temp->next;
        temp->next = n;
        count++; 
        return 0;
    }

    int removeatpos(int i){
        if(i > count){
            return 1; //invalid pos
    }
        if(head == NULL){
            return 1; //empty list
        }
        if(i == 1){
            remvatbeg();
            return 0; //removing the first element(base case)
        }
        if(i==count){
            remvatend(); //removing last element(base case)
        }
        
        int cn = 1;
        node*temp = head;
        while(cn != i-1){
            temp = temp->next;
            cn++;
        }
        node *t2 = temp->next;
        temp->next = temp->next->next;
        delete t2;
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

// 10->12->13->14->15->NULL



int main(){
    
    
    int n=1;
    linkedlist obj;

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
    cout<<"enter the option : ";
    cin>>n;

        switch (n)
        {
        case 1:
            obj.display();
                cout<<endl;

            break;
        case 2:
            int a;
            cout<<"enter the element :";
            cin>>a;
            obj.addelementatend(a);
                cout<<endl;

            break;
        
        case 3:
            int b;
            cout<<"enter the element :";
            cin>>b;
            obj.addatbegin(b);
                cout<<endl;

            break;

        case 4:
            
            int check;
            check=obj.remvatbeg();
            if(check){
                cout<<"empty list, cant remove anyhting! "<<endl;
                cout<<endl;
            }
            else{

                cout<<"element removed! "<<endl;
                cout<<endl;
            }
            
            break;

        case 5:
            success = obj.remvatend();
            if(success!=1){
                cout<<"element removed"<<endl;
                cout<<endl;
            }
            else{
                cout<<"empty list"<<endl;
                cout<<endl;
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
                cout<<endl;

            }
            else{
                cout << "element added sucessfully!" << endl;
                cout<<endl;
            }
            break;

        case 7:
            int posn,checker;
            cout<<"enter the position at which the elemnt should be removed : ";
            cin>>posn;
            checker = obj.removeatpos(posn);
            if(checker){
                cout << "Invalid Position or Empty List" << endl;
                cout<<endl;


            }
            else{
                cout << "element removed" << endl;
                cout<<endl;

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
                cout<<endl;

            }
            else{
                cout<<"element found at : "<<ans<<endl;
                cout<<endl;

            }
            break;
        default:
            if(n!=0){
                cout<<" enter correct command "<<endl;
                cout<<endl;

            }
            else{
                cout<<"exited program"<<endl;
            } 
            break;
        }

    }
    return 0;
}

