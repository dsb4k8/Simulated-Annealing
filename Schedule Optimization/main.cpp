//
//  main.cpp
//  Schedule Optimization
//
//  Created by Diego Brown on 2/10/18.
//  Copyright © 2018 Diego Brown. All rights reserved.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <array>
#include <cmath>
#include <vector>
#include "Student.hpp"



using namespace std;
double T;

double e = M_E;


double probability_of_acceptance(double s2, double s1, double temp){
    
    double base = (s2-s1);
    double exponent = (base * -1);
    double second_term = exponent/temp;
    double probability = pow(e,second_term);
    
    return 100*probability;
    
}


map<int,string> copy;

array <Student,100> shufflepair(array<Student, 100> prim_array){
    int switchindexes [2];
    int max = 100;
    int min = 0;
    
 
    pair<int, int> p;
    
    //create random number to be used as indexes for swap
    for(int i = 0; i <= 1; i++){
        int randNum = rand()%(max-min + 1) + min;
        switchindexes[i] = randNum;
        p.first = switchindexes[0];
    }


    swap(prim_array[p.first], prim_array[p.second]);
    prim_array[p.first].set_preference(prim_array[p.first].get_preference());
    prim_array[p.second].set_preference(prim_array[p.second].get_preference());

    array<Student, 100> indexed_array;
    
    
    for(int o = 0; o < 100; o++){
 
        indexed_array[o] = prim_array[o];
        indexed_array[o].set_lab(o);
    }

    //indexed_array[switchindexes[0]].set_Location(<#int#>)
    
    array <Student,100> s = indexed_array;//prim_array;

    return s;
    
}


int main(){
    
    map<int,string> m;
    map<int,string> copy;
    
    ifstream fin;
    fin.open("L1.txt");
    string first, second, third, fourth, fifth;
    int ID;
    while(fin >> ID >>first>> second >> third >> fourth >> fifth){
        pair<int, string> p;
        p.first = ID;
        p.second = first+second+third+fourth+fifth;
        m.insert(p);
        copy.insert(p);
    }
    fin.close();
    
//create array from map
    array<Student,100> prim_array;
    int count = 0;
    for (auto it = m.begin(); it != m.end(); it++){
        
        Student* newstudent = new Student;
        newstudent -> set_Location(m.find(count+1)-> first);
        newstudent -> set_preference(copy);
        newstudent -> set_lab();

        prim_array[count] = *newstudent;
        
        count++;
            }
    
    
    

//    int sum = 0;
    array<double,1000> averages;

    double T = 100;
    

    
    while(T>0){
        int u = 1; //under
        int count = 0;
        double Last_value;
        while(u<1000){
        
            array<int, 100> a;
            
           // DISPLAYS ALL STUDENT INFORMATION INCLUDING ID, LAB, PREFERENCE
            
            for(int i = 0; i < 100; i++){
                prim_array.at(i).set_lab(i);
                prim_array.at(i).set_utility();
                prim_array.at(i).set_preference(copy);///////////////////////////////////////////////
                
                //cout<<"Student ID "<<prim_array.at(i).get_location()<<", is in lab # "<< prim_array.at(i).get_lab()<<" Preference: '"<<prim_array.at(i).get_preference()<<"'. UTILITY = "<< prim_array.at(i).get_utility()<<endl<<endl;
                a.at(i) = prim_array.at(i).get_utility();
                
            }
            double sumation = 0.0;
            double avg = 0.0;
            for (int h = 0; h< 100; h++){
                sumation+= a.at(h);
            }
            
            avg = sumation/100;
            
            
            double prob = probability_of_acceptance(avg, averages[count -1], T);
            bool TrueFalse = rand() %100 < prob;
            
            
//            if(prob < .05){
//                cout<<"Skipped        PROB = "<<prob<<"  unlikely   "<< avg<<" > "<<averages[count-1]<<endl;
//                prim_array = shufflepair(prim_array);
//                continue;
//            }
            
            if(u == 1){
                if(count==0){
                averages[0] = avg;
                Last_value = avg;
                cout<<avg<<"_ADDED_____________________________________T = "<< T <<endl;
                }
                else{
                    averages[0] = Last_value;
                }
//                continue;
            }
 
            else if (avg > averages[count -1]){
                if(prob < .05){
                    cout<<"Skipped        PROB = "<<prob<<"  unlikely   "<< avg<<" > "<<averages[count-1]<<endl;
                    prim_array = shufflepair(prim_array);
                    continue;
                }
                else if(TrueFalse){
                    cout<<avg<<"_ADDED____PROBABILITY:___"<<prob<<"____________T = "<< T <<endl;
                    averages[count] = avg;
                    Last_value = avg;
                    count++;
                    u++;
                    continue;
                }
                else
                    cout<<"Skipped        PROB = "<<prob<<"             "<< avg<<" > "<<averages[count-1]<<endl;
                    continue;
            }
            else if(avg < averages[count -1]){
                cout<<avg<<"_ADDED____PROBABILITY:___"<<prob<<"____________T = "<< T <<endl;
                averages[count] = avg;
                Last_value = avg;
                count++;
                u++;
                continue;
            }
            
            prim_array = shufflepair(prim_array);
            u++;
            count++;
            continue;
        }
        T = .95* T;
        
    }
    return 0;
}
