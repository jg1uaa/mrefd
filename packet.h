//
//  Copyright © 2020-2025 Thomas A. Early, N7TAE
//
// ----------------------------------------------------------------------------
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    with this software.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#pragma once

#include <cstdint>
#include <string.h>
#include <memory>

#include "callsign.h"

#define MAX_PACKET_SIZE 859

class CPacket
{
public:
	CPacket();
	void Initialize(size_t s, bool iss);
	const uint8_t *GetCDstAddress() const;
	const uint8_t *GetCSrcAddress() const;
	uint8_t *GetDstAddress();
	uint8_t *GetSrcAddress();
	uint16_t GetStreamId() const;
	void SetStreamId(uint16_t sid);
	uint16_t GetFrameType() const;
	void SetFrameType(uint16_t ft);
	void SetRelay();
	void ClearRelay();
	bool IsRelaySet() const;
	uint16_t GetFrameNumber() const;
	void SetFrameNumber(uint16_t fn);
	bool IsStreamPacket() const { return isstream; }
	bool IsLastPacket() const;
	void CalcCRC();
	uint8_t *GetData() { return data; }
	const uint8_t *GetCData() const { return data; }
	size_t GetSize() const { return size; }
	uint8_t *GetVoice();
	const uint8_t *GetCVoice() const;
	uint16_t GetCRC(bool first = true) const;

private:
	uint16_t Get16At(size_t pos) const;
	
	bool isstream;
	size_t size;
	uint8_t data[MAX_PACKET_SIZE+1];
};
