
template<class T>
class List{
	public:
		int max_length;
		int length;
		T* elements;
		List();
		List(T* elements);
		List(List<T>* list);
		~List();
		void show_all();
		int get_length();
		T find_by_index(int index);
		int find_by_T(T &element);
		void insert_by_index(int index,T &element);
		void delete_by_index(int index);
};
