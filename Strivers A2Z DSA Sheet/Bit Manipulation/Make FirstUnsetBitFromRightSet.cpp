// link->https://www.codingninjas.com/studio/problems/set-the-rightmost-unset-bit_8160456

// solution derived after seeing the solution on coding ninjas since i initially TLE'd
int setBits(int N)
{
    if ((N & (N + 1)) == 0)
        return N;
    return (N | N + 1);
}
