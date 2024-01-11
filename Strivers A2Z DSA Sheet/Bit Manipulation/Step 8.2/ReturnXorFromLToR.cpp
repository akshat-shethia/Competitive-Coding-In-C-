// link->https://www.codingninjas.com/studio/problems/l-to-r-xor_8160412

int findXOR(int L, int R){
    int ans = 0;
    for(int i =L;i<=R;i++){
        ans^=i;
    }
    return ans;
}