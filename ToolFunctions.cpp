//
// Created by waterfall on 2025-3-25.
//

#include "ToolFunctions.h"

void sortByX(std::vector<Point> &array){
    std::sort(array.begin(), array.end(), [](const Point &a, const Point &b) {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    });
}

void sortByY(std::vector<Point> &array){
    std::sort(array.begin(), array.end(), [](const Point &a, const Point &b) {
        return (a.y < b.y) || (a.y == b.y && a.x < b.x);
    });
}

Point medium_x_point(std::vector<Point> &array){
    //medium point divided by x-value;
    if(array.empty()){
        std::cerr << "Fail to find the medium point divided by x-value:Empty point vector" <<std::endl;
        Point p(0,0);
        return p;
    }
    sortByX(array);
    return array[array.size()/2];

}

Point medium_y_point(std::vector<Point> &array){
    //medium point divided by y-value;
    if(array.empty()){
        std::cerr << "Fail to find the medium point divided by y-value:Empty point vector" <<std::endl;
        Point p(0,0);
        return p;
    }
    sortByY(array);
    return array[array.size()/2];
}

bool isSamePoint(Point p1,Point p2){
    return (p1.x == p2.x)&&(p1.y == p2.y);
}
