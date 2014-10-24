//main.cpp
//Name 吴松骏 Num 5132119049
//2014.10.24 21:43
#include <iostream>
#include <fstream>
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

//-------------------------------------------------------------------------------------
    ifstream infile("myinfile.in");
    ofstream outfile("myoutfile.out");
    if (!infile)
    {
        cerr << "输入文件无法打开！" << endl;
        return 1;
    }
    if (!outfile)
    {
        cerr << "输出文件无法打开！" << endl;
        return 2;
    }

    int mySize1;
    infile >> mySize1;
    //cout << mySize1 << endl;
    char mych1[mySize1 + 1];
    for (int i = 0; i < mySize1; ++i)
    {
        infile >> mych1[i];
    }
    mych1[mySize1] = '\0';

/*
    for (auto i:mych1)
        cout << i << endl;
*/

    int myWeight1[mySize1];
    for (int i = 0; i < mySize1; ++i)
    {
        infile >> myWeight1[i];
    }

/*
    for (auto i:myWeight1)
        cout << i << endl;
*/
    hfTree<char> myTree1(mych1, myWeight1, mySize1);
    hfTree<char>::hfCode myResult1[mySize1];
    myTree1.getCode(myResult1);

    outfile << "编码结果" << endl;
    for (int i = 0; i < mySize1; ++i)
    {
        outfile << myResult1[i].data << "\t\t" << myResult1[i].code << endl;
    }

    int mySize2;
    infile >> mySize2;
    hfTree<char>::hfCode myResult2[mySize2];
    string myNum[mySize2];
    for (int i = 0; i < mySize2; ++i)
    {
        infile >> myNum[i];
    }

/*
    for (auto i:myNum)
        cout << i << endl;
*/

    myTree1.getData(myResult2, myNum, mySize2);
    outfile << "译码结果" << endl;
    for (int i = 0; i < mySize2; ++i)
    {
        outfile << myResult2[i].code << "\t\t" << myResult2[i].data << endl;
    }

//-----------------------------------------------------------------------------------------------

    int mySize3;
    infile >> mySize3;
    //cout << mySize3 << endl;
    char mych2[mySize3 + 1];
    for (int i = 0; i < mySize3; ++i)
    {
        infile >> mych2[i];
    }
    mych2[mySize3] = '\0';

/*
    for (auto i:mych2)
        cout << i << endl;
*/

    int myWeight2[mySize3];
    for (int i = 0; i < mySize3; ++i)
    {
        infile >> myWeight2[i];
    }

/*
    for (auto i:myWeight1)
        cout << i << endl;
*/
    hfTree<char> myTree2(mych2, myWeight2, mySize3);
    hfTree<char>::hfCode myResult3[mySize3];
    myTree2.getCode(myResult3);

    outfile << "编码结果" << endl;
    for (int i = 0; i < mySize3; ++i)
    {
        outfile << myResult3[i].data << "\t\t" << myResult3[i].code << endl;
    }

    int mySize4;
    infile >> mySize4;
    hfTree<char>::hfCode myResult4[mySize4];
    string myNum2[mySize4];
    for (int i = 0; i < mySize4; ++i)
    {
        infile >> myNum2[i];
    }

/*
    for (auto i:myNum)
        cout << i << endl;
*/

    myTree2.getData(myResult4, myNum2, mySize4);
    outfile << "译码结果" << endl;
    for (int i = 0; i < mySize4; ++i)
    {
        outfile << myResult4[i].code << "\t\t" << myResult4[i].data << endl;
    }

    return 0;
}
