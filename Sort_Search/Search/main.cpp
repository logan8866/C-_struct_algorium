#include<iostream>
#include"find.cpp"

int main(){
	long *array;
	array = new long[100000000];
	long i = 0;
	int result;
	for (i=0;i<100000000;i++){
		array[i] = i+1;
	}
	Search<long>* bs;
	bs = new Binary_Search<long>();
	result = bs->search(array,100000000,66666666);
	std::cout<<"binary result index:"<<result<<std::endl;
	std::cout<<"binnary compare time:"<<bs->compare_time<<std::endl;
	std::cout<<"binary execute time:"<<bs->execute_time<<std::endl;
	
	Search<long>* os;
	os = new Order_Search<long>();
	result = os->search(array,100000000,66666666);
        std::cout<<"order result index:"<<result<<std::endl;
        std::cout<<"order compare time:"<<os->compare_time<<std::endl;
        std::cout<<"order execute time:"<<os->execute_time<<std::endl;

	return 0;
}


