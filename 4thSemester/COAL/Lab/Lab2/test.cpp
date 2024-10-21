#include <iostream>
#include <conio.h>

int main()
{

    for(int i = 0 ; i < 256 ; i++){
        std::cout << i << " : " << (char)i << std::endl;
    }
    // for (int i = 0; i <= 253; i = i + 3)
    // {
    //     std::cout << i << " : " << (char)i;
    //     std::cout << "\t" << i+1 << " : " << (char)(i+1);
    //     std::cout << "\t" << i+2 << " : " << (char)(i+2) << std::endl;
    // }
    // while(true){
    //     int c = getche();
    //     std::cout << " : " << c ;
    // }
    return 0;
}