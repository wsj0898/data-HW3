//Name 吴松骏
#include <iostream>
#include <string>
#include "hfTree.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char ch[] = "aeistdn";
    int w[] = {10, 15, 12, 3, 4, 13, 1};

    hfTree<char> tree(ch, w, 7);
    hfTree<char>::hfCode result[7];

    tree.getCode(result);

    for (int i = 0; i < 7; i++)
    {
        cout << result[i].data << "\t\t" << result[i].code << endl;
    }

    hfTree<char>::hfCode result2[7];
    string numb[7] = {"000", "01", "11", "00110", "0010", "10", "00111"};
    //cout << numb.size();

    tree.getData(result2, numb, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << result2[i].code << "\t\t" << result2[i].data << endl;
    }
    return 0;
}
