// O(N^3)
int MaxSubsequenceSum1(const int A[], int N)
{
    int ThisSum, MaxSum = 0;

    for (int i = 0; i < N; ++i)
        for (int j = i; j < N; ++j)
        {
            ThisSum = 0;
            for (int k = 0; k <= j; ++k)
                ThisSum += A[k];
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }

    return MaxSum;
}

// O(N^2)
int MaxSubsequenceSum2(const int A[], int N)
{
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; ++i)
    {
        ThisSum = 0;
        for (int j = i; j < N; ++j)
        {
            ThisSum += A[j];
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
}

static int Max3(int N1, int N2, int N3)
{
    int Max = N1;
    if (N2 > Max)
        Max = N2;
    if (N3 > Max)
        Max = N3;
    return Max;
}

static int MaxSubSum(const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    if (Left == Right) // Base case
        if (A[Left] > 0)
            return A[Left];
        else
            return 0;

    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center + 1, Right);

    MaxLeftBorderSum = LeftBorderSum = 0;
    for (i = Center; i >= Left; --i)
    {
        LeftBorderSum += A[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = RightBorderSum = 0;
    for (i = Center + 1; i <= Right; ++i)
    {
        RightBorderSum += A[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

// O(NlgN)
int MaxSubsequenceSum3(const int A[], int N)
{
    return MaxSubSum(A, 0, N - 1);
}

// O(N)
int MaxSubsequenceSum4(const int A[], int N)
{
    int ThisSum = 0, MaxSum = 0;
    for (int i = 0; i < N; ++i)
    {
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}