template<class T>
class Tree{
	public:
		Tree();
		~Tree();
		Tree(const T &data);
		T data;
		Tree<T>* ltree;
		Tree<T>* rtree;
};
template<class T>
void create_tree(Tree<T> *&root);
template<class T>
void pre_order(Tree<T>* root);
template<class T>
void middle_order(Tree<T>* root);
template<class T>
void post_order(Tree<T>* root);

template<class T>
Tree<T>* test(Tree<T> *&t);
