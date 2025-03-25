#include <iostream>
#include "TwoDimensionTree.h"

using namespace std;

int main() {
    std::vector<Point> array;
    for(int i = 0;i <= 6;++i){
        Point p(i,i+1);
        array.push_back(p);
    }
    TwoDimensionTree Tree(array);
    Tree.traverse("inorder");
    cout << Tree.search(1,1) <<endl;
    std::vector<Point> list;
    Tree.PointInSquare(2,2,3,3,list);
    for(auto item = list.begin();item != list.end();++item){
        std::cout<< (*item).x <<"-" <<(*item).y<<std::endl;
    }
}
