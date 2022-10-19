#include<iostream>
#include<fstream>
using namespace std;

 void home();
 
 int admin_home_page();         //decclaration of the function

 class Item{
 	private:
 		int id_i;
 		string name_i;
 		float price_i;
 		
 	public:
 		void add_i();
 		void update_i();
 		void delete_i();
 		void show_i();
 		int search_i(int searchdel);
 };
  
 ////////////////////////////////////////"item class ends"////////////////////////
 ////////////////////////////////////////"employee class starts"//////////////////
 class employee{
 	private:
	int id;
 	string name;
 	string password;
 	public:
 		void admin_home();
 		void receptionist_home();
 };
	employee emp1;
 void employee::admin_home(){
// 		cout<<"abcd2";
// 	system("CLS");
 	
//	cout<<"admin"<<endl;
	int b;
	
	
	cout<<"           "<<"|********|"<<endl;
    cout<<"           "<<"|**    "<<"BAKERY"<<"    ****|"<<endl;
    cout<<"           "<<"|**"<<"Login as Admin"<<"**|"<<endl;
    cout<<"           "<<"|----------------------------------------------------------|"<<endl;
    cout<<"           "<<"|                                                          |"<<endl;
    cout<<"           "<<"|------------------"<<"PRODUCT"<<"-------------------------|"<<endl; 
    cout<<"           "<<"| PRESS 1 To SHOW ALL PRODUCT                              |"<<endl;
    cout<<"           "<<"| PRESS 2 To SEARCH THE PRODUCT                            |"<<endl; 
	cout<<"           "<<"| PRESS 3 To ADD THE PRODUCT                               |"<<endl;// cin>>a;
		cout<<"       "<<"| PRESS 4 To DELETE THE PRODUCT                            |"<<endl;// 
    cout<<"           "<<"|----------------------------------------------------------|"<<endl; // cin>>b;
    cout<<"           "<<"|                                                          |"<<endl;
    cout<<"           "<<"|------------------"<<"EMPLOYEE"<<"------------------------|"<<endl; 
    cout<<"           "<<"| PRESS 5 To SHOW ALL EMPLOYEE                             |"<<endl;
    cout<<"           "<<"| PRESS 6 To SEARCH THE EMPOYLEE                           |"<<endl; // cin>>c;
    cout<<"           "<<"|                                                          |"<<endl; //cin>>d;
    cout<<"           "<<"|********|"<<endl;
    cout<<"           "<<"|----------------------------------------------------------|"<<endl;
   
   
   
	cin>>b; 
	if(b==1){
		Item i;
		i.show_i();
	}
	else if(b==2){
		Item i;
		i.search_i(0);
}
	else if(b==3){
		Item i;
		i.add_i();
	}
	else if(b==4){
		Item i;

		i.delete_i();
	}
}
 void employee::admin_home(); 
 void Item :: add_i(){
 	
  	fstream f;
	f.open("mydatabase.txt" , ios::out | ios::app);
	if(!f){	cout<<"data base connectivity error"<<endl;  }
	else{
		cout<<"Enter item's id" <<endl;
 	cin>> id_i;
 	
	cout<<"Enter item's name" << endl;
 	cin>>name_i;
 	
 	cout<<"Enter item's price"<<endl;
 	cin>>price_i;
 	
 	        //sending data to data base
		f<<id_i<<" "<<name_i<<" "<<price_i<<endl;  
		system("CLS");     
		cout<<"DATA ADDED SUCCESSFULLY"<<endl;     
		emp1.admin_home();
	}
}

 void Item :: show_i(){
// 	int id;
  	fstream fi;
	fi.open("mydatabase.txt" , ios::in);
	if(!fi){	cout<<"data base connectivity error"<<endl;  }
	else{
		
		int cc =1;
   while ( !fi.eof() ) { // keep reading until end-of-file
	  fi >> id_i >>name_i>>price_i;
      cout << "The " << id_i << "  :  "<< name_i<<"  :  "<<price_i <<endl;
      //cout<<"abcd :"<<cc++<<endl;
   }
   fi.close();
	}
}

int Item::search_i(int searchdel){
int userinput;
int choice;
int check=0;
cout<<"Enter id you want to search"<<endl;
cin>>choice;

	fstream fi;
	fi.open("mydatabase.txt" , ios::in);
	if(!fi){	cout<<"data base connectivity error"<<endl;  }
	else{
		
		int cc =1;
   while ( !fi.eof() ) { // keep reading until end-of-file
	  fi >> id_i >>name_i>>price_i;
	  
	  if(choice==id_i){
	  	if(searchdel == 0){
		  
	  	cout << "The " << id_i << "  :  "<< name_i<<"  :  "<<price_i <<endl; 
		  }
		  else if(searchdel==1){
		  	return 1;
			  }
	  	check=1;
	  }
      
      
   }
   if(check==0){  
   cout<<"no record found"<<endl;
}
   fi.close();
	}
	cout<<"enter 1 to search again and enter 0 to finish the program"<<endl;
	cin>>userinput;
	if(userinput==1)
	{  
	search_i(0);
	//emp1.admin_home();
	}
    else if(userinput!=1){
    	cout<<"invalid input "<<endl;
    	
	}
}
void Item::delete_i(){
	int id_i=search_i(1);
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Item i;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream fi;
        fi.open("mydatabase.txt" , ios::in);
	if(!fi){	cout<<"data base connectivity error"<<endl;  }
	else{
		
		int cc =1;
   while ( !fi.eof() ) { // keep reading until end-of-file
	  fi >> id_i >>name_i>>price_i;
	  
	  if(choice!=id_i){
	  	tempFile << "\n" << i.id_i;
        tempFile << "\n" << i.name_i;
        tempFile << "\n" << i.price_i;
	  }
      
   }
}
   fi.close();
   tempFile.close();
   remove("mydatabase.txt");
   rename("temp.txt", "mydatabase.txt");
   cout << "\nData deleted successfuly";
}
	else {
        cout << "\n\tRecord not deleted";
    }
    cout<<"invalid input "<<endl;
    	
	}
void Item::update_i(){
//    int id_i=search_i();
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y'){
        Item newi;
        cout<<"Enter item's id" <<endl;
 	    cin>> newi.id_i;
 	
	    cout<<"Enter item's name" << endl;
 	    cin>>newi.name_i;
 	
 	     cout<<"Enter item's price"<<endl;
 	     cin>>newi.price_i;
        Item i;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream fi;
        fi.open("mydatabase.txt" , ios::in);
	if(!fi){	
	    cout<<"data base connectivity error"<<endl;  
	    
	}
	else{
		
		int cc =1;
   while ( !fi.eof() ) { // keep reading until end-of-file
	  fi >> id_i >>name_i>>price_i;
	  
	  if(choice!=id_i){
	  	tempFile << "\n" << i.id_i;
        tempFile << "\n" << i.name_i;
        tempFile << "\n" << i.price_i;
	  }
      else{
	  	tempFile << "\n" << newi.id_i;
        tempFile << "\n" << newi.name_i;
        tempFile << "\n" << newi.price_i;
	  }
      //cout<<"abcd :"<<cc++<<endl;
   }
}
   fi.close();
   tempFile.close();
   remove("mydatabase.txt");
   rename("temp.txt", "mydatabase.txt");
   cout << "\nData deleted successfuly";
}
	else {
        cout << "\n\tRecord not deleted";
    }
    cout<<"invalid input "<<endl;
    	
	}       

 int main(){
 	
	home();
}
void home()
{
	int a;
	cout<<"WELCOME TO THE BAKERY"<<endl;
	cout<<"Select 1 for admin"<<endl;
	cout<<"Select 2 for receptionist"<<endl;
	cout<<"Select 3 for customer"<<endl;
	cin>>a;
	if(a == 1){

	emp1.admin_home();
	}
	else if (a==2){
		system("CLS");
		cout<<"receptionist"<<endl;
	}
	else if(a==3){
		system("CLS");
		cout<<"customer"<<endl;
	}
	else{
		system("CLS");
		cout<<"invalid input"<<endl;
	    main();
	}
}
