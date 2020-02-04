//
// Created by Leslie De Jesus on 11/6/19.
//

#ifndef CS14LAB6_STACK_H
#define CS14LAB6_STACK_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 20;
template <typename T>
class stack{
private:
    T data[MAX_SIZE];
    int size;
public:
    stack() { //constructs empty stack
        size = 0;
    }
    void push(T val){

        if (size >= MAX_SIZE) {
            throw overflow_error("Called push on full stack.");
        }
        data[MAX_SIZE - size - 1] = val;
        size++;
//        }
//        catch (overflow_error& except){
//            cout << "Called push on full stack." << endl;
//        }
    }
    void pop(){
        if (size == 0){
            throw out_of_range("Called pop on empty stack.");
        }
        size--;
//        catch(out_of_range& except){
//            cout << "Called pop on empty stack." << endl;
//        }
    }
    T top(){
        if (size == 0) {
            throw underflow_error("Called top on empty stack.");
        }
        return data[MAX_SIZE - size];
//        catch(underflow_error& except){
//            cout << "Called top on empty stack." << endl;
//        }
    }
    bool empty(){
        return size == 0;
    }
};




#endif //CS14LAB6_STACK_H
