#include <vector>
#include <iostream>
#include <iterator>
#ifndef colaPri
#define colaPri

using namespace std;
#define NULL __null

template <class T>
class BinaryHeap
{
    private:
        vector <T> heap;
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void heapifyup(int index);
        void heapifydown(int index);
    public:
        BinaryHeap()
        {}
        void Insert(T element);
        void DeleteMin();
        void DisplayHeap();
        int Size();
};
template<class T>
int BinaryHeap<T>::Size()
{
    return heap.size();
}
template<class T>
void BinaryHeap<T>::Insert(T element)
{
    heap.push_back(element);
    heapifyup(heap.size() -1);
}
template<class T>
void BinaryHeap<T>::DisplayHeap()
{
    vector <int>::iterator pos = heap.begin();
    while (pos != heap.end())
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
}
template <class T>
void BinaryHeap<T>::heapifyup(int in)
{
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] < heap[in])
    {
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        heapifyup(parent(in));
    }
}
template <class T>
void BinaryHeap<T>::heapifydown(int in)
{
 
    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] < heap[child1])
    {
       child = child1;
    }
    if (child > 0 && heap[in] > heap[child])
    {
        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        heapifydown(child);
    }
}
template <class T>
int BinaryHeap<T>::left(int parent)
{
    int l = 2 * parent + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}
template <class T>
int BinaryHeap<T>::right(int parent)
{
    int r = 2 * parent + 2;
    if (r < heap.size())
        return r;
    else
        return -1;
}
template <class T>
int BinaryHeap<T>::parent(int child)
{
    int p = (child - 1)/2;
    if (child == 0)
        return -1;
    else
        return p;
}

template <class T>
void BinaryHeap<T>::DeleteMin() {
   if (heap.size() == 0) {
      cout<<"Cola vacia"<<endl;
      return;
   }
   heap[0] = heap.at(heap.size() - 1);
   heap.pop_back();
   heapifydown(0);
   cout<<"Dato eliminado"<<endl;
}
#endif
