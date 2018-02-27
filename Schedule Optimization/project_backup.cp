//
//  main.cpp
//  Schedule Optimization
//
//  Created by Diego Brown on 2/10/18.
//  Copyright © 2018 Diego Brown. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <array>
#include "Student.hpp"


using namespace std;


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
    
//    Student a = prim_array[p.first];
//    Student b = prim_array[p.second];
//    int lab_a = a.get_lab();
//    int lab_b = b.get_lab();
//
//    a.set_lab(lab_b);
//    b.set_lab(lab_a);
    

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



//NEED FUNCTION TO ASSIGN LOCATION TO STUDENT



//Necessary for checking fitness
//returns float value representitive of the of the average utility per student

int fitness_check();



int main(){
    
    map<int,string> m;
    
    ifstream fin;
    fin.open("L1.txt");
    string first, second, third, fourth, fifth;
    int ID;
    while(fin >> ID >>first>> second >> third >> fourth >> fifth){
        pair<int, string> p;
        p.first = ID;
        p.second = first+second+third+fourth+fifth;
        m.insert(p);
    }
    fin.close();
    
//create array from map
    array<Student,100> prim_array;
    int count = 0;
    for (auto it = m.begin(); it != m.end(); it++){
        
        Student* newstudent = new Student;
        newstudent -> set_Location(m.find(count+1)-> first);
        newstudent -> set_preference(m.find(count+1)-> second);
        newstudent -> set_lab();
        //newstudent -> set_utility();                                      ///////////recently 
        
//        cout<<newstudent->get_location()<<endl;
//        cout<<newstudent->get_preference()<<endl;
        prim_array[count] = *newstudent;
        
                //cout<<it -> first<< it-> second << endl;
        count++;
            }
    //array<Student,100> newprim_array;
    for(int u = 0; u < 26; u++){
        array<int, 100> a;
        
       // newprim_array = shufflepair(prim_array);
        for(int i = 0; i < 100; i++){
            prim_array.at(i).set_lab(i);
            prim_array.at(i).set_utility();
            
            cout<<"Student ID "<<prim_array.at(i).get_location()<<", is in lab # "<< prim_array.at(i).get_lab()<<" Preference: '"<<prim_array.at(i).get_preference()<<"'. UTILITY = "<< prim_array.at(i).get_utility()<<endl;
            a.at(i) = prim_array.at(i).get_utility();
            
            
            
        }
        
        float sumation = 0.0;
        float avg = 0.0;
        for (int h = 0; h< 100; h++){
            sumation+= a.at(h);
            
            //cout<< sumation<<endl<<endl<<endl;
        }
         avg = sumation/100;
        
        
        prim_array = shufflepair(prim_array);
        
        for(int x = 0; x < prim_array.size(); x++){
            prim_array.at(x).set_lab();
            //prim_array[x].set_preference(pref);
            
            

            //prim_array.at(x).set_preference(prim_array[x].get_preference());
        }
        
        cout<<endl<<"Average for round "<< u <<" is: "<<avg<<endl;
    
    }
    cout<<prim_array.at(38).get_utility()<<endl<<endl;
    
    
    
    return 0;
}

