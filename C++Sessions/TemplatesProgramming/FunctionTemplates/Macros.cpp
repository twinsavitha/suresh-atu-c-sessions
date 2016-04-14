#include <iostream>                             
                                                
#define SQUARE(X) ((X) * (X))                   
                                                
int                                             
main(int argc, char *argv[])                    
{                                               
    int x = 6;                                  
    std::cout << "Square of x is " << SQUARE(++x) << std::endl;                                                                                                
} 
