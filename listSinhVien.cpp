#include<bits/stdc++.h>
using namespace std;
class SV{
	int msv, ns;
	string ht, gt, qq;
public:
	SV();
	SV(int,string,int,string,string);
	friend ostream&operator<<(ostream &, SV);
	friend istream&operator>>(istream &, SV &);
};
SV::SV(){
	msv = ns = 0;
	ht = gt = qq = "";
}
SV::SV(int msv, string ten, int ns, string gt,string qq)
{
	this->msv = msv;
	this->ht = ten;
	this->gt = gt;
	this->ns = ns;
	this->qq = qq;
}
ostream &operator<<(ostream &os, SV a)
{
	os << setw(10) << left << a.msv << "|" << setw(25) << left << a.ht << "|" << setw(10) << left << a.ns << "|" << setw(7) << left << a.gt << "|" << setw(15) << left << a.qq <<endl;
	return os;
}
istream &operator>>(istream &is, SV &a)
{
	cout << "MSV: ";
	is >> a.msv;
	cin.ignore();
	cout << "Ten: ";
	getline(cin, a.ht);
	cout << "Ngay sinh: ";
	is >> a.ns;
	cout << "Gioi tinh: ";
	is >> a.gt;
	cin.ignore();
	cout << "Que quan: ";
	getline(cin, a.qq);
	return is;
}
template<class T>
class Node
{
	private:
		T elem;
		Node *next;
		Node *pre;
	public:
		Node(){ next = NULL; pre = NULL;}		
		Node *getNext()
		{
			return next;
		}
		void setNext(Node *p)
		{
		    next = p;
		}
	 //---------------------------------
		Node *getPre()
		{
		  return pre;
		}
	 //---------------------------------
	  void setPre(Node *p)
	  {
		  pre = p;
	  }
	 //---------------------------------
		T getElem()
		{
			return elem;
		}
	 //----------------------------------
		void setElem(T e)
		{
		  elem = e;
		}
 };
 
//Lop Double List
template<class T>
class  List
{
	private:
		Node<T> *header;
		Node<T> *trailer;
		long count;  //luu so phan tu hien co cua danh sach
	public:
		List()
		{
			 header  = NULL;
			 trailer = NULL;
			 count   = 0;
		}
		long size()
		{   //Phuong thuc tra lai so phan tu hien co cua danh sach
			 return count;
		}
		//Phuong thuc cho biet danh sach co rong hay khong
		int  isEmpty()
		{ 
		   return count==0;
		}
		Node<T> *first(){ return header;}
		Node<T> *last() { return trailer;}
		///------- cac phuong thuc nay cai dat ben ngoai lop ----------------
		void replace(Node<T>*p,T e);
		Node<T> *insertAfter(Node<T> *p, T e);
		Node<T> *insertBefore(Node<T> *p, T e);
		Node<T> *insertFirst(T e);
		Node<T> *insertLast(T e);
		void remove(Node<T> *p);
		Node<T> *getNode(int i);
	};
	template<class T>
	void List<T>::replace(Node<T>*p, T e)
	{
		p->setElem(e);
	}
	//
	template<class T>
	Node<T>* List<T>::insertAfter(Node<T>*p, T e)
	{
		 Node<T>* q;
		 q = new Node<T>;
		 q->setElem(e);
		 if(p==trailer) //p la phan tu cuoi cua danh sach
		 {
			 p->setNext(q);
			 q->setPre(p);
			 trailer = q;
		 }
		 else //p khong la phan tu cuoi
		 {
			 q->setNext(p->getNext());
			 p->getNext()->setPre(q);
			 q->setPre(p);
			 p->setNext(q);
		 }
		 count++;
		 return q;
	 }
	 //-------------------------------------------------------------
	template <class T>
	Node<T>* List<T>::insertBefore(Node<T>*p, T e)
	{
		 Node<T>* q;
		 q = new Node<T>;
		 q->setElem(e);
		 if(p==header)    //p trung voi phan tu dau cua danh sach
		 {
			header->setPre(q);
			q->setNext(header);
			header = q;
		 }
		 else            //p khong trung voi phan tu dau cua danh sach
		 {
			  p->getPre()->setNext(q);
			  q->setPre(p->getPre());
			  q->setNext(p);
			  p->setPre(q);
		 }
		 count++;
		 return q;
	  }
	 //--------------------------------------------------------------
	  template <class T>
		Node<T>* List<T>::insertFirst(T e)
		{
			Node<T>* q;
			q = new Node<T>;
			q->setElem(e);
			if(isEmpty())
			{
				trailer = q;
				header  = q;
			}
			else
			{
			  q->setNext(header);
			  header->setPre(q);
			  header = q;
			}
			count++;
			return q;
		}
		//------------------------------------------------------------------
		template <class T>
		Node<T> * List<T>::insertLast(T e)
		{
			Node<T>* q;
			q = new Node<T>;
			q->setElem(e);
			if(isEmpty())
			{
				trailer = q;
				header  = q;
			}
			else
			{
				trailer->setNext(q);
				q->setPre(trailer);
				trailer = q;
			}
			count++;
			return q;
		}
	  //----------------------------------------------------------------------
		template <class T>
		void List<T>::remove(Node<T> *p)
		{
			if(p==header)
			{
				header = header->getNext();
				if(header!=NULL)
					header->setPre(NULL);
			}
			else
			if(p==trailer)
			{
				trailer = trailer->getPre();
				if(trailer!=NULL)
				   trailer->setNext(NULL);
			}
			else
			{
					p->getNext()->setPre(p->getPre());
					p->getPre()->setNext(p->getNext());
			 }
			 delete p;
			 count--;  
		}

 
int main(){
SV a(1,"An",1998,"Nam","HaNam");
SV b(2,"Be",1999,"Nu","HaNoi");
SV c(3,"Se",2000,"Nam","VinhPhuc");

List<SV> listSV;
/*listSV.insertFirst(a);
listSV.insertFirst(b);
listSV.insertFirst(c);
*/
/*
listSV.insertLast(a);
listSV.insertLast(b);
listSV.insertLast(c);
*/
listSV.insertFirst(a);
listSV.insertAfter(listSV.first(),b);
listSV.insertBefore(listSV.first()->getNext(),c);

Node<SV> *p = listSV.first();
while(p){
	cout<<p->getElem();
	p = p->getNext();
}
/*Node<SV> N1,N2,N3;
N1.setElem(a);
N2.setElem(b);
N3.setElem(c);
N1.setNext(&N2);
N1.setPre(NULL);
N2.setNext(&N3);
N2.setPre(&N1);
N3.setNext(NULL);
N3.setPre(&N2);
Node<SV> *p;
p = &N1;
while(p){
	cout<<p->getElem();
	p = p->getNext();
}
*/
}

