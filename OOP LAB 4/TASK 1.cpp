// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>
using namespace std;
class reverse
{
    public:
    int get_str(char arr[])
    {
        int i = 0;
        char ch;
        while(i<100)
        {
            ch = getchar();
            arr[i] = ch;
            i++;
            
            if(ch == '\n')break;
        }
        arr[i]  = '\0'; 
        return strlen(arr);
    }
    void disp_thearr(char arr[],int length)
    {
        for(int i = 0  ; i < length/2 ; i++)
        {
            char temp = arr[i];
            arr[i] = arr[length-i-1];
            arr[length-i-1] = temp;
        }
        cout << endl;
    }
};
int main()
{
    reverse r1;
    char arr[100];
    int length = r1.get_str(arr);
    r1.disp_thearr(arr,length);
    for(int i = 0  ; i < length ; i++)
    {
        cout << arr[i];
    }
    
}
