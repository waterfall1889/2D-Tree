//
// Created by waterfall on 2025-3-25.
// tool functions
//

#ifndef INC_2D_TREE_TOOLFUNCTIONS_H
#define INC_2D_TREE_TOOLFUNCTIONS_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "TreeNode.h"

void sortByX(std::vector<Point> &array);

void sortByY(std::vector<Point> &array);

Point medium_x_point(std::vector<Point> &array);

Point medium_y_point(std::vector<Point> &array);

bool isSamePoint(Point p1,Point p2);

#endif //INC_2D_TREE_TOOLFUNCTIONS_H
