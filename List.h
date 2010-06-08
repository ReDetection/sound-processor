/*
 * List.h
 *
 *  Created on: 15.03.2010
 *      Author: rd
 */
#ifndef LIST_H_
#define LIST_H_

#include <iostream>

template<class T>
class List {
    class ListItem {
    public:
        T *data;
        ListItem *next;
        ListItem() {
            next = 0;
        }
        ListItem(T* data){
            this->data=data;
            next=0;
        }
        ~ListItem(){
            delete data;
        }
    };

    ListItem *head,*end;
    int size;

public:
    List() {
        head = 0;
        size=0;
        end=0;
    }

    int getSize() const{
        return size;
    }


    /*
     * добавление нового элемента в хвост
     * возвращает индекс нового элемента или -1, если не хватило памяти
     */
    int append(T *value){
    	ListItem *n = new ListItem(value);
	if(n==0)
            return -1;
    	if(size==0){
            head=n;
            end=n;
            return size++;
    	}
        end->next = n;
        end=end->next;
        return size++;
    }



    ~List() {
        for(ListItem *p=head; p!=0 ; p=head){
            head=head->next;
            delete p;
        }
    }
    T* getItem(int index) const{
        ListItem *p=head;
        for(int i=0;i<index;i++,p=p->next); // ищем
        return p->data;
    }

    T& getItemByRef(int index)const{
        ListItem *p=head;
        for(int i=0;i<index;i++,p=p->next);
        return *p->data;
    }

    T& operator[](int index)const{
        return getItemByRef(index);
    }

    void remove(int index) {
        if(index >= size || index < 0)
            return;
        ListItem *pre, *p, *post;
        if(size==index+1)
            end=0;
        size--;
        if(index==0){
            p=head;
            head=head->next;
            delete p;
            return;
        }
        pre = head;
        p=head->next;
        post = p->next;
        for(int i=1;i<index;i++){
            pre=p;
            p=post;
            post=post->next;
        }
        pre->next=post;
        delete p;
    }
    /*
     * добавляет элемент в список по определенному порядковому номеру. существующие, начиная с заданного порядкового номера сдвигаются вправо.
     * возвращает индекс добавленного элемента в случае успеха и -1 иначе.
     */
    int append(T *value,int index){
        if(index>=size)
            return append(value);

        ListItem *n = new ListItem(value);
        if(n==0)
            return -1;

        if(index<=0){
            n->next = head;
            head = n;
            size++;
            return 0;
        }

        ListItem *p=head;
        for(int i=1;i<index;i++,p=p->next);
        n->next = p->next;
        p->next = n;
        size++;
        return index;
    }

    void raiseUp(int index){
        if(index==0 || size<2)
            return;
        
        ListItem *pre=head,*p;
        for(int i=1;i<index && i<size;i++,pre=pre->next);
        p=pre->next;
        pre->next=pre->next->next;
        p->next=head;
        head=p;
        if(head==end)
            end=pre;
    }

//	void removeItem(T& item) {
//		remove(getIndex(item));
//	}
//	void removeAll(){
//		while(size)
//			remove(0);
//	}
//
//	int getMinIndex() const{
//		if(size<1)
//			return T();
//
//		ListItem *p=head,*min=head;
//		int i=0,result=0;
//		for(;p!=0;p=p->next,i++)
//			if(p->data < min->data)
//				min = p,result=i;
//
//		return result;
//	}
//	T getMin() const{
//		if(size<1)
//			return T();
//
//		ListItem *p=head,*result=head;
//		for(;p!=0;p=p->next)
//			if(p->data < result->data)
//				result = p;
//
//		return result->data;
//	}
//	int getMaxIndex() const{
//		if(size<1)
//			return T();
//
//		ListItem *p=head,*max=head;
//		int i=0,result=0;
//		for(;p!=0;p=p->next,i++)
//			if(p->data > max->data)
//				max = p,result=i;
//
//		return result;
//	}
//	T getMax() const{
//		if(size<1)
//			return T();
//
//		ListItem *p=head,*result=head;
//		for(;p!=0;p=p->next)
//			if(p->data > result->data)
//				result = p;
//
//		return result->data;
//	}
//
//	T& pop(){
//		if(size==0){
//			T *zero = new T();
//			return *zero;
//		}
//		T *result =& head->data;
//		if(size==1)
//			end=0;
//		head=head->next;
//		size--;
//		return *result;
//	}

//	void sort(){
//		/*
//		List t(*this);
//		removeAll();
//		while(t.getSize()){
//			insert(t.pop());
//		}*/
//		if(size<2)
//			return;
//		ListItem *prehead = new ListItem();
//		prehead->next = head;
//		for(ListItem *preunsorted = prehead;preunsorted->next!=0;preunsorted=preunsorted->next){
//			//find max
//			ListItem *premin = preunsorted,*t;
//			for(ListItem *p=premin;p->next!=0;p=p->next)
//				if(premin->next->data>p->next->data)
//					premin=p;
//			t=premin->next;
//			premin->next=premin->next->next;
//			t->next=preunsorted->next;
//			preunsorted->next=t;
//		}
//		head=prehead->next;
//		delete prehead;
//	}


//	friend istream& operator>>(istream& in, List &list){
//		int count;
//		in >> count;
//		for(int i=0;i<count;i++){
//			T item;
//			in >> item;
//			list.append(item);
//		}
//		return in;
//	}

//	void outTo(ostream& out){
//		for(ListItem *p = head; p!=0;p=p->next)
//			out << p->data << " ";
//		out << endl;
//	}
//
//	friend ostream& operator<<(ostream& out, List &list){
///*		int c = list.getSize() ;
//		out << c << " ";
//		list.
//		for(int i=0;i<c;i++)
//			out << list.pop()<< " ";
//
//		out << endl;*/
//		list.outTo(out);
//		return out;
//	}

//    /*
//     * вставка отличается от добавления тем, что сохраняется порядок(если он, конечно, есть :) )
//     * возвращает индекс нового элемента или -1, если не хватило памяти
//     */
//    int insert(const T& value){
//    	if(size==0)
//    		return append(value);
//
//    	ListItem *n = new ListItem(value), *p = head;
//    	if(n==0)
//    		return -1;
//
//    	for(;p->next!=0 && p->next->data < value; p=p->next);
//    	n->next=p->next;
//    	p->next=n;
//    	if(n->next==0)
//    		end = n;
//    	return size++;
//    }

//    /*
//     * adds n elements from array
//     * returns added elements count
//     */
//    int appendAll(T* array,int n){
//    	int added=0;
//    	for(int i=0;i<n;i++)
//    		if(append(array[i])!=-1)
//    			added++;
//    		else
//    			return added;
//    	return added;
//    }
//
//    /*
//     * создает в памяти массив из элементов списка и его возвращает
//     */
//    T* toArray(){
//    	T* result = new T[size];
//    	ListItem *p=head;
//    	for(int i=0;i<size;i++,p=p->next)
//    		result[i]=p->data;
//    	return result;
//    }
//
//    /*
//     * добавляет содержимое списка list в хвост текущего.
//     * возвращает количество добавленных элементов
//     */
//    int append(List &list){
//    	T *t = list.toArray();
//    	int result =  appendAll(t,list.getSize());
//    	delete []t;
//    	return result;
//    }

//    List(T* &fromArray,int count){
//    	(*this)();
//    	append(fromArray,count);
//    }

//    List& clone() const{
//        List *result = new List(getSize());
//        ListItem *t=result;
//        for(ListItem *p=head;p!=0;p=p->next)
//        	result->addItem(p->data);
//        return *result;
//    }
//
//	List(List& clone){
//            head = 0;
//            size=0;
//            end=0;
//            append(clone);
//	}


//	int getIndex(T& item) const {
//		int result = 0;
//		ListItem *p=head;
//		for(; p!=0 && *p->data!=item;  p=p->next,result++);
//		return p==0 ? 0 : result;
//	}

};

#endif /* LIST_H_ */
