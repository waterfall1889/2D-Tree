//
// Created by waterfall on 2025-3-25.
//

#ifndef INC_2D_TREE_TREENODE_H
#define INC_2D_TREE_TREENODE_H


class Point{
public:
    double x;
    double y;
    Point() = default;
    Point(double xValue,double yValue):x(xValue),y(yValue){}

};
//definition of point


class TreeNode{
public:
    Point point;
    enum Type{xDivision,yDivision} NodeType;//the division of the node
    TreeNode *leftChild;
    TreeNode *rightChild;

    TreeNode():point(0,0),leftChild(nullptr),rightChild(nullptr),NodeType(xDivision){}

    TreeNode(Type nodeType,double xValue,double yValue,TreeNode *left= nullptr,TreeNode *right = nullptr):
            point(xValue,yValue),leftChild(left),rightChild(right),NodeType(nodeType){}

};


#endif //INC_2D_TREE_TREENODE_H
