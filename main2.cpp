#include<iostream>
#include<cstring>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){

    int i,j;

    for(i=1;i<argc;i++){

        Stack s;
        bool mismatch = false;
        bool tooManyClose = false;

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

                    if(x == -1){
                        tooManyClose = true;
                    }
                    else if(x != '['){
                        mismatch = true;
                    }

                    break;
                }

                case '}':
                {
                    int x = s.pop();

                    if(x == -1){
                        tooManyClose = true;
                    }
                    else if(x != '{'){
                        mismatch = true;
                    }

                    break;
                }
            }

            if(mismatch || tooManyClose)
                break;
        }

        if(tooManyClose)
            cout<<"too many close"<<endl;

        else if(mismatch)
            cout<<"mismatch"<<endl;

        else if(!s.isEmpty())
            cout<<"too many open"<<endl;

        else
            cout<<"correct"<<endl;
    }

    return 0;
}