#include <iostream>
#include <fstream>
#include "DoublyLinkedList.CPP"
#include "Player.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	DoublyLinkedList<Player> DLL;
	int choice = 0;
	while(choice != 13)
	{
        cout << "+------------------------------------------------------------------------------------+\n";
	    cout << "¦                                       Main Menu                                    ¦\n";
	    cout << "+------------------------------------------------------------------------------------+\n";
	    cout << "¦      1-Insert at beginning.               ¦            8-Circular Display Backword.¦\n";
	    cout << "¦      2-Insert at end.                     ¦            9-search JrNum.             ¦\n";
	    cout << "¦      3-Insert at position.                ¦            10-search Name.             ¦\n";
	    cout << "¦      4-Delete From Beginning.             ¦            11-Update.                  ¦\n";
	    cout << "¦      5-Delete From End.                   ¦            12-Top3.                    ¦\n";
	    cout << "¦      6-Delete From Position.              ¦            13-Exit.                    ¦\n";
	    cout << "¦      7-Circular Display.                  ¦                                        ¦\n";
	    cout << "+------------------------------------------------------------------------------------+\n";
        cout << "\n\nEnter your choice : ";
        cin >> choice;
		
		
		
		
		switch(choice)
		{
			case 1: {
						int j,m,r,w;
						char nm[20];
						cout << "\nEnter the JrNum : ";
						cin >> j;
						cout << "\nEnter Player Name : ";
						fflush(stdin);
						gets(nm);
						cout << "\nEnter the Matchs : ";
						cin >> m;
						cout << "\nEnter the Runs : ";
						cin >> r;
						cout << "\nEnter the wickets : ";
						cin >> w;
						Player data(j,nm,m,r,w);
						DLL.insertBeg(data);
					break;
					}
			case 2: {
						int j,m,r,w;
						char nm[20];
						cout << "\nEnter the JrNum : ";
						cin >> j;
						cout << "\nEnter Player Name : ";
						fflush(stdin);
						gets(nm);
						cout << "\nEnter the Matchs : ";
						cin >> m;
						cout << "\nEnter the Runs : ";
						cin >> r;
						cout << "\nEnter the wickets : ";
						cin >> w;
						Player data(j,nm,m,r,w);
						DLL.insertEnd(data);
					break;
					}
			case 3:{
						int pos;
						
						int j,m,r,w;
						char nm[20];
						cout << "\nEnter the JrNum : ";
						cin >> j;
						cout << "\nEnter Player Name : ";
						fflush(stdin);
						gets(nm);
						cout << "\nEnter the Matchs : ";
						cin >> m;
						cout << "\nEnter the Runs : ";
						cin >> r;
						cout << "\nEnter the wickets : ";
						cin >> w;
						Player data(j,nm,m,r,w);
						
						cout << "\nEnter Position : ";
						cin >> pos;
						DLL.insertPos(data,pos);
					break;
					}
			case 4:{
					DLL.deleteBeg();
					break;
					}
			case 5:{
					DLL.deleteEnd();
					break;
					}
			case 6:{
					int pos;
					cout<<"\nEnter the postion : ";
					cin>>pos;
					DLL.deletePos(pos);
					break;
					}
			case 7: DLL.display();
					break;
			case 8: DLL.displayBackword();
					break;
			case 9:{
					int jr;
					cout << "Enter jrNum : ";
					cin >> jr;
					Node<Player>* x;
					if(DLL.search(jr,x)){
						x->getData().Display();
					}
					else{
						cout << "\nNot Found..";
					}
					cout << "\n\n";
				break;
			}
			case 10:{
					char nm[20];
					cout << "Enter Name : ";
					cin >> nm;
					Node<Player>* x;
					if(DLL.search(nm,x)){
						x->getData().Display();
					}
					else{
						cout << "\nNot Found..";
					}
					cout << "\n\n";
				break;
			}
			case 11:{
				DLL.Update();
				break;
			}
			case 12:{
				DLL.top3();
				break;
			}
			case 13:{
				cout << "\nThank You..\n";
				break;
			}
			default : 
				cout<<"\nInvalid choice..";
		}
	}
	return 0;
}

