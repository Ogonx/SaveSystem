#include <iostream>
#include "ByteWriter.h"


int main()
{
    ByteWriter writer;
    writer.WriteU32(258);
    writer.WriteFloat(1.0f);
    writer.WriteString("ogonx");
    std::cout << "SaveSystem running\n";

    for (uint8_t b : writer.Data()) {
        std::cout << static_cast<int>(b) << " ";
    }
     
    std::cout << "\n";

    return 0;
}