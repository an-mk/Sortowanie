#ifndef UTILS_H_
#define UTILS_H_

template<typename T>
void swap(T& a, T& b) 
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

#endif /* !UTILS_H_ */
