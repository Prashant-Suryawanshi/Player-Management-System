#include "Node.cpp"
#include "string.h"

template <class T>
class DoublyLinkedList{
	Node<T>* last;
	
	public:
		//Member Functions
		//Constructer
		DoublyLinkedList();
		//Muteters/Setters
		void setLast(Node<T>*);
		//Inspecters/Accessers/Getters
		Node<T>* getLast();
		
		// Function to read data from a binary file during construction
	    void readFromBinaryFile(const char* fileName);
	
	    // Function to write data to a binary file
	    void writeToBinaryFile(const char* fileName);
		
		void insertBeg(T);
		void insertPos(T,int);
		void insertEnd(T);
		
		bool searchJrNum(int jr, Node<T>*&);
		bool searchName(const char*,Node<T>*&);
		
		bool search(int jr, Node<T>*&);
		bool search(const char*,Node<T>*&);
		void Update();
		void top3();
		
		void deleteBeg();
		void deletePos(int);
		void deleteEnd();
		
		void display();
		void displayBackword();
		
		~DoublyLinkedList();
};
