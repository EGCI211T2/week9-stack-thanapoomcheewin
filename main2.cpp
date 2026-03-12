#include<iostream>
#include<cstring>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){

    int i,j;

    for(i=1;i<argc;i++){

        Stack s;
        bool correct = true;

        for(j=0;j<strlen(argv[i]);j++){

            switch(argv[i][j])
            {
                case '[':
                case '{':
                    s.push(argv[i][j]);
                    break;

                case ']':
                case '}':
                {
                    int x = s.pop();

                    if(x == -1){   // empty stack
                        correct = false;
                        break;
                    }

                    if(argv[i][j] == ']' && x != '[')
                        correct = false;

                    if(argv[i][j] == '}' && x != '{')
                        correct = false;

                    break;
                }
            }

            if(!correct) break;
        }

        
        if(s.pop() != -1)
            correct = false;

        if(correct)
            cout<<"argv "<<i<<" correct"<<endl;
        else
            cout<<"argv "<<i<<" incorrect"<<endl;
    }

   return 0;
}