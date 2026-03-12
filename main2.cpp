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
                {
                    int x = s.pop();

                    if(x == -1 || x != '['){
                        correct = false;
                    }
                    break;
                }

                case '}':
                {
                    int x = s.pop();

                    if(x == -1 || x != '{'){
                        correct = false;
                    }
                    break;
                }
            }

            if(!correct) break;
        }

        // check remaining open brackets ONLY if no mismatch occurred
        if(correct && s.pop() != -1)
            correct = false;

        if(correct)
            cout<<"correct"<<endl;
        else
            cout<<"incorrect"<<endl;
    }

    return 0;
}