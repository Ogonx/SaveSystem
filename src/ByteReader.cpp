#include "ByteReader.h"
#include <cstring>

bool ByteReader::ReadU32(uint32_t& out) {

	if (m_data.size() - m_pos < 4) {
		return false;
	}

	uint32_t b0 = m_data[m_pos];
	uint32_t b1 = m_data[m_pos + 1];
	uint32_t b2 = m_data[m_pos + 2];
	uint32_t b3 = m_data[m_pos + 3];

	out = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
	m_pos += 4;
	return true;
}

bool ByteReader::ReadFloat(float& out) {

	uint32_t bits = 0;

	if (!ReadU32(bits)) {
		return false;
	}

	std::memcpy(&out, &bits, sizeof(bits));
	return true;
}

bool ByteReader::ReadString(std::string& out) {

	uint32_t length = 0;

	if (!ReadU32(length)) {
		return false;
	}

	if (length > m_data.size() - m_pos) {
		return false;
	}

	if (length == 0) {
		out.clear();
		return true;
	}

	out.assign(reinterpret_cast<const char*> (&m_data[m_pos]), length);
	m_pos += length;
	return true; 
}