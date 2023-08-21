#include<iostream>
using namespace std;

const int MAX_SIZE=500;


struct Task{
	
	string task;
	string status;
	
	
};

class ToDoList{
	
    private:
		Task taskArray[MAX_SIZE];
		int no_task;

		
    public:

	ToDoList(){
		
	
		no_task=1;
		
	}
	
	
	void addTask(string task_info){
	    
	    taskArray[no_task].task=task_info;
	    	
	    no_task++;
	    	
	    cout<<"Your Task is Added Successfully "<<endl;
	

}


    void editTask(int id, string edit){
	
		if(id>0 && id <= no_task){
			taskArray[id].task=edit;
		}
		else{
			cout<<"INVALID INPUT"<<endl;
		}
}


void deleteTask(int id){
	
	
	if(id>0 && id<=no_task){
		
		for(int i=id; i<no_task-1; ++i){
			taskArray[id]= taskArray[i+1];
			
			
		}
		no_task--;

	}
	else{
		cout<<"INVALID INPUT !!"<<endl;
	}
}

    void DisplayList(){
	
	cout<<"\t\t\t\tTO DO LIST "<<endl;
	cout<<"\t\t--------------------------------------------------"<<endl;
		for(int i=1;i<no_task;i++){
				cout<<"\t\tTASKS  \t       STATUS\t\t  DESCRIPTION"<<endl;
				cout<<"\t\t--------------------------------------------------"<<endl;
				cout<<"\t\t"<<i<<"\t     "<<taskArray[i].status<<"\t\t\t"<<taskArray[i].task<<"\n\n\n";
				
			
			}
	
}	


    void CompletionStatus(int id){
	
	if(id>0 && id <= no_task){
		
			taskArray[id].status="completed";
		
			cout<<"Task marked as Done"<<endl;
			
			
	}
	else{
			cout<<"Invalid ID "<<endl;
			
		}
	
}		
};





int main(){
	
	ToDoList list;
	cout<<"\n\t\t\tTO DO LIST"<<endl;
	
	// variables declaration
		int choice=1,id;
		string TASK,confirm;
		
	do{
	//menu driven program
	cout<<"\n\n";
	cout<<"Press 1 to Add task "<<endl;
	cout<<"Press 2 to Delete task "<<endl;
	cout<<"Press 3 to Edit task"<<endl;
	cout<<"Press 4 to mark done  task"<<endl;
	cout<<"Press 5 to Display List "<<endl;
	cout<<"Press 0 to Exit"<<endl;
	cout<<"\nEnter your choice :"<<endl;
	
	cin>>choice;
	
	switch(choice){
		
		case 0 :
			exit(0);
		
			
		case 1 :
			
			cout<<"\nEnter your task : "<<endl;
		    cin.get();
			getline(cin,TASK);
			
			list.addTask(TASK);
			do{
				cout<<"Want to Add more ?\n Press y for Yes OR Press n for No"<<endl;
	        cin>>confirm;
	        if(confirm == "y"){
	        
			cout<<"Enter your task : "<<endl;
			cin.get();
			getline(cin,TASK);
		    list.addTask(TASK);
		    
	        }
		}while(confirm!="n");
			
	       
		break;
		
		
		case 2 :
			
			cout<<"\nEnter task id which you want to Delete :"<<endl;
			cin>>id;
			cout<<"Confirm (y/n)?"<<endl;
			cin>>confirm;
			if(confirm=="y"){
				list.deleteTask(id);
				cout<<"Your task is Deleted Successfully !!"<<endl;
			}
			
			
		break;
			
			
		case 3 :
			
			cout<<"\nEnter task id which you want to Edit "<<endl;
			cin>>id;
			cout<<"Enter New description "<<endl;
			cin.get();
			getline(cin,TASK);
			cout<<"Confirm & save (y/n)?"<<endl;
			cin>>confirm;
			if(confirm=="y"){
				list.editTask(id,TASK);
				cout<<"Your task is Updated Successfully !!"<<endl;
			}
			
			
			
			break;
			
		case 4 :
			
			cout<<"\nEnter the task ID which you want to mark as done :"<<endl;
			cin>>id;
			list.CompletionStatus(id);
			break;
			
			
		case 5:
			
			list.DisplayList();
			break;
			
			
		
			
	}
	}while(choice!=0);
	
	
	
	
	
}