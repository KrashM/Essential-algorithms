#include<bits/stdc++.h>

class Vector{

    private:
        int SIZE = 1;
        int* V = new int[SIZE];
        int index;

        void SizeDown(){

            SIZE = index - 1;
            int* r = new int[SIZE];
            r = V;
            V = r;

        }

        void SizeUp(){

            int* r = new int[++SIZE];
            r = V;
            V = r;

        }

    public:
        Vector(){

            index = 0;

        }

        void Push_Back(int x){

            V[index] = x;
            index++;
            SizeUp();

        }

        void RemoveAt(int i){

            index--;
            for(; i < index; i++) V[i] = V[i + 1];
            //V[index] = (1 << 30);
            SizeDown();

        }

        void Insert(int i, int x){

            index++;
            for(int j = index; j >= i; j--) V[j + 1] = V[j];
            V[i] = x;
            SizeUp();

        }

        void Erase(int x){

            int j;

            //for(int i = 0; i < index; i++)
            //    if(V[i] == x) { j = i; break; }

            int offset = 1;

            for(int j = -1; j < index; j++){

                if(V[j + 1] == x) offset++;
                V[j] = V[j + offset];

            }

            index -= offset;

            SizeDown();

        }

        void Show(){

            for(int i = 0; i < index; i++) std :: cout << V[i] << ' ';
            std :: cout << '\n';

        }

        void Sort(){

            std :: queue <int> numbers[10];

            int max = V[0];

            for(int i = 1; i < SIZE; i++) max = ((int)log10(V[i]) + 1 > max) ? (int)log10(V[i]) + 1 : max;

            int powerOf10 = 1;

            for(int i = 0; i < max; i++){

                for(int i = 0; i < index; i++) numbers[(V[i] / powerOf10) % 10].push(V[i]);

                int index = 0;

                for(int i = 0; i < 10; i++){

                    while(!numbers[i].empty()){

                        V[index] = numbers[i].front();
                        numbers[i].pop();
                        index++;

                    }

                }

                powerOf10 *= 10;

            }



        }

        int ShowLast(){

            return V[index];

        }

};

int main(){

    Vector v;
    int x;

    while(std :: cin >> x) v.Push_Back(x);

    v.Show();

    v.RemoveAt(4);

    v.Show();

    v.Insert(4, 10);

    v.Show();

    v.Erase(50);

    v.Show();

    v.Sort();

    v.Show();

    std :: cout << v.ShowLast();

}
///1 5 6 7 8 1 50 0 13 45 6 10 1 2 3 7 8 50 36 5 6 8 9 1 4 50 ^Z
