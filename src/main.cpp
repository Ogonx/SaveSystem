#include <iostream>
#include <vector>
#include "ByteWriter.h"
#include "ByteReader.h"

int main()
{
    ByteWriter writer;
    writer.WriteU32(258);
    writer.WriteFloat(1.0f);
    writer.WriteString("ogonx");

    for (uint8_t b : writer.Data()) {
        std::cout << static_cast<int>(b) << " ";
    }
    std::cout << "\n";

    ByteReader reader(writer.Data());
    uint32_t result = 0;
    bool ok = reader.ReadU32(result);
    std::cout << "ok: " << ok << " result: " << result << "\n";

    std::vector<uint8_t> shortData = { 1, 2 };
    ByteReader shortReader(shortData);
    uint32_t dummy = 0;
    bool shortOk = shortReader.ReadU32(dummy);
    std::cout << "short ok: " << shortOk << "\n";

    return 0;
}