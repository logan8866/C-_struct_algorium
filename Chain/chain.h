template <class T>
class ChainNode{
	public:
		T element;
		ChainNode<T>* next;
		ChainNode(const T &element);
		ChainNode(const T &element, ChainNode<T>* next);
		ChainNode(ChainNode<T> *chainnode);
};
template <class T>
class Chain{
	public:
		ChainNode<T>* head;
		ChainNode<T>* end;
		int length;
		Chain();
		Chain(Chain<T>* chain);
		int insert(int index,ChainNode<T>* chainnode);
		int end_insert(ChainNode<T>* chainnode);
		int delete_any(int index);
		int update_any(int index,const T &element);
		int show_any(int index);
		int show_all();
};
