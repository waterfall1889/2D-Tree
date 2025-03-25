//
// Created by waterfall on 2025-3-25.
// definition of 2-D tree
// functions:
// 1.build
// 2.search
// 3.find the point in a certain set
// 4.find the nearest neighbour
#pragma once
#ifndef INC_2D_TREE_TWODIMENSIONTREE_H
#define INC_2D_TREE_TWODIMENSIONTREE_H
#include "TreeNode.h"
#include "ToolFunctions.h"

class TwoDimensionTree {
private:
    void clear(TreeNode *target);

public:
    TreeNode *root;

    TwoDimensionTree():root(nullptr){}
    TwoDimensionTree(std::vector<Point> &array);
    ~TwoDimensionTree();

    void clear();
    void buildTree(std::vector<Point> &array,TreeNode *&target,char type);
    bool search(double x,double y)const;

    void traverse(TreeNode *node, const std::string &order);
    void traverse(const std::string &order);

    bool PointInSquare(int xMin,int yMin,int xMax,int yMax,std::vector<Point> &pointSet) const;
};


#endif //INC_2D_TREE_TWODIMENSIONTREE_H
