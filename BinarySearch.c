int BinarySearch(const ElemType A[], ElemType X, int N)
{
    int Low = 0, High = N - 1, Mid;
    while (Low <= High)
    {
        Mid = (Low + High) / 2;
        if (A[Mid] < X)
            Low = Mid + 1;
        else if (A[Mid] > X)
            High = Mid - 1;
        else
            return Mid; // Found
    }
    return -1; // Not Found
}