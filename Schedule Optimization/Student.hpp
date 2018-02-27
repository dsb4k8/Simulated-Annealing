//
//  Student.hpp
//  Schedule Optimization
//
//  Created by Diego Brown on 2/13/18.
//  Copyright © 2018 Diego Brown. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class Student{
private:
    int location,lab,utility;
    string preference;
public:
    Student();
    void set_Location(int);
    int get_location();
    void set_preference(string);
    void set_preference(map<int,string>);

    string get_preference();
    
    int get_lab();
    void set_lab();
    void set_lab(int);
    void set_lab(array<Student, 100>);
    
    void set_utility();
    int get_utility();

};
#endif /* Student_hpp */
