#include <iostream>
#include <string>

std :: string reversing(std :: string half){

    int size = half.length();

    std :: string rev = "";

    for(int i = size - 1; i >= 0; i--){

        rev += half[i];

    }

    return rev;

}

int main(){

    std :: string number, answer, firsthalf, secondhalf;
    std :: cin >> number;
    char mid;
    bool singledigit = (number.length() < 2);

    int l = (number.length() + 1) / 2, size = number.length() - 1, even_odd = size % 2;

    if(even_odd == 0) mid = number[l - 1];

    firsthalf = number.substr(0, l - 1 + even_odd);

    while(1){

        secondhalf = reversing(firsthalf);

        if(!singledigit){

            if(even_odd == 0) answer = firsthalf + mid + secondhalf;
            else answer = firsthalf + secondhalf;

        }
        else answer = firsthalf;

        bool stop = 0;

        for(int i = 0; i < size + 1; i++){

            if(answer[i] > number[i]) stop = 1;

        }

        if(stop) break;

        firsthalf[l - 1 + even_odd]++;

        for(int i = l - 1 + even_odd; i > 0; i--){

            if(firsthalf[i] > '9'){

                firsthalf[i] = '0';
                firsthalf[i - 1]++;

            }

        }

        if(firsthalf[0] == 0){

            firsthalf = '1' + firsthalf;

        }

    }

    std :: cout << answer << '\n';

}
