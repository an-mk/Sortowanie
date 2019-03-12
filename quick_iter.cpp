#include "quick_iter.hpp"

#include <stack>
#include <utility>

//template<typename C>
//class TD;

using PosT = signed long long;

template <typename T>
/*o__constexpr*/ void sort::quicksort_iter(std::vector<T> &vec)
{
	std::stack< std::pair<PosT, PosT > > stosik;
	stosik.push(std::make_pair<PosT, PosT>(0, vec.size()-1) );

	do{
		auto left = static_cast<PosT>(stosik.top().first);
		auto right = static_cast<PosT>(stosik.top().second);
		stosik.pop();
		do{
			auto l = left;
			auto r = right;	
			auto pivot = vec[(left+right)/2];
			
			do{
				while(vec[l] < pivot)l++;
				while(vec[r] > pivot)r--;
				if(l <= r){
					std::swap(vec[r], vec[l]);
					l++; r--;
				}
			}while(l <= r);
			if(l < right){
				stosik.emplace(l, right);
			}
			right = r;
		}while(left < right);
	
	}while(!stosik.empty());
	
}
