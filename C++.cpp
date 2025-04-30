#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    int arr[9];
    int temp = 0;
    int sum=0;
    // 9개 입력받아 배열에 저장
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }


    

    // 거짓말쟁이 선별 과정
    int faker1 = 0, faker2 = 0;
    bool found = false;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - (arr[i] + arr[j]) == 100)
            {
                faker1 = arr[i];
                faker2 = arr[j];
                found = true;
                break;
            }
        }
        if (found) break;
    }


    //거짓말쟁이 빼고 넣기
    int sevenMinions[7];
    int sevenindex = 0;
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] != faker1 && arr[i] != faker2)
        {
            sevenMinions[sevenindex] = arr[i];
            sevenindex++;
        }
    }

    
    // 선택정렬 과정
    for (int i = 0; i < 7; i++)
    {
        int minindex = i;
        for (int j = i; j < 7; j++)
        {
            if (sevenMinions[minindex] > sevenMinions[j])
            {
                temp = sevenMinions[minindex];
                sevenMinions[minindex] = sevenMinions[j];
                sevenMinions[j] = temp;
            }
        }
    }
    

    for (int i = 0; i < 7; i++)
    {
        cout << sevenMinions[i] << '\n';
    }

}

