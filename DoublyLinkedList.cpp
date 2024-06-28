#include "DoublyLinkedList.h"
#include "Player.h"
#include <iostream>
#include <fstream>
using namespace std;
	
	//Constructer
	template <class T>
	DoublyLinkedList<T>::DoublyLinkedList(){
		this->last = NULL;
		readFromBinaryFile("Players.bin");
	}
	
	template <typename T>
	void DoublyLinkedList<T>::readFromBinaryFile(const char* fileName) {
	    ifstream inFile(fileName, ios::binary);
	    if (!inFile) {
	        cerr << "Error opening file for reading: " << fileName << endl;
	        return;
	    }
	
	    T playerData;
	    while (inFile.read((char*)(&playerData), sizeof(T))) {
	        Node<T>* newNode = new Node<T>(playerData);
	        if (last == NULL) {
	            last = newNode;
	            last->setNext(last);
	            last->setPrev(last);
	        } else {
	            newNode->setPrev(last);
	            newNode->setNext(last->getNext());
	            last->getNext()->setPrev(newNode);
	            last->setNext(newNode);
	            last = newNode;
	        }
	    }
	
	    inFile.close();
	}
	
	template <typename T>
	void DoublyLinkedList<T>::writeToBinaryFile(const char* fileName) {
	    ofstream outFile(fileName, ios::binary);
	    if (!outFile) {
	        cerr << "Error opening file for writing: " << fileName << endl;
	        return;
	    }
	
	    Node<T>* p = last->getNext();  // Start from the first node
	    do {
	        T playerData = p->getData();
	        outFile.write((const char*)(&playerData), sizeof(T));
	        p = p->getNext();
	    } while (p != last->getNext());  // Continue until we reach the first node again
	
	    outFile.close();
	}
	
	//Muteters/Setters
	template <class T>
	void DoublyLinkedList<T>::setLast(Node<T>* l){
		this->last = l;
	}
	
	//Inspecters/Accessers/Getters
	template <class T>
	Node<T>* DoublyLinkedList<T>::getLast(){
		return this->last;
	}
	
	template <class T>
	void DoublyLinkedList<T>::insertBeg(T d){
		Node<T>* temp = new Node<T>(d);
		if(last == NULL){
			temp->setNext(temp);
			temp->setPrev(temp);
			last = temp;
		}
		else{
			temp->setNext(last->getNext());
			temp->setPrev(last);
			temp->getNext()->setPrev(temp);
			last->setNext(temp);
		}
	}
	
	template <class T>
	void DoublyLinkedList<T>::insertPos(T d,int pos){
		if(pos < 1){
			cout << "\nInvalid position.. \nbcoz position is less than 1";
			return;
		}
		Node<T>* temp = new Node<T>(d);
		if(last == NULL){
			temp->setNext(temp);
			temp->setPrev(temp);
			last = temp;
		}
		else{
		
			if(pos == 1){
				temp->setNext(last->getNext());
				temp->setPrev(last);
				temp->getNext()->setPrev(temp);
				last->setNext(temp);
			}
			else{
				Node<T>* p = last->getNext();
				int i = 1;
				while((i < pos-1) && (p != last)){
					p = p->getNext();
					i++;
				}
				temp->setPrev(p);
				temp->setNext(p->getNext());
				p->setNext(temp);
				temp->getNext()->setPrev(temp);
				if(p == last){
					last = temp;
				}
			}
		}
	}
	template <class T>
	void DoublyLinkedList<T>::insertEnd(T d){
		Node<T>* temp = new Node<T>(d);
		if(last == NULL){
			temp->setNext(temp);
			temp->setPrev(temp);
		}
		else{
			temp->setPrev(last);
			temp->setNext(last->getNext());
			last->setNext(temp);
			temp->getNext()->setPrev(temp);
		}
		last = temp;
	}
	template <class T>
	bool DoublyLinkedList<T>::search(int jr, Node<T>*& x){
		if(last == NULL){
			cout << "\nPlayers List Not Created...";
			x = NULL;
			return false;
		}
		Node<T>* p = last->getNext();
		while(p != last){
			if(p->getData().getJrNum() == jr){
				x = p;
				return true;
			}
			p = p->getNext();
		}
		if(p->getData().getJrNum() == jr){
			x = p;
			return true;
		}
		x = NULL; 
		return false;
	}
	template <class T>
	bool DoublyLinkedList<T>::search(const char* nm, Node<T>*& x){
		if(last == NULL){
			cout << "\nTs List Not Created...";
			x = NULL;
			return false;
		}
		Node<T>* p = last->getNext();
		while(p != last){
			if(stricmp(p->getData().getName(),nm)==0){
				x = p;
				return true;
			}
			p = p->getNext();
		}
		if(stricmp(p->getData().getName(),nm)==0){
			x = p;
			return true;
		}
		x = NULL; 
		return false;
	}
	template <class T>
	void DoublyLinkedList<T>::Update() {
	    char ex;
	    do {
	        int n;
	        cout << "1-Update from JrNum.\n2-Update from Name.\n";
	        cout << "Enter your choice: ";
	        cin >> n;
	
	        Node<T>* x = NULL;
	
	        if (n == 1) {
	            int jrnum;
	            cout << "Enter the JrNum of the player you want to update: ";
	            cin >> jrnum;
	            if (!search(jrnum, x)) {
	                cout << "\nPlayer not found with the given JrNum.\n";
	            }
	        } else if (n == 2) {
	            char name[20];
	            cout << "Enter the Player Name which you want to update: ";
				fflush(stdin);
				gets(name);
	            if (!search(name, x)) {
	                cout << "\nPlayer not found with the given Name.\n";
	            }
	        } else {
	            cout << "Invalid choice.\n";
	            return;
	        }
	        if (x != NULL) {
	            int choice;
	            cout << "What do you want to update?\n";
	            cout << "1- Runs.\n2- Wickets.\n3- Matches.\n4- All.\n";
	            cout << "Enter your choice: ";
	            cin >> choice;
	            x->getData().printTableHeader();
				x->getData().Display();
	            switch (choice) {
				    case 1: {
				        int r;
				        cout << "Enter the runs: ";
				        cin >> r;
				        x->getData().setRuns(r);
				        break;
				    }
				    case 2: {
				        int w;
				        cout << "Enter the wickets: ";
				        cin >> w;
				        x->getData().setWickets(w);
				        break;
				    }
				    case 3: {
				        int m;
				        cout << "Enter the Matches: ";
				        cin >> m;
				        x->getData().setMatches(m);
				        break;
				    }
				    case 4: {
				    	int r,w,m;
				    	cout << "Enter the runs: ";
				        cin >> r;
				        cout << "Enter the wickets: ";
				        cin >> w;
				        cout << "Enter the Matches: ";
				        cin >> m;
				        x->getData().setRuns(r);
				        x->getData().setWickets(w);
				        x->getData().setMatches(m);
						break;
					}
				    default:
				        cout << "Invalid choice.\n";
				}
	            cout << "T information updated successfully.\n";
	        }
	        cout << "Do you want to continue in Update Menu (Y/N): ";
	        cin >> ex;
	    } while (ex == 'Y' || ex == 'y');
	}
	template <class T>
	void DoublyLinkedList<T>::top3() {
	    Node<T>* arr[3] = {NULL, NULL, NULL};
	    int fmax = -2147483648;
	    int smax = -2147483648;
	    int tmax = -2147483648;
	    Node<T>* p = last->getNext();
	    int choice = 0;
	
	    while (choice != 3) {
	        cout << "\n\t1-ByRuns.\n\t2-ByWickets.\n\t3-Exit";
	        cout << "\nEnter Your Choice: ";
	        cin >> choice;
	
	        switch (choice) {
	            case 1: {
	                do {
	                    if (fmax < p->getData().getRuns()) {
	                    	tmax = smax;
               				smax = fmax;
               				fmax = p->getData().getRuns();
	                        arr[2] = arr[1];
	                        arr[1] = arr[0];
	                        arr[0] = p;
	                    } else if (smax < p->getData().getRuns()) {
	                    	tmax = smax;
	                    	smax = p->getData().getRuns();
	                        arr[2] = arr[1];
	                        arr[1] = p;
	                    } else if (tmax < p->getData().getRuns()) {
	                    	tmax = p->getData().getRuns();
	                        arr[2] = p;
	                    }
	                    p = p->getNext();
	                } while (p != last->getNext());
	                break;
	            }
	            case 2: {
	                do {
	                    if (fmax < p->getData().getWickets()) {
	                    	tmax = smax;
               				smax = fmax;
               				fmax = p->getData().getWickets();
	                        arr[2] = arr[1];
	                        arr[1] = arr[0];
	                        arr[0] = p;
	                    } else if (smax < p->getData().getWickets()) {
	                    	tmax = smax;
	                    	smax = p->getData().getWickets();
	                        arr[2] = arr[1];
	                        arr[1] = p;
	                    } else if (tmax < p->getData().getWickets()) {
	                    	tmax = p->getData().getWickets();
	                        arr[2] = p;
	                    }
	                    p = p->getNext();
	                } while (p != last->getNext());
	                break;
	            }
	            case 3: {
	                cout << "\nExit.";
	                break;
	            }
	            default: {
	                cout << "\nInvalid choice. Please enter 1, 2, or 3.";
	                break;
	            }
	        }
	    }
	
	    cout << "\nTop 3 Ts:\n";
	    for (int i = 0; i < 3; i++) {
	    	
	    	if (arr[i] != NULL){
	    		arr[i]->getData().printTableHeader();
	    		arr[i]->getData().Display();
			}
	            
	    }
	}
	template <class T>
	void DoublyLinkedList<T>::deleteBeg(){
		if(last == NULL){
			cout << "\nNo Node to Delete..";
			return;
		}
		Node<T>* p = last->getNext();
		if(p == last){
			last = NULL;
			p->getData().printTableHeader();
			p->getData().Display();
			cout << " is deleted..";
			delete p;
		}
		else{
			p->getNext()->setPrev(last);
			last->setNext(p->getNext());
			p->getData().printTableHeader();
			p->getData().Display();
			cout << " is deleted..";
			delete p;
		}
	}
	template <class T>
	void DoublyLinkedList<T>::deletePos(int pos){
		if(pos < 1){
			cout << "\nInvalid position.. \nbcoz position is less than 1";
			return;
		}
		if(last == NULL){
			cout << "\nNo Node to Delete..";
		}
		else{
			Node<T>* p = last->getNext();
			if(pos == 1){
				if(p == last){
					last = NULL;
					p->getData().printTableHeader();
					p->getData().Display();
					cout << " is deleted..";
					delete p;
				}
				else{
					p->getNext()->setPrev(last);
					last->setNext(p->getNext());
					p->getData().printTableHeader();
					p->getData().Display();
					cout << " is deleted..";
					delete p;
				}
			}
			else{
				int i = 1;
				while((i < pos-1) && p->getNext() != last){
					p = p->getNext();
					i++;
				}
				if((i == pos-1) && (p != last)){
					Node<T>* q = p->getNext();
					p->setNext(q->getNext());
					if(q == last){
						last = p;
					}
					q->getNext()->setPrev(p);
					q->getData().printTableHeader();
					q->getData().Display();
					cout << " is Deleted..";
					delete q;
					return;
				}
				else{
					cout << "\nInvalid Position..";
				}
			}
		}
	}
	template <class T>
	void DoublyLinkedList<T>::deleteEnd(){
		if(last == NULL){
			cout << "\nNo Node to Delete..";
			return;
		}
		Node<T>* p = last->getNext();
		if(p == last){
			last = NULL;
			p->getData().printTableHeader();
			p->getData().Display();
			cout << " is deleted..";
			delete p;
		}
		else{
			while(p->getNext()!=last){
				p = p->getNext();
			}
			Node<T>* q = last;
			p->setNext(q->getNext());
			q->getNext()->setPrev(p);
			last = p;
			q->getData().printTableHeader();
			q->getData().Display();
			cout << " is deleted..";
			delete q;
		}
	}
	template <class T>
	void DoublyLinkedList<T>::display(){
		if(last == NULL){
			cout << "No Node to Display..";
		}
		else{
			Node<T>* p = last->getNext();
			p->getData().printTableHeader();
			while(p != last){
				p->getData().Display();
				cout << "\t";
				p = p->getNext();
			}
			p->getData().Display();
			cout << "\n";
		}
	}
	template <class T>
	void DoublyLinkedList<T>::displayBackword(){
		if(last == NULL){
			cout << "No Node to Display..";
		}
		else{
			Node<T>* p = last;
			p->getData().printTableHeader();
			while(p != last->getNext()){
				p->getData().Display();
				cout << "\t";
				p = p->getPrev();
			}
			p->getData().Display();
			cout << "\n";
		}
	}
	template <class T>
	DoublyLinkedList<T>::~DoublyLinkedList(){
		writeToBinaryFile("Players.bin");
		if(last != NULL){
			Node<T>* p = last->getNext();
			Node<T>* q;
			while(p != last){
				q = p->getNext();
            	delete p;
            	p = q;
			}
			delete last;
			last = NULL;
		}
	}
