//
// Created by waterfall on 2025-3-25.
//

#include <functional>
#include "TwoDimensionTree.h"

TwoDimensionTree::TwoDimensionTree(std::vector<Point> &array) {
    root = nullptr;
    buildTree(array,root,'x');
}

TwoDimensionTree::~TwoDimensionTree() {
    clear();
}

void TwoDimensionTree::clear(TreeNode *target) {
    if(target == nullptr){
        return;
    }
    clear(target->leftChild);
    clear(target->rightChild);
    delete target;
}

void TwoDimensionTree::clear() {
    clear(root);
}

void TwoDimensionTree::buildTree(std::vector<Point> &array,TreeNode *&target,char type) {
    if(array.empty()){
        return;
    }

    if(type == 'x'){
        std::vector<Point> leftArray;
        std::vector<Point> rightArray;
        Point data = medium_x_point(array);
        auto item = array.begin();
        for(; !isSamePoint(*item,data);++item){
            leftArray.push_back(*item);
        }
        item ++;
        for(; item != array.end();++item){
            rightArray.push_back(*item);
        }
        target = new TreeNode(TreeNode::xDivision,data.x,data.y);
        buildTree(leftArray,target->leftChild,'y');
        buildTree(rightArray,target->rightChild,'y');
        return;
    }

    else if(type == 'y'){
        std::vector<Point> leftArray;
        std::vector<Point> rightArray;
        Point data = medium_y_point(array);
        auto item = array.begin();
        for(; !isSamePoint(*item,data);++item){
            leftArray.push_back(*item);
        }
        item ++;
        for(; item != array.end();++item){
            rightArray.push_back(*item);
        }
        target = new TreeNode(TreeNode::yDivision,data.x,data.y);
        buildTree(leftArray,target->leftChild,'x');
        buildTree(rightArray,target->rightChild,'x');
        return;
    }
    else{
        std::cerr<<"Invalid build command:cannot build from "<<type<<"-division"<<std::endl;
    }
}

bool TwoDimensionTree::search(double x, double y) const {
    TreeNode *position = root;
    while(position){
        if (x == position->point.x && y == position->point.y){
            return true;
        }
        if(position->NodeType == TreeNode::xDivision){
            if(x < position->point.x){
                position = position->leftChild;
            }
            else if(x > position->point.x){
                position = position->rightChild;
            }
            else if(x == position->point.x){
                if(y < position->point.y){
                    position = position->leftChild;
                }
                else{
                    position = position->rightChild;
                }
            }
        }
        else{
            if(y < position->point.y){
                position = position->leftChild;
            }
            else if(y > position->point.y){
                position = position->rightChild;
            }
            else if(y == position->point.y){
                if(x < position->point.x){
                    position = position->leftChild;
                }
                else{
                    position = position->rightChild;
                }
            }
        }
    }
    return false;
}

void TwoDimensionTree::traverse(TreeNode *node, const std::string &order) {
    if (!node) return;

    if (order == "preorder") {
        std::cout << "(" << node->point.x << ", " << node->point.y << ") ";
        traverse(node->leftChild, order);
        traverse(node->rightChild, order);
    }
    else if (order == "inorder") {
        traverse(node->leftChild, order);
        std::cout << "(" << node->point.x << ", " << node->point.y << ") ";
        traverse(node->rightChild, order);
    }
    else if (order == "postorder") {
        traverse(node->leftChild, order);
        traverse(node->rightChild, order);
        std::cout << "(" << node->point.x << ", " << node->point.y << ") ";
    }
}

void TwoDimensionTree::traverse(const std::string &order) {
    traverse(root, order);
    std::cout << std::endl;
}

bool TwoDimensionTree::PointInSquare(int xMin, int yMin, int xMax, int yMax, std::vector<Point> &pointSet) const {
    if (!root) {
        return false;
    }

    pointSet.clear();

    std::function<void(TreeNode*)> searchInRange = [&](TreeNode* node) {
        if (!node) return;
        Point p = node->point;
        if (p.x >= xMin && p.x <= xMax && p.y >= yMin && p.y <= yMax) {
            pointSet.push_back(p);
        }
        searchInRange(node->leftChild);
        searchInRange(node->rightChild);
    };

    searchInRange(root);
    return !pointSet.empty();
}


