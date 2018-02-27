//
//  Student.cpp
//  Schedule Optimization
//
//  Created by Diego Brown on 2/13/18.
//  Copyright © 2018 Diego Brown. All rights reserved.
//

#include "Student.hpp"
#include <array>
#include <vector>
#include <map>

using namespace std;
Student::Student(){
    this-> preference = "XXXXX";
    this-> utility = 10000;
    this-> location = -1;
    this -> lab = 10;
}
void Student::set_Location(int i){
    this->location = i;
}
int Student::get_location(){
    return this -> location;
}

void Student::set_preference(string sp){
    this -> preference = sp;
}
void Student::set_preference(map<int,string> m){
    this-> preference = m.find(this->get_location())->second;
}

    
string Student::get_preference(){
    return this -> preference;
    
}

int Student::get_lab(){
    return this -> lab;
}
void Student::set_lab(){
    if (this -> location < 20){
        this -> lab = 1;
    }
    else if(this -> location >= 20 && this->location <40){
        this-> lab = 2;
    }
    else if(this -> location >= 40 && this->location <60){
        this-> lab = 3;
    }
    else if(this -> location >= 60 && this->location <80){
        this-> lab = 4;
    }
    else {
        this-> lab = 5;
    }
}

void Student::set_lab(int a){
    if (a < 20){
        this -> lab = 1;
    }
    else if(a >= 20 && a <40){
        this-> lab = 2;
    }
    else if(a >=40 && a< 60){
        this-> lab = 3;
    }
    else if(a >= 60&& a < 80){
        this-> lab = 4;
    }
    else {
        this-> lab = 5;
    }
}




void Student::set_utility(){
    array<char, 5> a;
        map<char, int> m;
        pair<char, int>pr;
        pr.second = 'A';
        pr.first = 1;
        m.insert(pr);
        pr.second = 'B';
        pr.first = 2;
        m.insert(pr);
        pr.second = 'C';
        pr.first = 3;
        m.insert(pr);
        pr.second = 'D';
        pr.first = 4;
        m.insert(pr);
        pr.second = 'E';
        pr.first =5;
        m.insert(pr);
    
    
    
    this-> get_preference();
    
    char target = m.find(lab)->second;
    
    for(int i = 0; i< 5; i++){
        
        if(this-> get_preference()[i] == target){
            this-> utility = (i+1)*(i+1);
            break;
        }
        else if(this -> get_preference()[i]== 'X'){
            this-> utility = 1;
            break;
        }
        else continue;
        
    }
}
int Student::get_utility(){
    return this->utility;
}
    
    

