#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

class ByteReader
{
public:
    explicit ByteReader(const std::vector<uint8_t>& data) : m_data(data) {}
    bool ReadU32(uint32_t& out);
    bool ReadFloat(float& out);
    bool ReadString(std::string& out);

private:
    std::vector<uint8_t> m_data;
    size_t m_pos = 0;
};