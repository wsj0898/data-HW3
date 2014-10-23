#ifndef _hfmanTree
#define _hfmanTree

#include <string>
using namespace std;

template<class T>
class hfTree
{
private:
	struct Node
	{
		T data;
		int weight;
		int parent, left, right;
	};

	Node *elem;
	int length;

public:
	struct hfCode
	{
		T data;
		string code;
	};

	hfTree(const T *x, const int *w, int size);
	void getCode(hfCode result[]);
	//void getData(hfCode result[], string *myCode);
	void getData(hfCode result[], string mycode[], int mySize);
	~hfTree()
	{
		delete[] elem;
	}
};

template<class T>
hfTree<T>::hfTree(const T *v, const int *w, int size)
{
	const int MAX_INT = 32700;
	int min1, min2;
	int x, y;

	length = 2 * size;
	elem = new Node[length];
	for (int i = size; i < length; ++i)
	{
		elem[i].weight = w[i - size];
		elem[i].data = v[i - size];
		elem[i].parent = 0;
		elem[i].left = 0;
		elem[i].right = 0;
	}

	//归并
	for (int i = size -1; i > 0; --i)
	{
		min1 = MAX_INT;
		min2 = MAX_INT;
		x = 0;
		y = 0;

		for ( int j = i + 1; j < length; ++j)
		{
			if ( elem[j].parent == 0)
			{
				if (elem[j].weight < min1)
				{
					min2 = min1;
					min1 = elem[j].weight;
					x = y;
					y = j;
				}
				else if (elem[j].weight < min2)
				{
					min2 = elem[j].weight;
					x = j;
				}
			}
		}

        elem[i].weight = min1 + min2;
        elem[i].left = x;
        elem[i].right = y;
        elem[i].parent = 0;
        elem[x].parent = i;
        elem[y].parent = i;
	}
}

template<class T>
void hfTree<T>::getCode(hfCode result[])
{
    cout  << "开始编码" << endl;
    int size = length / 2;
    int p, s;
    for (int i = size; i < length; ++i)
    {
        result[i - size].data = elem[i].data;
        result[i - size].code = "";
        p = elem[i].parent;
        s = i;
        while (p)
        {
            if (elem[p].left == s)
                result[i - size].code = '0' + result[i - size].code;
            else
                result[i - size].code = '1' + result[i - size].code;

            s = p;
            p = elem[p].parent;
        }
    }
}

template<class T>
void hfTree<T>::getData(hfCode result[], string mycode[], int mySize)
{
    cout << "开始解码" << endl;
    for (int i = 0; i < mySize; i++)
    {
        result[i].code = mycode[i];
    }
    //从根节点开始寻找，遇到0往左，遇到1往右

    for (int i = 0; i < mySize; i++)
    {
        int codeMaxSize = result[i].code.size();
        //cout << codeMaxSize << endl;
        //寻找数据下标
        int s = 1;
        //指向当前编码中一个数字的下标
        int n = 0;
        while (n < codeMaxSize)
        {
            if (result[i].code[n] == '0')
                s = elem[s].left;
            else
                s = elem[s].right;
            //cout << "s is " << s << endl;
            n++;
        }

        result[i].data = elem[s].data;
    }
    return;
}

/*
template<class T>
void hfTree<T>::getData(hfCode result, string *mycode)
{
        return;
}
*/

#endif // _hfmanTree
