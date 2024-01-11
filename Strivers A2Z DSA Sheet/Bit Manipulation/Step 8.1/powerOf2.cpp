// link->https://www.codingninjas.com/studio/problems/power-of-two_893061

bool isPowerOfTwo(int n)
{
    if (n & (n - 1))
        return false;
    else
        return true;
}