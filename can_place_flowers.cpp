class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int placed = 0;
        flowerbed.push_back(0);
        for(int i = 0; i < flowerbed.size() - 1; i ++){
            placed += ((i == 0 || (flowerbed[i - 1]) == 0) && flowerbed[i + 1] == 0 && flowerbed[i] == 0) ? flowerbed[i] = 1 : 0;
            
        }
        return placed >= n;

        /*
        // OLD SOLUTION, ABOVE IS cleaner
        if(flowerbed.size() == 1){
            if(flowerbed[0] == 0) return true;
            if(n == 1) return false;
            return true;
        }

        // plant in first slot if possible
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            n--;
        }

        for(int i = 1; i < flowerbed.size() - 1; i++){
            //cout << "checking at: " << i << endl;
            if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                //cout << "planting at: " << i << endl;
                flowerbed[i] = 1;
                n--;
            }
        }
        // plant in last slot if possible
        if(flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 1] == 0){
            flowerbed[flowerbed.size() - 1] = 1;
            n--;
        }

        if(n <= 0) return true;
        return false;
        */
    }
};
