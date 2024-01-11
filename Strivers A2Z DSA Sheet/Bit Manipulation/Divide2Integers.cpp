// link->https://www.codingninjas.com/studio/problems/-divide-two-integers_1112617

int divideTwoInteger(int dividend, int divisor)
{
    int sign = 1;
    int divi = abs(dividend);
    int divis = abs(divisor);
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        sign = -1;
    int count = 0;
    while (divi >= divis)
    {
        divi -= divis;
        count++;
    }
    return count * sign;
}
