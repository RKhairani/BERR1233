#include <iostream>
#include <cstring>
#include <stdlib.h>
#define number 2 
using namespace std;

struct treenode{
	int data;
	treenode *left,*right;
};

//queue
class Queue{ //pre-registered
	public:
		Queue();
		void Insert(int value);
		int Sumsecondary();  //secondary student
		void Remove();
		int copy();
	private:
		int *Array,Front,Rear,ArraySize;
    int CurrentSize;
};

Queue::Queue(){ 
	Array=new int[number]; 
	ArraySize=number;
	Front=0,CurrentSize=0;
	Rear=ArraySize-1;
}

void Queue::Insert(int value){
	if(CurrentSize>ArraySize-1){
		cout<<"\t\t Queue for today is full";
		return;
	}
	if(Rear==ArraySize-1)
		Rear=0;
	else
		Rear++;
	Array[Rear]=value;
	CurrentSize++;
}

int Queue::Sumsecondary(){
	return 1;  
}

void Queue::Remove(){
	if(CurrentSize==0){
		cout<<"\t\t Queue for today is empty\n";
		return;
	}
	int Temp;
	Temp=Array[Front];
	if(Front==ArraySize-1)
		Front=0;
	else
		Front++;
	CurrentSize--;
	cout<<"\t\t"<<Temp<<endl;
	return;
}


//binary tree
class BST{
	public:
		BST(){
			root=NULL;
		}
		void insert(int);
		int totalprimarystudent(int d); //d =parameter data umur
		void inorder(); //ltr
	private:
		treenode *root;
		void insert(treenode*,int);
		int totalprimarystudent(treenode*,int d,int t); //t=total
		void inorder(treenode*);
};
void BST::insert(int d){
	if(root!=NULL)
		insert(root,d);
	else{
		root=new treenode;
		root->data=d;
		root->left=NULL;
		root->right=NULL;
	}
}

void BST::insert(treenode *node,int d){
	if(d<node->data){
		if(node->left!=NULL)
			insert(node->left,d); //start in order arrangements
		else{
			node->left=new treenode;
			node->left->data=d;
			node->left->left=NULL;
			node->left->right=NULL;
		}
	}                                        
	else if(d>=node->data){
		if(node->right!=NULL)
			insert(node->right,d);
		else{
			node->right=new treenode;
			node->right->data=d;
			node->right->left=NULL;
			node->right->right=NULL;
		}
	}
}

int BST::totalprimarystudent(int d){
	int t=0;
	if(root!=NULL)
		t=totalprimarystudent(root,d,t);
	else{
		root=new treenode;
		root->data=d;
		t++;
		root->left=NULL;
		root->right=NULL;
	}
	return t;
}

int BST::totalprimarystudent(treenode *node,int d,int t){
	
	if(d<node->data){
		if(node->left!=NULL)
			t=totalprimarystudent(node->left,d,t);
		else{
			node->left=new treenode;
			node->left->data=d;
			t++;
			node->left->left=NULL;
			node->left->right=NULL;
		}
	}
	else if(d>=node->data){
		if(node->right!=NULL)
			t=totalprimarystudent(node->right,d,t);
		else{
			node->right=new treenode;
			node->right->data=d;
			t++;
			node->right->left=NULL;
			node->right->right=NULL;
		}
	}
	return t;
}

void BST::inorder(){
	if(root==NULL)
		cout<<"\t\t Tree Empty\n";
	else
		inorder(root);
}

void BST::inorder(treenode *node){
	if(node!=NULL){
		inorder(node->left);
		cout<<"\t\t"<<node->data<<endl;
		inorder(node->right);
	}
}

class Tuition  //create student
{
	public:
		char name[50];
		int noID;
		char grade[50];
		int studentage;
		Tuition *next;
};

int ARRAY=0;
Tuition Tuitionlist[10];


//linked insertion
void createAcc(Tuition *&head,Tuition *&last, int noID, char name, char grade,int studentage);
void searchnoID(Tuition *&head,Tuition *&last, int noID, char name, char grade,int studentage);

void createAcc(Tuition *&head,Tuition *&last, int noID, char name[], char grade[],int studentage){
	Tuition *temp = new Tuition;
	temp->noID = noID;
	temp->next = NULL;
	head = temp;
	last = temp;

	if(ARRAY < 10){
		cout<<"\n\t\t Enter  Student Details"<<endl;
		cout<<"\t\t Enter No ID: ";
		cin>>Tuitionlist[ARRAY].noID;
		cout<<"\t\t Enter Student Name: ";
		cin>>Tuitionlist[ARRAY].name;
		cout<<"\t\t Enter a Grade: ";
		cin>>Tuitionlist[ARRAY].grade;
		cout<<"\t\t Enter Student Age: ";
		cin>>Tuitionlist[ARRAY].studentage;
		ARRAY++;
	}
	else{
		cout<<"Maximum capacity of people reached"<<endl;
	}
}

//Searching : linear

void searchnoID(Tuition *&head,Tuition *&last, int noID, char name[], char grade[],int studentage){
	Tuition *temp = new Tuition;
	temp->noID = noID;
	temp->next = NULL;
	head = temp;
	last = temp;
  

	int id,found=0;
	cout<<"\n\t\t Enter No ID Student to search: ";
	cin>>id;
	int i=0;
	while(i<10){
		if(id==Tuitionlist[i].noID){
			cout<<endl;
 			cout<<"\t\t No ID Student:"<<Tuitionlist[i].noID<<endl;
  			cout<<"\t\t Student Name:"<<Tuitionlist[i].name<<endl;
  	 		cout<<"\t\t Grade:"<<Tuitionlist[i].grade<<endl;
  	 		cout<<"\t\t Age:"<<Tuitionlist[i].studentage<<endl;
			found=1;
			return;
		}
    	else
			i++;
	}
  	if(found==0)
  	{
    	cout<<"\n\t\t No ID Not Found"<<endl;
 	 }
	
}

int ageread();

int ageread(){
	int age;
	cout<<"\t\t Enter Age: ";
	cin>>age;
	return age;
}
int main(){
	char ch2;
  	int ch1,ch,ch3;
	int age,sumprimary=0,sumsecondary=0;
	string ic;
	string PW;
	char name[50];
	int noID;
	char grade[50];
	int studentage;
	
	Tuition *head = NULL;
	Tuition *last = NULL;

  	BST primarystudent; //linked list show result registered student
  	BST primarystudent2; 
	Queue adult;
	Queue adult2;
	do{
		
		cout<<"\t\t------------------------------\n"<<endl;
		cout<<"\t\t Tuition Registration Management System\n\n"<< endl;
		cout<<"\t\t 1. Pre-Registered Student (Admin) "<< endl;
		cout<<"\t\t 2. Manage Student "<< endl;
		cout<<"\t\t 3. Exit "<< endl;
		cout<<"\t\t------------------------------\n"<<endl;
		cout<<"\t\t Enter choice: ";
		cin>>ch1;
		
		switch(ch1){
		case 1:{
			cout<<"\t\t Enter Password: ";
			cin.ignore();
			getline(cin,PW);
			if(PW=="Admin123"){
				
				
			do{
				cout<<"\n\t\t 1. Display Total Primary Students\n";
				cout<<"\t\t 2. Display Total Secondary Students\n";
				cout<<"\t\t 3. Back\n";
				cout<<"\n\t\t Enter choice:";
				cin>>ch;
			
				if(ch==1){
					cout<<"\n\t\t Sum of Primary Student: "<<sumprimary<<endl;
					primarystudent.inorder();
				}
				else if(ch==2){
					cout<<"\n\t\t Sum of Secondary Student: "<<sumsecondary<<endl;
					for(int k=0;k<sumsecondary;k++){
						adult2.Remove();
					}
				}
				else if(ch==3){
					break;
				}
			}while(ch!=3);
			}
			break;}
		case 2:{
			do{
				cout<<"\n\t\t1. Create New Student\n";
				cout<<"\t\t2. Search Student ID\n";
				cout<<"\t\t3. Pre-Register Student\n";
				cout<<"\t\t4. Back\n";
				cout<<"\n\t\t Enter choice:";
				cin>>ch3;
				if(ch3==1){
					createAcc(head,last,noID,name,grade,studentage);
				}
				else if(ch3==2){
					searchnoID(head,last,noID,name,grade,studentage);
				}
				else if(ch3==3){
					cout<<"\n\t\t Enter I/C Num: ";
					cin>>ic;
					cout << "\t\t Enter Name: ";
    				cin>>name;
					age=ageread();
					if(age>=7&&age<=12){
						primarystudent.insert(age);
						sumprimary=sumprimary+primarystudent2.totalprimarystudent(age);
					}
					else if(age>12 && age<=17){
						adult.Insert(age);
						adult2.Insert(age);
						sumsecondary=sumsecondary+adult.Sumsecondary();
					}
					else{
						cout << "\n\t\t Cannot Register: Age is not within the acceptable range for registration." << endl;
					}
				}
				else if(ch3==4){
					break;
				}
			}while(ch3!=4);
			
			break;}
		case 3:{
			cout<<"\n\n\t\t\t Thank You";
			break;}
		default :cout<<"\a";
		}
	}while(ch1!=3);
	return 0;
}

