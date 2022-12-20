//
// Created by иван on 20.12.2022.
//
#include <iostream>
#ifndef UNTITLED19_ARR_H
#define UNTITLED19_ARR_H

template<typename T,int N>
class arr {
private:
    T* data;
public:
    arr();
    ~arr();
    bool pull(T,int);
    void print();
    void sort();
    bool search(T);
};

template<typename T,int N>arr<T,N>::arr(){
    data=new T[N*sizeof (T)];
}
template<typename T,int N>arr<T,N>::~arr(){
    delete []data;
}
template<typename T,int N> bool arr<T,N>::pull(T t,int n){
if(n<N) {data[n]=t; return 1;}
else return 0;
}
template<typename T,int N> void arr<T,N>::print(){
    for(int i=0;i<N;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}
template<typename T,int N> void arr<T,N>::sort(){//сортировка шелла
    for (int s = N / 2; s > 0; s /= 2) {
        for (int i = s; i < N; i++) {
            for (int j = i - s; j >= 0 && data[j] > data[j + s] ; j -= s) {
                T x=data[j];
                data[j] = data[j + s];
                data[j + s] = x;
            }
        }
    }
}
template<typename T,int N> bool arr<T,N>::search(T key){
    this->sort();

    bool flag=false;
    int l=0;
    int r=N;
    int mid;

    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;
        if (data[mid] == key) flag = true;
        if (data[mid] > key) r = mid - 1;
        else l = mid + 1;
        }
    return flag;
}

#endif //UNTITLED19_ARR_H
