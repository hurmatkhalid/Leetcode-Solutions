class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(!n)  return true;
        int i =0;
        while(i<flowerbed.size()){
            if(flowerbed[i]==0 && (i ==0 || flowerbed[i-1]==0) && (i == flowerbed.size()-1 || flowerbed[i+1]==0)){
                n--;
                flowerbed[i]=1;
                if(!n)  return true;
            }
            i++;
        }
        return false;
    }
};