#include<bits/stdc++.h>

int main(){

    std :: pair<int, int> cords[6];

    int x, y, closest, min = (1 << 30);

    for(int i = 0; i < 5; i += 2){

        std :: cin >> x >> y;
        cords[i] = std :: make_pair(x, y);

    }

    if(cords[2].second < cords[4].second) swap(cords[2], cords[4]);

    cords[1] = std :: make_pair(cords[2].first, cords[4].second);
    cords[3] = std :: make_pair(cords[4].first, cords[2].second);
    cords[5] = cords[1];

    if(cords[2].first < cords[4].first)
    {
        swap(cords[1], cords[2]);
        swap(cords[3], cords[4]);
    }
    else
    {
        swap(cords[1], cords[3]);
        swap(cords[2], cords[4]);
    }

    if((cords[0].first >= cords[2].first && cords[0].first <= cords[3].first) && (cords[0].first >= cords[1].first && cords[0].first <= cords[4].first) && (cords[0].second <= cords[1].second && cords[0].second >= cords[2].second) && (cords[0].second <= cords[4].second && cords[0].second >= cords[3].second)){

        std :: cout << 0 << '\n';
        return 0;

    }

    for(int i = 1; i < 5; i++){

        int first, second;
        first = abs(cords[0].first - cords[i].first);
        second = abs(cords[0].second - cords[i].second);
        if(first + second < min) {

                min = first + second;
                closest = i;

        }

    }


    if(closest == 1){

        closest = 5;

        if(cords[0].first >= cords[closest].first && cords[0].first <= cords[closest - 1].first) cords[closest] = std :: make_pair(cords[0].first, cords[closest].second);

        else if(cords[0].second <= cords[closest].second && cords[0].second >= cords[closest + 1].second) cords[closest] = std :: make_pair(cords[closest].first, cords[0].second);

    }

    if(closest == 2){

        if(cords[0].first >= cords[closest].first && cords[0].first <= cords[closest + 1].first) cords[closest] = std :: make_pair(cords[0].first, cords[closest].second);

        else if(cords[0].second >= cords[closest].second && cords[0].second <= cords[closest - 1].second) cords[closest] = std :: make_pair(cords[closest].first, cords[0].second);

    }

    if(closest == 3){

        if(cords[0].first <= cords[closest].first && cords[0].first >= cords[closest - 1].first) cords[closest] = std :: make_pair(cords[0].first, cords[closest].second);

        else if(cords[0].second >= cords[closest].second && cords[0].second <= cords[closest + 1].second) cords[closest] = std :: make_pair(cords[closest].first, cords[0].second);

    }

    if(closest == 4){

        if(cords[0].first <= cords[closest].first && cords[0].first >= cords[closest + 1].first) cords[closest] = std :: make_pair(cords[0].first, cords[closest].second);

        else if(cords[0].second <= cords[closest].second && cords[0].second >= cords[closest - 1].second) cords[closest] = std :: make_pair(cords[closest].first, cords[0].second);

    }

    std :: cout << ceil(sqrt(pow(cords[0].first - cords[closest].first, 2) + pow(cords[0].second - cords[closest].second, 2))) << '\n';

}
