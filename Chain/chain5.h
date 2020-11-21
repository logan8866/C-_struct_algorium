#ifndef C5
#define C5
#include"chain.h"
#endif
template<class T>
class Chain5 : public Chain<T>
{
	public:
		void delete_many(int index_start, int index_end);
};
