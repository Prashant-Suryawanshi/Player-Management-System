template <class T>
class Node{
	Node* prev;
	T data;
	Node* next;
	public:
		//Constructer
		Node(T);
		
		//Mutetters/Setters
		void setPrev(Node*);
		void setData(T);
		void setNext(Node*);
		
		//Inspecters/Accessers
		Node* getPrev();
		T& getData();
		Node* getNext();
};//class Node end's here
