#include "ByteReader.h"

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